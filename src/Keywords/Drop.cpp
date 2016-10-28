/*
 * Drop.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Drop.h"

namespace Keys
{

Drop::Drop(const std::string& table, const bool& ifExists)
: table(table), ifExists(ifExists)
{
    processKeyword();
}

Drop::~Drop()
{
}

void Drop::processKeyword()
{
    m_completeKeyword = DropClause + " " + Table + " " + (ifExists? IfExistsClause + " " : "") + table;
}

}