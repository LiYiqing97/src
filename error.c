#include "error.h"

// TODO: Move to a separate module 'calc'
char const* GetErrorString(error_t error)//¥ÌŒÛ¿‡–Õ
{
	// TODO: Find the corresponding error description
	//UNUSED_PARAMETER(error);
	switch (error){
	case ERR_NOT_ENOUGH_MEMORY:
		return "not enough memory";
	case ERR_WRONG_SYMBOL:
		return "wrong symbol";
	case ERR_OK:
		return "without error";
	default:
		return "";
	}

}

error_t ReportError(error_t error)//±®¥Ì
{
	printf("ERROR: %s\n", GetErrorString(error));
	return error;
}