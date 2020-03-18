//
//  hopper.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include "hopper.hpp"

//MARK:- ERROR
class Error
{
public:
    std::string m_name;
    std::string m_details;
public:
    Error(std::string name, std::string details = "") {
        m_name = name;
        m_details = details;
    }
    
    std::string ToString() {
        return "[" + m_name + "]: " + m_details;
    }
    
};

class IllegalCharacterError: public Error
{
public:
    IllegalCharacterError(std::string details)
    : Error("[Illegal Character Error] '" + details + "'")
    {
        // do something
    }
};

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
const std::string DIGITS = "0123456789";
std::string SPACETAB = " \t";


class Token {
public:
    std::string m_type;
    std::string m_value;
public:
    Token(std::string type, std::string value = "") {
        m_type = type;
        m_value = value;
    }
    
    std::string ToString() {
        if (m_value.size()) return m_type + ":" + m_type;
        return m_type;
    }
};



//MARK:- LEXER
class Lexer {
public:
    std::string m_text;
    signed int m_pos;
    std::string m_currChar;
    
public:
    Lexer(std::string text) {
        // text to be parsed by lexer
        m_text = text;
        // current text position
        m_pos = -1;
        m_currChar = "";
        Move();
    }
    
    void Move() {
        // Move to next char in text
        m_pos++;
        if (m_pos < m_text.length()) {
            m_currChar = m_text[m_pos];
        } else {
            m_currChar = "";
        }
    }
    
    std::vector<Token> GenerateTokens() {
        std::vector<Token> tokens;
        while (!m_currChar.size()) {
            if (SPACETAB.find(m_currChar) != std::string::npos) {
                // Ignore spaces and tabs
                Move();
            } else if (DIGITS.find(m_currChar) != std::string::npos) {
                // Get Number
                GenerateNumber();
            } else if (m_currChar == "+") {
                tokens.push_back(Token(TOKEN_PLUS));
            } else if (m_currChar == "-") {
                tokens.push_back(Token(TOKEN_MINUS));
            } else if (m_currChar == "*") {
                tokens.push_back(Token(TOKEN_MUL));
            } else if (m_currChar == "/") {
                tokens.push_back(Token(TOKEN_DIV));
            } else if (m_currChar == "(") {
                tokens.push_back(Token(TOKEN_LEFT_PARANTHESIS));
            } else if (m_currChar == ")") {
                tokens.push_back(Token(TOKEN_RIGHT_PARANTHESIS));
            } else {
                // Error
                std::string chr = m_currChar;
                Move();
                return {};
            }
        }
        
        return tokens;
    }
    
    Token GenerateNumber() {
        std::string num = "";
        int dotCount = 0;
        
        while (m_currChar.size() && (DIGITS + ".").find(m_currChar) != std::string::npos) {
            if (m_currChar == ".") {
                if (dotCount) break;
                dotCount++;
                num += ".";
            } else {
                num += m_currChar;
            }
        }
        
        if (dotCount) {
            return Token(TOKEN_FLOAT, num);
        } else {
            return Token(TOKEN_INT, num);
        }
    }
    
};
