//
//  Lexer.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include "Lexer.hpp"

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

//MARK:- LEXER

Lexer::Lexer(std::string text) {
    // text to be parsed by lexer
    m_text = text;
    // current text position
    m_pos = -1;
    m_currChar = "";
    Move();
}

Lexer::~Lexer() {}

void Lexer::Move() {
    // Move to next char in text
    m_pos++;
    if (m_pos < m_text.length()) {
        m_currChar = m_text[m_pos];
    } else {
        m_currChar = "";
    }
}

std::vector<Token> Lexer::GenerateTokens() {
    std::vector<Token> tokens;
    while (m_currChar.size()) {
        if (SPACETAB.find(m_currChar) != std::string::npos) {
            // Ignore spaces and tabs
        } else if (DIGITS.find(m_currChar) != std::string::npos) {
            // Get Number
            tokens.push_back(GenerateNumber());
            m_pos--;
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
            setError(m_currChar);
            Move();
            return {};
        }
        Move();
    }
    
    return tokens;
}

Error* Lexer::getError() {
    return m_error;
}

Token Lexer::GenerateNumber() {
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
        Move();
    }
    
    if (dotCount) {
        return Token(TOKEN_FLOAT, num);
    } else {
        return Token(TOKEN_INT, num);
    }
}

void Lexer::setError(std::string chr) {
    m_error = new Error("Illegal character", chr);
}

