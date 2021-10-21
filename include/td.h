#pragma once

/**
* td.h - Tridiagonal SLE solver
*/

#include "math_common.h"
#include "vm.h"

/**
* tdslesv() - решение СЛАУ с тридиаг. матрицей методом прогонки
* (Tridiagonal Sys. of Lin. Eqs. Solve)
* Алгоритм обобщён на случай матриц со смещением.
* См. https://yadi.sk/i/DSl020OF1Kzl8Q
*
* @m: трёхдиаг. матрица
* @rhs: вектор правой части СЛАУ
* @x: вектор решения
* @offs: смещение диагоналей
* 
* Функция возвращает -1, если какой-либо из диагональных элементов = 0.
* Если какой-либо из указателей == NULL -> вовзвращается -2.
*/
int DLL tdslesv(const struct tdmatr *m, const double *rhs, double *x, int offs);