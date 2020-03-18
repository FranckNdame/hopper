//
//  Error.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include "Error.hpp"

//MARK:- ERROR
Error::Error(std::string name, Position posStart, Position posEnd, std::string details) {
    m_name = name;
    m_details = details;
    m_posStart = posStart;
    m_posEnd = posEnd;
}

Error::~Error() {}

std::string Error::ToString() {
    std::string str =  m_name + ": " + m_details;
    str += "\nFileName: " + m_posStart.m_filename + ", line " + std::to_string(m_posStart.m_lineNumber + 1);
    return str;
}




