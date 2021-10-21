#pragma once

/**
* td.h - Tridiagonal SLE solver
*/

#include "math_common.h"
#include "vm.h"

/**
* tdslesv() - ������� ���� � �������. �������� ������� ��������
* (Tridiagonal Sys. of Lin. Eqs. Solve)
* �������� ������� �� ������ ������ �� ���������.
* ��. https://yadi.sk/i/DSl020OF1Kzl8Q
*
* @m: �������. �������
* @rhs: ������ ������ ����� ����
* @x: ������ �������
* @offs: �������� ����������
* 
* ������� ���������� -1, ���� �����-���� �� ������������ ��������� = 0.
* ���� �����-���� �� ���������� == NULL -> ������������� -2.
*/
int DLL tdslesv(const struct tdmatr *m, const double *rhs, double *x, int offs);