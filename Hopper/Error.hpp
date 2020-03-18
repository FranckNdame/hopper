//
//  Error.hpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#ifndef Error_hpp
#define Error_hpp

#include <stdio.h>
#include <iostream>
#include "Position.hpp"

//MARK:- ERROR
class Error
{
public:
    std::string m_name;
    std::string m_details;
    Position m_posStart;
    Position m_posEnd;
public:
    Error(std::string name, Position posStart, Position posEnd, std::string details = "");
    ~Error();
    std::string ToString();
    
};



#endif /* Error_hpp */
