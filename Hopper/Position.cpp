//
//  Position.cpp
//  Hopper
//
//  Created by Franck-Stephane Ndame Mpouli on 18/03/2020.
//  Copyright © 2020 Franck-Stephane Ndame Mpouli. All rights reserved.
//

#include "Position.hpp"


Position::Position(int index, int lineNumber, int col, std::string filename, std::string filetxt) {
    m_index = index;
    m_lineNumber = lineNumber;
    m_col = col;
    m_filename = filename;
    m_filetxt = filetxt;
}

Position::Position() {}
Position::~Position() {}

void Position::Advance(std::string currChar) {
    m_index++;
    m_col++;
    if (currChar == "\n") {
        m_lineNumber += 1;
        m_col = 0;
    }
}

Position Position::Copy() {
    return Position(m_index, m_lineNumber, m_col, m_filename, m_filetxt);
}
