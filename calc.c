#include "calc.h"

// TODO: Move to a separate module 'calc'
double Calculate(char const* expression, error_t* error)
{
	double result;

	//���󣡣�����
	{
		int i = 0;
		int n = 0;

		//�ж������Ƿ�ɶԳ���
		while (expression[i]){
			if (expression[i] == '('){
				n++;
			}
			else if (expression[i] == ')'){
				n--;
			}
			i++;
		}
		if (n != 0)
			*error = ERR_WRONG_SYMBOL;

		i = 0;
		//���ʽ�������ֵȺű��ʽ����
		while (expression[i]){
			if (expression[i++] == '=')
				*error = ERR_WRONG_SYMBOL;
		}

		//��ʽ�в��������������������
		/*i = 1;
		while (expression[i] && expression[i + 1]){
			if (expression[i] == ('+' || '-' || '*' || '/' || '.') && expression[i + 1] == ('+' || '-' || '*' || '/' || '.')){
				*error = ERR_WRONG_SYMBOL;
				i++;
			}
		}*/
	}

	//��ȷ���ʽ���������ź�˳��ټӼ�


	// TODO: Replace with a computational algorithm subdivided into modules/functions
	//UNUSED_PARAMETER(expression);
	result = 4.0;
	//if (error != NULL)
	//	*error = ERR_OK;

	return result;
}