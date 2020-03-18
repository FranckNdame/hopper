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

//MARK:- ERROR
class Error
{
public:
    std::string m_name;
    std::string m_details;
public:
    Error(std::string name, std::string details = "");
    ~Error();
    std::string ToString();
    
};

class IllegalCharacterError: public Error
{
public:
    IllegalCharacterError(std::string details);
};



#endif /* Error_hpp */
