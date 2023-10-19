#ifndef FUNCTIONSTATEMENT_HPP
#define FUNCTIONSTATEMENT_HPP

#include "BlockStatement.hpp"
#include "Statement.hpp"
#include "Identifier.hpp"
#include "Token.hpp"
#include <memory>
#include <string>
#include <vector>

using namespace std;
namespace mirror {
    class FunctionStatement : public Statement {
    public:
        unique_ptr<Token> m_token;
        shared_ptr<Identifier> m_name;
        shared_ptr<vector<unique_ptr<Identifier>>> m_parameters;
        shared_ptr<BlockStatement> m_body;

    public:
        FunctionStatement(Token& token) : m_token(new Token(token)) {};

    public:
        string token_literal() override { return m_token->m_literal; };
        string to_string() override {
            string ret = "";

            ret += token_literal();
            ret += m_name->to_string();
            ret += "(";
            auto& parameters = *m_parameters;
            for (int i = 0; i < parameters.size(); i++) {
                ret += parameters[i]->to_string();
                if (i < parameters.size() - 1) {
                    ret += ", ";
                }
            }
            ret += ") ";
            ret += m_body->to_string();

            return ret;
        };
    };
}
#endif /* FUNCTIONSTATEMENT_HPP */
