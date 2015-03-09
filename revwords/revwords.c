#include "../lib/helpers.h"
#include <string.h>
#include <stdlib.h>

const int LEN = 4096;


void reverse(char* str, int len) 
{
	for (int i = 0; i < len / 2; ++i) 
	{
		char tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

int main() 
{
	void* buf = malloc(LEN);
	memset(buf, 0, LEN);
	int have = 0;
	int red;
	while((red = read_until(STDIN_FILENO, (char*)buf, LEN, ' ')) != 0) 
	{	
		reverse(buf, red - 1);
		write_(STDOUT_FILENO, buf, red);
		memset(buf, 0, LEN);
	}
	free(buf);
	return 0;
}