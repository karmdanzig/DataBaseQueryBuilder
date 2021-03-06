/*
 * Values.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_VALUES_H_
#define SRC_KEYWORDS_VALUES_H_

#include "Keyword.h"

namespace Keys
{

class Values : public Keyword
{
private:

    std::vector<std::string> valuesList;

public:

    Values(const std::vector<std::string>& valuesList);
    ~Values();
    void processKeyword();
};

}

#endif /* SRC_KEYWORDS_VALUES_H_ */
