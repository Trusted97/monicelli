#ifndef SCANNER_HPP
#define SCANNER_HPP

/*
 * Monicelli: as esoteric language compiler
 * 
 * Copyright (C) 2014 Stefano Sanfilippo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include "Parser.hpp"

namespace monicelli {

class Scanner: public yyFlexLexer {
public:
    Scanner(std::istream &in): yyFlexLexer(&in) {}

    int yylex(Parser::semantic_type *lval, Parser::location_type *loc) {
        this->lval = lval;
        location = loc;
        return yylex();
    }

private:
    int yylex();
    Parser::semantic_type *lval;
    Parser::location_type *location;
};

} // monicelli

#endif