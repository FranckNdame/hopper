//
//  main.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include <iostream>


int main(int argc, const char * argv[]) {
    while (true) {
        std::cout << "hopper > ";
        std::string text;
        getline(std::cin, text);
        std::cout << text << std::endl;
    }
    return 0;
}
