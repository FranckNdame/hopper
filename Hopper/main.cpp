//
//  main.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include "run.hpp"

int main(int argc, const char * argv[]) {
    while (true) {
        std::cout << "hopper > ";
        std::string text;
        getline(std::cin, text);
        std::vector<Token> tokens = run(text);
        std::cout << tokens.size() << std::endl;
        for(int i=0; i<tokens.size();i++) {
            std::cout << tokens[i].ToString() << std::endl;
            std::cout << i << "<- index" << std::endl;
        }
 
    }
    return 0;
}
