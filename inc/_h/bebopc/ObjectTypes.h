#ifndef OBJECT_TYPES
#define OBJECT_TYPES

#include <inttypes.h>

typedef enum ObjectTypes {
    i8type,
    i16type,
    i32type,
    i64type,
    i128type,

    u8type,
    u16type,
    u32type,
    u64type,
    u128type,

    f32type,
    f64type,

    chartype,
    strtype,
    stringtype,

    arraytype,
    buffertype,
    hashmaptype,
    listtype,
    settypes,
    structtype,
    enumtype
} ObjectTypes;


typedef struct VarType {
    ObjectTypes dtype;
    string      value;
} VarType;


typedef struct KeyType {
    ident_or_object_or_method *keyptr;
} KeyType;


typedef struct TOK {
    uint8_t  tokenType;

    union value {
        VarType var_type;
        KeyType key_type;
    } value;
} TOK;


typedef struct Tokens {
    uint64_t allsize;
    uint64_t len;
    TOK      *toks;
} Tokens;

#endif // OBJECT_TYPES