/*
 * CreateIndex.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#include "CreateIndex.h"

namespace Keys
{

CreateIndex::CreateIndex(const std::string& nameOfIndex, const std::string& table, const bool& unique, const bool& ifNotExists, std::vector<std::string>& fieldsList)
: nameOfIndex(nameOfIndex), table(table), unique(unique), ifNotExists(ifNotExists), fieldsList(fieldsList)
{
    processKeyword();
}

CreateIndex::~CreateIndex()
{
}

void CreateIndex::processKeyword()
{
    m_completeKeyword = CreateClause + " " + (unique? UniqueClause + " " : "") + IndexClause + " " + (ifNotExists? IfNotExistsClause + " " : "") + nameOfIndex + " " + OnClause + " " + table;
    m_completeKeyword.append(" (");
    insertFromListWithSeparator(fieldsList, ", ");
    m_completeKeyword.append(")");
}

}


