#ifndef ASSIGNEXPRESSION_HPP
#define ASSIGNEXPRESSION_HPP

#include "Expression.hpp"
#include "Identifier.hpp"
#include "Statement.hpp"
#include "Token.hpp"
#include <memory>

using namespace std;

namespace mirror {
    class AssignExpression : public Expression {
    public:
        unique_ptr<Token> m_token; // the token.ASSIGN token
        unique_ptr<Identifier> m_name;
        unique_ptr<Expression> m_value;

    public:
        AssignExpression() = default;
        AssignExpression(Token& token, unique_ptr<Identifier> name,
            unique_ptr<Expression> value)
            : m_token(make_unique<Token>(token)), m_name(std::move(name)),
            m_value(std::move(value)) {};
        AssignExpression(Token& token) : m_token(make_unique<Token>(token)) {};
        ~AssignExpression() {};

    public:
        string token_literal() { return m_token->m_literal; };
        string to_string() {
            string ret = m_name->to_string() + " = " +  m_value->to_string() + ";";
            return ret;
        };
    };
}
#endif /* ASSIGNEXPRESSION_HPP */
