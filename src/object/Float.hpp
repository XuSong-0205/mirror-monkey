#ifndef FLOAT_HPP
#define FLOAT_HPP

#include "Hashable.hpp"
#include "Object.hpp"
#include <memory>

using namespace std;
using namespace mirror;
using namespace object;

namespace mirror {
    class Float : public Object, public Hashable {
    public:
        double m_value;

    public:
        Float(double value) : m_value(value) {};

    public:
        OBJECT_TYPE type() override { return OBJECT_TYPE::FLOAT_OBJ; };
        string Inspect() override { return to_string(m_value); };

    public:
        HashKey hash_key() override {
            HashKey hk(type(), *reinterpret_cast<uint64_t*>(&m_value));
            return hk;
        };
    };
}
#endif /* FLOAT_HPP */
