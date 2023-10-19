#include "Lexer.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

#include "Constant.hpp"

using namespace mirror;
using namespace mirror::token;

using namespace std;

Lexer::Lexer(std::string &str) : m_input(str.begin(), str.end()) {
    read_char();
}

Lexer::~Lexer() {
}

void Lexer::read_char() {
    if (m_readPosition >= m_input.size()) {
        m_ch = 0;
    } else {
        m_ch = m_input[m_readPosition];
    }

    m_position = m_readPosition++;
}

void Lexer::skip_whitespace() {
    while (m_ch == ' ' || m_ch == '\t' || m_ch == '\n' || m_ch == '\r')
        read_char();
}

unique_ptr<Token> Lexer::next_token() {
    unique_ptr<Token> tok;
    skip_whitespace();

    switch (m_ch) {
    case '=':
        if (peed_char() == '=') {
            tok = make_unique<Token>(TOKEN_TYPE::EQ, capture_char(2));
        } else {
            tok = make_unique<Token>(TOKEN_TYPE::ASSIGN, string(1, m_ch));
        }
        break;
    case '+':
        tok = make_unique<Token>(TOKEN_TYPE::PLUS, string(1, m_ch));
        break;
    case '-':
        tok = make_unique<Token>(TOKEN_TYPE::MINUS, string(1, m_ch));
        break;
    case '!':
        if (peed_char() == '=') {
            tok = make_unique<Token>(TOKEN_TYPE::NOT_EQ, capture_char(2));
        } else {
            tok = make_unique<Token>(TOKEN_TYPE::BANG, string(1, m_ch));
        }
        break;
    case '/':
        if (peed_char() == '/') {
            read_annotation();
            tok = next_token();
        } else {
            tok = make_unique<Token>(TOKEN_TYPE::SLASH, string(1, m_ch));
        }
        break;
    case '*':
        tok = make_unique<Token>(TOKEN_TYPE::ASTERISK, string(1, m_ch));
        break;
    case '%':
        tok = make_unique<Token>(TOKEN_TYPE::REM, string(1, m_ch));
        break;
    case '<':
        if (peed_char() == '=') {
            tok = make_unique<Token>(TOKEN_TYPE::LT_EQ, capture_char(2));
        }
        else {
            tok = make_unique<Token>(TOKEN_TYPE::LT, string(1, m_ch));
        }
        break;
    case '>':
        if (peed_char() == '=') {
            tok = make_unique<Token>(TOKEN_TYPE::GT_EQ, capture_char(2));
        }
        else {
            tok = make_unique<Token>(TOKEN_TYPE::GT, string(1, m_ch));
        }
        break;
    case '&':
        if (peed_char() == '&') {
            tok = make_unique<Token>(TOKEN_TYPE::AND, capture_char(2));
        } else {
            tok = make_unique<Token>(TOKEN_TYPE::BIT_AND, string(1, m_ch));
        }
        break;
    case '|':
        if (peed_char() == '|') {
            tok = make_unique<Token>(TOKEN_TYPE::OR, capture_char(2));
        }
        else {
            tok = make_unique<Token>(TOKEN_TYPE::BIT_OR, string(1, m_ch));
        }
        break;
    case '^':
        tok = make_unique<Token>(TOKEN_TYPE::XOR, string(1, m_ch));
        break;
    case ';':
        tok = make_unique<Token>(TOKEN_TYPE::SEMICOLON, string(1, m_ch));
        break;
    case ':':
        tok = make_unique<Token>(TOKEN_TYPE::COLON, string(1, m_ch));
        break;
    case ',':
        tok = make_unique<Token>(TOKEN_TYPE::COMMA, string(1, m_ch));
        break;
    case '{':
        tok = make_unique<Token>(TOKEN_TYPE::LBRACE, string(1, m_ch));
        break;
    case '}':
        tok = make_unique<Token>(TOKEN_TYPE::RBRACE, string(1, m_ch));
        break;
    case '(':
        tok = make_unique<Token>(TOKEN_TYPE::LPAREN, string(1, m_ch));
        break;
    case ')':
        tok = make_unique<Token>(TOKEN_TYPE::RPAREN, string(1, m_ch));
        break;
    case '[':
        tok = make_unique<Token>(TOKEN_TYPE::LBRACKET, string(1, m_ch));
        break;
    case ']':
        tok = make_unique<Token>(TOKEN_TYPE::RBRACKET, string(1, m_ch));
        break;
    case '"':
        tok = make_unique<Token>(TOKEN_TYPE::STRING, read_string());
        break;
    case 0:
        tok = make_unique<Token>(TOKEN_TYPE::EOF_, string(""));
        break;
    default:
        if (is_letter(m_ch)) {
            string literal = read_identifier();
            tok = make_unique<Token>(Token::lookup_ident(literal), literal);
            return tok;
        } else if (is_digit(m_ch)) {
            string literal = read_number();
            tok = make_unique<Token>(TOKEN_TYPE::INT, literal);
            return tok;
        } else {
            tok = make_unique<Token>(TOKEN_TYPE::ILLEGAL, string(1, m_ch));
        }

        break;
    }

    read_char();
    return tok;
}

char Lexer::peed_char() {
    if (m_readPosition >= m_input.size()) {
        return 0;
    } else {
        return m_input[m_readPosition];
    }
}

string Lexer::capture_char(int number) {

    string literal(1, m_ch);

    while (--number > 0) {
        read_char();
        literal += m_ch;
    }

    return literal;
}

bool Lexer::is_letter(char ch) {
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_';
}

bool Lexer::is_digit(char ch) { return '0' <= ch && ch <= '9'; }

string Lexer::read_identifier() {
    vector<char> v;

    while (is_letter(m_ch) || is_digit(m_ch)) {
        v.push_back(m_ch);
        read_char();
    }
    return string(v.begin(), v.end());
}

string Lexer::read_number() {
    vector<char> v;

    while (is_digit(m_ch)) {
        v.push_back(m_ch);
        read_char();
    }

    return string(v.begin(), v.end());
}

string Lexer::read_string() {
    // a different implementation , not like read_number, ugly;
    std::string str;

    for (int i = 0; i < 20; i++) {
        read_char();
        switch (m_ch)
        {
        case '"':
        case 0:
            return str;

        case '\\':
            switch (peed_char())
            {
            case 'a':
                read_char(); str += '\a'; break;

            case 'b':
                read_char(); str += '\b'; break;

            case 'f':
                read_char(); str += '\f'; break;

            case 'n':
                read_char(); str += '\n'; break;

            case 'r':
                read_char(); str += '\r'; break;

            case 't':
                read_char(); str += '\t'; break;

            case 'v':
                read_char(); str += '\v'; break;

            case '\\':
                read_char(); str += '\\'; break;

            case '\'':
                read_char(); str += '\''; break;

            case '\"':
                read_char(); str += '\"'; break;

            default:
                str += m_ch; break;
            }
            break;

        default:
            str += m_ch; break;
        }

    }

    return str;
}

void Lexer::read_annotation() {
    read_char();
    read_char();

    while (m_ch != '\n') {
        read_char();
    }
}