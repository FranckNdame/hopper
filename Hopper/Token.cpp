//
//  Token.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include "Token.hpp"

//MARK:- TOKENS
Token::Token(std::string type, std::string value) {
    m_type = type;
    m_value = value;
}
Token::~Token() {}

std::string Token::ToString() {
    if (m_value.size()) return m_type + ": " + m_value;
    return m_type;
}


