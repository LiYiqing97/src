#include "calc.h"

// TODO: Move to a separate module 'calc'
double Calculate(char const* expression, error_t* error)
{
	double result;

	//错误！！！！
	{
		int i = 0;
		int n = 0;

		//判断括号是否成对出现
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
		//表达式中若出现等号表达式错误
		while (expression[i]){
			if (expression[i++] == '=')
				*error = ERR_WRONG_SYMBOL;
		}

		//等式中不能连续有两个计算符号
		/*i = 1;
		while (expression[i] && expression[i + 1]){
			if (expression[i] == ('+' || '-' || '*' || '/' || '.') && expression[i + 1] == ('+' || '-' || '*' || '/' || '.')){
				*error = ERR_WRONG_SYMBOL;
				i++;
			}
		}*/
	}

	//正确表达式计算先括号后乘除再加减


	// TODO: Replace with a computational algorithm subdivided into modules/functions
	//UNUSED_PARAMETER(expression);
	result = 4.0;
	//if (error != NULL)
	//	*error = ERR_OK;

	return result;
}