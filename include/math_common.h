#pragma once

/**
* math_common.h - ��������������� �������
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef DLL 
	#define DLL __declspec(dllexport)
#endif

/**
* DEALLOC() - �������-������ ��� ������������ ������ � ���������� ���������
*/
#ifndef DEALLOC
	#define DEALLOC(obj) {free(obj); obj = NULL;}
#endif

#ifndef SMALL_VAL 
	#define SMALL_VAL 1.0e-30
#endif

/**  
* ABS() - �������-������ ��� ���������� |x|
*/
#ifndef ABS
	#define ABS(x) (((x) >= 0) ? (x) : (-x))
#endif 

/**  
* IS_SMALL() - �������� ����� �� �������
*/
#ifndef IS_SMALL
	#define IS_SMALL(x) ((ABS(x) <= SMALL_VAL) ? 1 : 0)
#endif 

#ifndef SQR
	#define SQR(x) ((x)*(x))
#endif 

#ifndef CUBE
	#define CUBE(x) ((x)*(x)*(x))
#endif

#ifndef MAX
	#define MAX(a,b) (((a) >= (b)) ? (a) : (b))
#endif

#ifndef MIN
	#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#endif
	
/**
* SWAPD() - �������-������ ��� ����� �������� ���������� a � b,
* ������� ��� double, ���� � ������
*/
#ifndef SWAPD
#define SWAPD(a,b) {\
		double tmp; \
		tmp = a; \
		a = b; \
		b = tmp; \
	}
#endif

/**
* kemak_math_ver() - ��������� ������ dll
* ���� ���������� ������� � ���������� ������������, 
* ������������ �������� < 0.
*/
double DLL kemak_math_ver();
