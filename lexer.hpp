//
// Created by shobhit on 25/3/24.
//

#ifndef EVAL_LEXER_HPP
#define EVAL_LEXER_HPP

#include <string>
#include <list>

enum TYPE {
    NUM,
    ADD,
    SUB,
    MUL,
    DIV,
    OPEN_PAREN,
    CLOSE_PAREN
};

struct node {
    TYPE token;
    std::string val;
};

class lexer {
    bool isDigit(char c);
public:
    std::list <node> tokenTable;
    std::string typeInStr(int i);
    void tokenize(std::string input);
    void printTokenTable();
};


#endif //EVAL_LEXER_HPP
