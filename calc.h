#ifndef _CALC_H_INCLUDED_
#define _CALC_H_INCLUDED_
#pragma once

#include <stdio.h>
#include <math.h>
#include "func.h"

#define e = 2,7182;

double Calculate(char const* expression, error_t* error);

#endif