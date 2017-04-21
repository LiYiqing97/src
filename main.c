#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"

// TODO: Include local header files
// TODO: Use all unused parameters and remove this temporary definition
// Helps eliminating warning C4100: 'error': unreferenced formal parameter
#define UNUSED_PARAMETER(name) (void)name

//////////////////////////////////////////////////////////////////////////////
// Dummy calc module


//////////////////////////////////////////////////////////////////////////////
// UI functions

int main(int argc, char const* argv[])
//int main(void)
{
	FILE* in = stdin;
	char* line = NULL;

	// Choose an input source 
	////选择输入源（若main函数参数大于1，且文件为空则返回-1）
	if (argc > 1 && (in = fopen(argv[1], "r")) == NULL)
	{
	printf("ERROR: Cannot open file '%s'\n", argv[1]);
	return -1;
	}
	/*in = fopen("b.txt", "r");
	if (in == stdin)
		printf("ERROR: Cannot open file\n");*/
	// Process the data line by line
	//若文件不为空，读取文件，并原文输出
	while ((line = ReadLine(in)) != NULL)
	{
		ProcessLine(line);
		free(line);
	}

	// Clean up
	if (in != stdin)
		fclose(in);
	return 0;
}
