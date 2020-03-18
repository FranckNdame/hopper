//
//  Error.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include "Error.hpp"

//MARK:- ERROR
Error::Error(std::string name, std::string details) {
    m_name = name;
    m_details = details;
}

Error::~Error() {}

std::string Error::ToString() {
    return "[" + m_name + "]: " + m_details;
}


IllegalCharacterError::IllegalCharacterError(std::string details)
: Error("[Illegal Character Error] '" + details + "'")
{
    // do something
}



