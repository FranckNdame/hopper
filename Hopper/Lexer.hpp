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
#include "Position.hpp"

//MARK:- LEXER
class Lexer {
public:
    std::string m_text;
    Position m_pos;
    std::string m_currChar;
    Error* m_error = nullptr;
    std::string m_filename;
    
public:
    Lexer(std::string text, std::string filename);
    ~Lexer();
    void Move();
    std::vector<Token> GenerateTokens();
    Error* getError();
    
private:
    Token GenerateNumber();
    void setError(std::string chr, Position posStart);
    
};



#endif /* Lexer_hpp */
