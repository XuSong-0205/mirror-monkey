#ifndef CONSTANT_HPP
#define CONSTANT_HPP
#include <string>

using namespace std;

namespace mirror {
namespace object {
enum class OBJECT_TYPE {
    NULL_OBJ,       //  "NULL"
    ERROR_OBJ,      //  "ERROR"

    BOOLEAN_OBJ,    // "BOOLEAN"
    INTEGER_OBJ,    // "INTEGER"
    FLOAT_OBJ,      // "FLOAT"
    STRING_OBJ,     // "STRING"

    RETURN_VALUE_OBJ,   // "RETURN_VALUE"

    FUNCTION_OBJ,       // "FUNCTION"

    BUILTIN_OBJ,        // "BUILTIN"

    ARRAY_OBJ,          // "ARRAY"
    HASH_OBJ,           // "HASH"
};

const string OBJECT_TYPE_VALUE[] = {

    "NULL",  // NULL_OBJ
    "ERROR", // ERROR_OBJ
    "STRING",

    "INTEGER", // INTEGER_OBJ
    "BOOLEAN", // BOOLEAN_OBJ

    "RETURN_VALUE", // RETURN_VALUE_OBJ

    "FUNCTION", // FUNCTION_OBJ
    "BUILTIN",

    "ARRAY",
    "HASH"
};

} // namespace object
}
#endif /* CONSTANT_HPP */
