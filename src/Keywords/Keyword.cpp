/*
 * Keyword.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "Keyword.h"

namespace Keys
{

Keyword::Keyword() : m_completeKeyword("")
{
}

Keyword::~Keyword()
{
}

void Keyword::insertFromListWithSeparator(const std::vector<std::string>& whichList, const std::string& separator)
{
    for(std::vector<std::string>::const_iterator it = whichList.begin() ; it != whichList.end(); ++it)
    {
        m_completeKeyword.append(*it);
        if (*it != whichList.at(whichList.size() - 1))
        {
            m_completeKeyword.append(separator);
        }

    }
}

void Keyword::insertFromListWithOperatorList(const std::vector<std::string>& whichList, const std::vector<std::string>& operatorList)
{

    for(std::vector<std::string>::const_iterator it = whichList.begin(), it2 = operatorList.begin(); it != whichList.end(); ++it, ++it2)
    {
        m_completeKeyword.append(*it);
        if (*it != whichList.at(whichList.size() - 1))
        {
            m_completeKeyword.append(" " + *it2 +" ");
        }

    }
}

std::string Keyword::returnTypeOfDropOrCreate(DropType typeOfDropOrCreate)
{
    std::string toReturn;

    switch(typeOfDropOrCreate)
    {
        case NoneType_DropType :
        {
            toReturn = "";
            break;
        }
        case Index_DropType :
        {
            toReturn = IndexClause;
            break;
        }
        case Table_DropType :
        {
            toReturn = TableClause;
            break;
        }
        case Trigger_DropType :
        {
            toReturn = TriggerClause;
            break;
        }
        case View_DropType :
        {
            toReturn = ViewClause;
            break;
        }
    }

    return toReturn;
}

void Keyword::addReturnLine()
{
    m_completeKeyword.append("\n");
}

std::string& Keyword::getCompleteKeyword()
{
    return m_completeKeyword;
}

}
