//
//  run.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include "run.hpp"

//MARK:- RUN
std::vector<Token> run(std::string text, std::string filename) {
    Lexer lexer(text, filename);
    std::vector<Token> tokens = lexer.GenerateTokens();

    Error* error = lexer.getError();
    if (error == nullptr) return tokens;
    std::cout << error->ToString() << std::endl;
    return {};

}
