//
//  Lexer.hpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#ifndef Lexer_hpp
#define Lexer_hpp
#include <vector>
#include "Error.hpp"
#include "Token.hpp"

//MARK:- LEXER
class Lexer {
public:
    std::string m_text;
    signed int m_pos;
    std::string m_currChar;
    IllegalCharacterError* m_error;
    
public:
    Lexer(std::string text);
    ~Lexer();
    void Move();
    std::vector<Token> GenerateTokens();
    IllegalCharacterError* getError();
    
private:
    Token GenerateNumber();
    void setError(std::string chr);
    
};



#endif /* Lexer_hpp */
