/*

#include "../../../inc/_h/numtypes.h"
#include "../../../inc/_h/DTypes.h"
#include "../../../inc/_h/std.h"
#include <stdlib.h>
#include <stdio.h>

extern i64 rd(unsigned int f, char *buffer, u64 s);
// extern void* alloc(u64 s);
// extern void free(void *ptr);

i64 rdln(Buffer *buffer){
	printf("rd:0x00\n");
	i64 res = rd(STDIN, buffer->buffer, buffer->allmemory);
	i64 r = 0;

	if(res == -1)
		return -2;

	while(*(buffer->buffer + (res - 1)) != '\n'){
		buffer->allmemory += 128;
	    // u8 *newBuffer = (u8*)alloc(buffer->length);

		u8 *newBuffer = (u8*)malloc(buffer->allmemory);

		if(newBuffer == NULL)
			return -3;

		for(u64 i = 0; i < res; i++)
			*(newBuffer + i) = *(buffer->buffer + i);

		free(buffer->buffer);

		buffer->buffer = newBuffer;
		r = rd(STDIN, buffer->buffer + res, 128);
		printf("rd:0x01\n");

		if(r == -1)
			return -2;

		res += r;
	}

	if(res < buffer->allmemory){
		char stdincollector[24];
		i64 r = 0;

		while(1){
			r = rd(STDIN, stdincollector, sizeof(stdincollector));
			printf("rd:0x02\n");

			if(r == -1)
				return -2;

			if(*(stdincollector + (r - 1)) == '\n')
				break;
		}
	}

	buffer->length = res;
    *(buffer->buffer + (res - 1)) = '\0';
    return 0;
}

*/


