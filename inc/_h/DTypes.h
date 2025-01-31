#ifndef DTypes_h
#define DTypes_h

#include "numtypes.h"

typedef struct Buffer {
    u8 *buffer;
    u64 length;
    u64 allmemory;
} Buffer;

typedef char* string;
typedef unsigned short* x10str;

#endif // DTypes_h