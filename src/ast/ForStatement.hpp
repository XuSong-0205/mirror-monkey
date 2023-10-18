#ifndef FORSTATEMENT_HPP
#define FORSTATEMENT_HPP

#include "BlockStatement.hpp"
#include "Statement.hpp"
#include "Token.hpp"

using namespace std;
namespace mirror {
    class ForStatement : public Statement {
    public:
        unique_ptr<Token> m_token; // The 'for' token
        unique_ptr<LetStatement> m_loop_var;
        unique_ptr<Expression> m_condition;
        unique_ptr<Expression> m_next_step;
        unique_ptr<BlockStatement> m_body;

    public:
        ForStatement(Token& token) : m_token(new Token(token)) {}

    public:
        string token_literal() { return m_token->m_literal; }
        string to_string() {
            string ret = "";

            ret += "for";
            ret += "(";

            ret += m_loop_var->to_string();
            ret += m_condition->to_string();
            ret += m_next_step->to_string();

            ret += ")";
            ret += m_body->to_string();

            return ret;
        }
    };
}
#endif /* FORSTATEMENT_HPP */
