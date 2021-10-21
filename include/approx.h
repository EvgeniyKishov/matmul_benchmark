#pragma once

/**
* approx.h - approximation of functions
*/

#include "math_common.h"
#include "vm.h"
#include "sleslv.h"

/**
* polappr() - (POLynomyal APPRoximation) �������������� �������������
* @a: (�����) ������ ������������� ��������
* @x: ������ �������
* @y: ������ �������
* 
* ������� ���������� �����-�� �������� 
* a0 + a1*x + a2*(x^2) + ... + an*(x^n),
* ����������� ����� ����� xi � yi, �� ������ ���������� ���������.
* 
* ���� ���� �� ���������� ����� NULL -> ������������ -2.
*/
int DLL polappr(struct vec *a, const struct vec *x, const struct vec *y);