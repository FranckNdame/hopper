//
//  Token.hpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp

#include <stdio.h>
#include <iostream>

//MARK:- TOKENS
class Token {
public:
    std::string m_type;
    std::string m_value;
public:
    Token(std::string type, std::string value = "");
    ~Token();
    std::string ToString();
};

#endif /* Token_hpp */
