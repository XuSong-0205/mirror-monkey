#include "Repl.hpp"
#include "Repl.hpp"
#include "Environment.hpp"
#include "Evaluator.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

void print_anthor_name();
void print_parser_errors(vector<string> errors);

void Repl::start() {

    print_anthor_name();

    const string PROMPT = ">> ";

    std::string line;

    Evaluator e;
    auto env = make_shared<Environment>();
    while (1) {
        cout << PROMPT;
        getline(cin, line);
        Lexer l(line);
        Parser p(l);

        // for (auto tok = l.next_token(); (*tok).m_type != TOKEN_TYPE::EOF_;
        //      tok = l.next_token()) {
        //     cout << *tok << endl;
        // }

        auto program = p.parse_program();
        if (p.errors().size() != 0) {
            print_parser_errors(p.errors());
            continue;
        }

        cout << program->to_string() << endl;

        auto evaluated = e.eval(program.get(), env.get());
        if (evaluated) {
            cout << evaluated->Inspect() << endl;
        }
    }
}

void mirror::Repl::exec(const char* file)
{
    std::ifstream ifile(file);
    if (!ifile) {
        std::cout << "file: " << file << " not found!\n";
        return;
    }

    std::istreambuf_iterator<char> beg(ifile);
    std::istreambuf_iterator<char> end;
    std::string code(beg, end);
    ifile.close();

    Evaluator global_env;
    auto env = make_shared<Environment>();

    Lexer lexer(code);
    Parser parser(lexer);
    auto program = parser.parse_program();
    if (parser.errors().size() != 0) {
        print_parser_errors(parser.errors());
        return;
    }

    auto evaluated = global_env.eval(program.get(), env.get());
    if (evaluated) {
        cout << evaluated->Inspect() << endl;
    }
}

void print_anthor_name() {
    string name = R"(
	########################
	#¨q©¥©¥¨r¨u¨u¨u¨u¨u¨u¨u¨u¨q¨r        #
	#¨t©§©§©ï©¥©¥©×©×¨r¨q©¥©¥©ï©ï©×©×©×©×©¥©×©×¨r#
	#¨q©§©§©Ï©§©§©§©§©§©§©§©§©§©§¨q©Ï¨q©Ï©ï©§¨q¨s#
	#¨t©¥©¥©ß©ß©ß©ï¨r©§¨t©ß©ß©ß©ß¨s¨t¨s¨t©¥©ß¨s #
	#¨u¨u¨u¨u¨u¨u¨t©¥¨s             #
	########################
)";

    cout << name << endl;
}

void print_parser_errors(vector<string> errors) {
    print_anthor_name();
    cout << "Woops! We ran into some `mirror` business here!\n";
    cout << " parser errors:\n";
    for (int i = 0; i < errors.size(); i++) {
        cout << "\t" << errors[i] << endl;
    }
}