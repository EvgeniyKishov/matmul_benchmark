#pragma once

/**
* approx.h - approximation of functions
*/

#include "math_common.h"
#include "vm.h"
#include "sleslv.h"

/**
* polappr() - (POLynomyal APPRoximation) полиномиальная аппроксимация
* @a: (ВЫХОД) массив коэффициентов полинома
* @x: массив абсцисс
* @y: массив ординат
* 
* Функция определяет коэфф-ты полинома 
* a0 + a1*x + a2*(x^2) + ... + an*(x^n),
* проходящего через точки xi и yi, по методу наименьших квадратов.
* 
* Если один из аргументов равен NULL -> возвращается -2.
*/
int DLL polappr(struct vec *a, const struct vec *x, const struct vec *y);