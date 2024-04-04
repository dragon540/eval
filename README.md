## Goal: 

Demonstrate parsing of a string of mathematical expression

Suppose a mathematical expression like ```5-3+7*8/12``` is given, generate a parse tree like below :

                                    +
                                  /   \
                                 -     /
                                / \   /  \
                               5   3  *   12
                                     / \
                                    7   8

## Things to be taken care of:
1) Ambiguity
2) Left recursion

## Grammar a

E -> E + T | E - T | T

T -> T * F | T / F | F

F -> N | (E)

### Problem :

The above grammar cannot be parsed by an Left derivation parser since left recursion present in the grammar, due
to which during parsing, it goes into an infinite loop.

To remove left recursion, E and T can be switched.

## Grammar b

E -> T + E | T - E | T

T -> F * T | F / T | F

F -> N | (E)

### Problem :

The above grammar cannot handle the order of precedence, for example ```5-3+2``` is parsed as ```(5-(3+2))``` which is 
incorrect.

Introduce auxiliary symbols to handle associativity.

## Grammar c (final grammar)

E -> TE'
E' -> +TE' | -TE' | \n
T -> FT'
T' -> *FT' | /FT' | \n
F -> N + (E)