#include <iostream>
#include <string>

#include "lexer.hpp"

int main() {
    std::string input;
    getline(std::cin, input);
    std::cout << input << std::endl;

    lexer lex;
    lex.tokenize(input);
    lex.printTokenTable();

    return 0;
}
