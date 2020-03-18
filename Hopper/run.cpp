//
//  run.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include "run.hpp"

//MARK:- RUN
std::vector<Token> run(std::string text) {
    Lexer lexer(text);
    std::vector<Token> tokens = lexer.GenerateTokens();
    std::cout << "Token length: " << tokens.size() << std::endl;
    std::cout << "==============" << std::endl;
    Error* error = lexer.getError();
    if (error == nullptr) return tokens;
    std::cout << error->ToString() << std::endl;
    return {};

}
