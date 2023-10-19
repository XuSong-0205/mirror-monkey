#ifndef FLOATLITERAL_HPP
#define FLOATLITERAL_HPP

#include "Expression.hpp"
#include "Token.hpp"
#include <string>

using namespace std;

namespace mirror {
    // Expressions
    class FloatLiteral : public Expression {
    public:
        unique_ptr<Token> m_token; // the token.IDENT token
        double m_value = 0;

        string token_literal() { return m_token->m_literal; };
        string to_string() { return std::to_string(m_value); };

    public:
        FloatLiteral(Token& token) : m_token(new Token(token)) {};
        FloatLiteral(Token& token, double value)
            : m_token(new Token(token)), m_value(value) {};
    };
}
#endif /* FLOATLITERAL_HPP */
