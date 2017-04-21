#include "func.h"

char* ReadLine(FILE* in)//读取文件内字符串
{
	char* line = NULL;
	char value;//value是文件一行的字符串
	// TODO: Read a line of text into a dynamic memory block

	int i = 0;
	error_t firstError = ERR_NOT_ENOUGH_MEMORY;

	//申请内存失败返回报错，内存不足
	if ((line = (char *)malloc(sizeof(char))) == NULL)
	{
		ReportError(firstError);
		return "";
	}
	
	//若文件没有结尾且没有换行，读文件，c为文件内一行的字符串
	while ((value = (char)fgetc(in)) != EOF && value != '\n')
	{
		char *tmp;
		line[i++] = value;
		if ((tmp = (char *)realloc(line, (i + 1) * sizeof(char))) == NULL)//继续申请内存
		{
			ReportError(firstError);
			return "";
		}
		line = tmp;
	}

	line[i] = '\0';

	//printf("%s\n", line);

	if (i == 0 && value == EOF)
		return NULL;


	return line;
}

void ProcessLine(char const* line)//寻找表达式
{
	error_t lastError = ERR_OK;
	if (!NeedCalculate(line))//若存在字符串则输出,NeedCalculate返回值为0存在字符串
	{
		puts(line);
		return;
	}

	printf("%s == ", line);
	//printf("lasterror = %i\n", lastError);
	double result = Calculate(line, &lastError);
	
	if (lastError == ERR_OK)
		printf("%lg\n", result);
	else
		ReportError(lastError);
}

int NeedCalculate(char const* line)//确定行是否包含表达式
{
	// TODO: Determine if the line contains an expression
	//UNUSED_PARAMETER(line);
	int i = 0;

	while (line[i] != '\0')
	{
		if ((line[i] >= 48 && line[i] <= 57) || line[i] == '(' || line[i] == '-')//判断首字符是否为数字
			return 1;
		else
			return 0;
	}

	return 0;
}