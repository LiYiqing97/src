#ifndef _FUNC_H_INCLUDED_
#define _FUNC_H_INCLUDED_
#pragma once


#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "calc.h"


char* ReadLine(FILE* in);
void ProcessLine(char const* line);
int NeedCalculate(char const* line);

#endif