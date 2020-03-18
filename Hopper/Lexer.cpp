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

Lexer::Lexer(std::string text, std::string filename) : m_pos(-1, 0, -1, filename, text) { // https://stackoverflow.com/questions/31488756/explicitly-initialize-member-which-does-not-have-a-default-constructor
    // text to be parsed by lexer
    m_text = text;
    m_currChar = "";
    m_filename = filename;
    Move();
}

Lexer::~Lexer() {}

void Lexer::Move() {
    // Move to next char in text
    m_pos.Advance(m_currChar);
    if (m_pos.m_index < m_text.length()) {
        m_currChar = m_text[m_pos.m_index];
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
            m_pos.m_index--;
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
            Position posStart = m_pos.Copy();
            setError(m_currChar, posStart);
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

void Lexer::setError(std::string chr, Position posStart) {
    std::string details = "'" + chr + "' was not defined.";
    m_error = new Error("Illegal character", posStart, m_pos, details);
}

