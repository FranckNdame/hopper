//
//  hopper.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include "hopper.hpp"
#include <vformat>

//MARK:- TOKENS

// Constants for token types
const std::string TOKEN_INT = "TOKEN_INT";
const std::string TOKEN_FLOAT = "TOKEN_FLOAT";
const std::string TOKEN_PLUS = "TOKEN_PLUS";
const std::string TOKEN_MINUS = "TOKEN_MINUS";
const std::string TOKEN_MUL = "TOKEN_MUL";
const std::string TOKEN_DIV = "TOKEN_DIV";
const std::string TOKEN_LEFT_PARANTHESIS = "TOKEN_LEFT_PARANTHESIS";
const std::string TOKEN_RIGHT_PARANTHESIS = "TOKEN_RIGHT_PARANTHESIS";

class Token {
public:
    std::string m_type;
    std::string m_value;
public:
    Token(std::string type, std::string value) {
        m_type = type;
        m_value = value;
    }
    
    std::string ToString() {
        if (!m_value.empty()) return m_type + ":" + m_value;
        return m_type;
    }
};
