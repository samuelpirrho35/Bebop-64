#include "../../../inc/_h/input.h"
#include "../../../inc/_h/output.h"
#include "../../../inc/_h/DTypes.h"
#include "../../../inc/_h/numtypes.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	Buffer buffer;
	buffer.buffer = (u8*)malloc(24);
	buffer.allmemory = 24;

	for(int i = 0; i < 24; i++)
		*(buffer.buffer + i) = 0x00;

	char auxiliaryBuffer[] = "Insert a text: ";
	i64 res_out = module_wrt(auxiliaryBuffer, sizeof(auxiliaryBuffer) - 1);
	if(res_out < 0){
		free(buffer.buffer);
		return res_out;
	}

	i64 res_in = rdln(&buffer);
	if(res_in < 0){
		free(buffer.buffer);
		return res_in;
	}

	res_out = wrtln((char*)buffer.buffer, buffer.length - 1);
	if(res_out < 0){
		free(buffer.buffer);
		return res_out;
	}

	printf("\nBuffer::allmemory: %lld\n", buffer.allmemory);
	printf("Buffer::length: %lld\n", buffer.length);
	printf("Buffer::buffer: %s\n", (char*)buffer.buffer);

	free(buffer.buffer);
	return 0;
}
