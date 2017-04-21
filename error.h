#ifndef _ERROR_H_INCLUDED_
#define _ERROR_H_INCLUDED_
#pragma once

#include <stdio.h>

typedef enum
{
	ERR_OK,
	ERR_WRONG_SYMBOL,
	ERR_NOT_ENOUGH_MEMORY,
	// TODO: Add your own error codes
} error_t;

char const* GetErrorString(error_t error);
error_t ReportError(error_t error);

#endif