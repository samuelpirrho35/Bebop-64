#include "../../../inc/_h/numtypes.h"
#include "../../../inc/_h/DTypes.h"
#include "../../../inc/_h/std.h"
#include <stdlib.h>
#include <string.h>

extern i64 rd(unsigned int f, char *buffer, u64 s);

i64 rdln(Buffer *buffer){
    i64 res = rd(STDIN, buffer->buffer, buffer->allmemory);
    i64 totalRead = res;

    if(res == -1)
        return -2;

    if(*(buffer->buffer + (res - 1)) == '\n'){
        *(buffer->buffer + (res - 1)) = '\0';
        buffer->length = res;
        return 0;
    }

    while(*(buffer->buffer + (totalRead - 1)) != '\n'){
        buffer->allmemory += 128;
        u8 *newBuffer = (u8*)malloc(buffer->allmemory);

        if(newBuffer == NULL)
            return -3;

        memcpy(newBuffer, buffer->buffer, totalRead);

        free(buffer->buffer);
        buffer->buffer = newBuffer;

        res = rd(STDIN, buffer->buffer + totalRead, 128);

        if(res == -1)
            return -2;

        totalRead += res;

        if(*(buffer->buffer + (totalRead - 1)) == '\n'){
            *(buffer->buffer + (totalRead - 1)) = '\0';
            buffer->length = totalRead;
            return 0;
        }
    }

    if(totalRead < buffer->allmemory){
        char stdincollector[24];
        while(1){
            res = rd(STDIN, stdincollector, sizeof(stdincollector));

            if(res == -1)
                return -2;

            if(*(stdincollector + (res - 1)) == '\n')
                break;
        }
    }

    buffer->length = totalRead;
    return 0;
}
