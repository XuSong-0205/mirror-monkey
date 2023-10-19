#ifndef TOKEN_CONSTANT_HPP
#define TOKEN_CONSTANT_HPP

#include <string>
using namespace std;

namespace mirror {

namespace token {
enum class TOKEN_TYPE {
    ILLEGAL,    // "ILLEGAL"
    EOF_,       // "EOF"

    // Identifiers + literals
    IDENT,      // "IDENT"  // add, foobar, x, y, ...
    INT,        // "INT"    // 1343456
    FLOAT,      // "FLOAT"  // 3.1415926
    STRING,     // "foobar"

    // Operators
    ASSIGN,     // "="
    PLUS,       // "+"
    MINUS,      // "-"
    BANG,       // "!"
    ASTERISK,   // "*"
    SLASH,      // "/"
    REM,        // "%"

    LT,         // "<"
    GT,         // ">"
    LT_EQ,      // "<="
    GT_EQ,      // ">="

    EQ,         // "=="
    NOT_EQ,     // "!="

    BIT_AND,    // "&"
    BIT_OR,     // "|"
    XOR,        // "^"

    AND,        // "&&"
    OR,         // "||"

    // Delimiters
    COMMA,      // ","
    SEMICOLON,  // ";"
    COLON,      // ":"

    LPAREN,     // "("
    RPAREN,     // ")"
    LBRACE,     // "{"
    RBRACE,     // "}"
    LBRACKET,   // "["
    RBRACKET,   // "]"

    // Keywords
    FUNCTION,   // "FUNCTION"
    LET,        // "LET"
    TRUE_,      // "TRUE"
    FALSE_,     // "FALSE"
    IF,         // "IF"
    FOR,        // "FOR"
    ELSE,       // "ELSE"
    RETURN,     // "RETURN"
};

const string TOKEN_TYPE_VALUE[] = {
    "ILLEGAL", "EOF",

    // Identifiers + literals
    "IDENT",    // add, foobar, x, y, ...,
    "INT",      // 1343456,
    "FLOAT",    // 3.1415926
    "STRING",   // "foobar"

    // Operators
    "ASSIGN",   // "="
    "PLUS",     // "+"
    "MINUS",    // "-"
    "BANG",     // "!"
    "ASTERISK", // "*"
    "SLASH",    // "/"
    "REM",      // "%"

    "LT",       // "<"
    "GT",       // ">"
    "LT_EQ",    // "<="
    "GT_EQ",    // ">="

    "EQ",       // "=="
    "NOT_EQ",   // "!="

    "BIT_AND",  // "&"
    "BIT_OR",   // "|"
    "XOR",      // "^"

    "AND",      // "&&"
    "OR",       // "||"

    // Delimiters
    "COMMA",        // ","
    "SEMICOLON",    // ";"
    "COLON",        // ":"
    "LPAREN",       // "("
    "RPAREN",       // ")"
    "LBRACE",       // "{"
    "RBRACE",       // "}"
    "LBRACKET",     // "["
    "RBRACKET",     // "]"

    // Keywords
    "FUNCTION", // "FUNCTION"
    "LET",      // "LET"
    "TRUE_",    // "TRUE"
    "FALSE_",   // "FALSE"
    "IF",       // "IF"
    "FOR",      // "FOR"
    "ELSE",     // "ELSE"
    "RETURN",   // "RETURN"
};

} // namespace token
}
#endif /* TOKEN_CONSTANT_HPP */
