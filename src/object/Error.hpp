#ifndef ERROR_HPP
#define ERROR_HPP

#include "Object.hpp"

using namespace std;
using namespace mirror;
using namespace object;

namespace mirror {
class Error : public Object {
  public:
    string m_message;

  public:
    OBJECT_TYPE type() { return OBJECT_TYPE::ERROR_OBJ; };
    string Inspect() { return "Error: " + m_message; };
};
}

namespace std {
    inline string to_string(const char* str) {
        return std::string(str);
    }
}

template<typename... Args>
std::shared_ptr<Error> new_error(Args&&... args) {
    auto ret = make_shared<Error>();
    std::string str;
    int temp[]{ (str += std::to_string(args), 0)... };
    ret->m_message = str;
    return ret;
}


#endif /* ERROR_HPP */
