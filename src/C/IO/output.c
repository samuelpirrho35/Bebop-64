#include "../../../inc/_h/numtypes.h"
#include "../../../inc/_h/std.h"

extern i64 wrt(unsigned int f, char *buffer, u64 count);

i64 module_wrt(char *buffer, u64 s){
	i64 res = wrt(STDOUT, buffer, s);
	if(res == -1)
		return -1;

	return 0;
}

i64 wrtln(char *buffer, u64 s){
	char nln[] = "\n";

	i64 res = wrt(STDOUT, buffer, s);
	if(res == -1)
		return -1;

	if(wrt(STDOUT, nln, sizeof(nln)) == -1)
		return -1;

	return 0;
}
