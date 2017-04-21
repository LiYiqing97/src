#include "func.h"

char* ReadLine(FILE* in)//��ȡ�ļ����ַ���
{
	char* line = NULL;
	char value;//value���ļ�һ�е��ַ���
	// TODO: Read a line of text into a dynamic memory block

	int i = 0;
	error_t firstError = ERR_NOT_ENOUGH_MEMORY;

	//�����ڴ�ʧ�ܷ��ر����ڴ治��
	if ((line = (char *)malloc(sizeof(char))) == NULL)
	{
		ReportError(firstError);
		return "";
	}
	
	//���ļ�û�н�β��û�л��У����ļ���cΪ�ļ���һ�е��ַ���
	while ((value = (char)fgetc(in)) != EOF && value != '\n')
	{
		char *tmp;
		line[i++] = value;
		if ((tmp = (char *)realloc(line, (i + 1) * sizeof(char))) == NULL)//���������ڴ�
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

void ProcessLine(char const* line)//Ѱ�ұ��ʽ
{
	error_t lastError = ERR_OK;
	if (!NeedCalculate(line))//�������ַ��������,NeedCalculate����ֵΪ0�����ַ���
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

int NeedCalculate(char const* line)//ȷ�����Ƿ�������ʽ
{
	// TODO: Determine if the line contains an expression
	//UNUSED_PARAMETER(line);
	int i = 0;

	while (line[i] != '\0')
	{
		if ((line[i] >= 48 && line[i] <= 57) || line[i] == '(' || line[i] == '-')//�ж����ַ��Ƿ�Ϊ����
			return 1;
		else
			return 0;
	}

	return 0;
}