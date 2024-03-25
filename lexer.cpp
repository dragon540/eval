//
// Created by shobhit on 25/3/24.
//

#include "lexer.hpp"
#include <iostream>

bool lexer::isDigit(char c) {
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            return false;
    }
}

std::string lexer::typeInStr(int i) {
    std::string type;
    switch (i) {
        case 0:
            type = "NUM";
            break;
        case 1:
            type = "ADD";
            break;
        case 2:
            type = "SUB";
            break;
        case 3:
            type = "MUL";
            break;
        case 4:
            type = "DIV";
            break;
        case 5:
            type = "OPEN_PAREN";
            break;
        case 6:
            type = "CLOSE_PAREN";
            break;
    }
    return type;
}


void lexer::tokenize(std::string input) {
    for(int i=0;i<input.length();i++) {
        std::string temp = "";

        // checking for numerals
        while(isDigit(input[i]) == true) {
            temp += input[i];
            if( (i+1 < input.length()) && (isDigit(input[i+1]) == false) ) {
                tokenTable.push_back({NUM, temp});
                break;
            }
            else if( (i+1 < input.length()) && (isDigit(input[i+1]) == true) ) {
                i++;
            }
            else if(i+1 >= input.length()) {
                tokenTable.push_back({NUM, temp});
                break;
            }
        }

        // checking for operands
        if(input[i] == '+') {
            temp = input[i];
            tokenTable.push_back({ADD, temp});
        }
        else if(input[i] == '-') {
            temp = input[i];
            tokenTable.push_back({SUB, temp});
        }
        else if(input[i] == '*') {
            temp = input[i];
            tokenTable.push_back({MUL, temp});
        }
        else if(input[i] == '/') {
            temp = input[i];
            tokenTable.push_back({DIV, temp});
        }
        else if(input[i] == '(') {
            temp = input[i];
            tokenTable.push_back({OPEN_PAREN, temp});
        }
        else if(input[i] == ')') {
            temp = input[i];
            tokenTable.push_back({CLOSE_PAREN, temp});
        }
    }
}

void lexer::printTokenTable() {
    std::list<node> :: iterator it;
    it = tokenTable.begin();
    while (it != tokenTable.end()) {
        std::cout  << "Token: " << typeInStr(it->token) << " Value: " << it->val << std::endl;
        it++;
    }

}
