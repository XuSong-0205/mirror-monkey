#ifndef REPL_HPP
#define REPL_HPP

namespace mirror {
class Repl{
public:
	void start();
	void exec(const char* file);
};
}
#endif /* REPL_HPP */
