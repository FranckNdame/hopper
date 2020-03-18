//
//  Position.hpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#ifndef Position_hpp
#define Position_hpp

#include <stdio.h>
#include <iostream>

class Position {
public:
    int m_index;
    int m_lineNumber;
    int m_col;
    std::string m_filename;
    std::string m_filetxt;
public:
    Position(int index, int lineNumber, int col, std::string filename, std::string filetxt);
    Position();
    ~Position();
    void Advance(std::string currChar);
    Position Copy();
    
};

#endif /* Position_hpp */
