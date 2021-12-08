#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "kemak_math.h"
#include <omp.h>
#include <windows.h>

#define USE_PARALLEL 1
#define SEQUENTIAL   0

struct matr2 {	
	double** v;
	int n, m;
};

struct matr2 *create_matr2(int n, int m)
{
	struct matr2* a = NULL;
	a = calloc(1, sizeof(struct matr2));
	if (a == NULL)
		return NULL;
	a->n = n;
	a->m = n;
	a->v = calloc(n, sizeof(double*));
	if (a->v == NULL)
		return NULL;
	for (int i = 0; i < m; i++)
		a->v[i] = calloc(n, sizeof(double));
	return a;
}

double** create_matr_arr(int n)
{
	double **a = NULL;
	a = calloc(n, sizeof(double*));
	for (int i = 0; i < n; i++)
		a[i] = calloc(n, sizeof(double));
	return a;
}

static void matmul2(struct matr2* c, const struct matr2* a, const struct matr2* b, 
		    int parl)
{
	int i = 0;
	//storing pointers gives a performance gain
	//double **cv = c->v,
	//       **av = a->v,
	//       **bv = b->v;
	#pragma omp parallel for if (parl == USE_PARALLEL)
	for (i = 0; i < c->n; i++) {
		int j = 0;
		//#pragma omp parallel for if (parl == USE_PARALLEL)
		for (j = 0; j < c->n; j++)
		{
			c->v[i][j] = 0.0;
			for (int k = 0; k < a->n; k++)
				c->v[i][j] += a->v[i][k] * b->v[k][j];
		}
	}
}

static void matmul2_arr(double **c, double **a, double **b, int n, int parl)
{
	int i = 0;
	#pragma omp parallel for if (parl == USE_PARALLEL)
	for (i = 0; i < n; i++) {
		int j = 0;
		//#pragma omp parallel for if (parl == USE_PARALLEL)
		for (j = 0; j < n; j++)
		{
			c[i][j] = 0.0;
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
}

double rnd(double scale)
{
	return ((double)rand()/RAND_MAX)*scale;
}

void rnd_fill_matr(struct matr2 *m)
{	
	for (int i = 0; i < m->n; i++)
		for (int j = 0; j < m->n; j++)
			if (i == j)
				m->v[i][j] = rnd(100.0);
			else
				m->v[i][j] = rnd(10.0);
}

void rnd_fill_matr_arr(double **m, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				m[i][j] = rnd(100.0);
			else
				m[i][j] = rnd(10.0);
}

void rnd_fill_vec(struct vec *v)
{
	for (int i = 0; i < v->n; i++)
		v->v[i] = rnd(10);
}

void main()
{
	srand((unsigned int)time(0));

	//MessageBox(NULL, TEXT("Привет"), TEXT("Мой заголовок"), MB_OK);

	int n = 500;
	struct matr2 *a = create_matr2(n, n);
	//double **a = create_matr_arr(n);
	rnd_fill_matr(a);
	//rnd_fill_matr_arr(a, n);
	//printf("Matrix [A]: \n");
	//print_matr(a, "%6.2f");

	struct matr2 *b = create_matr2(n, n);
	//double **b = create_matr_arr(n);
	//rnd_fill_matr_arr(b, n);
	rnd_fill_matr(b);
	//printf("Matrix [B]: \n");
	//print_matr(b, "%6.2f");

	struct matr2 *c = create_matr2(n, n);
	//double **c = create_matr_arr(n);
	clock_t begin = clock();
	//matmul2_arr(c, a, b, n, USE_PARALLEL);
	matmul2(c, a, b, SEQUENTIAL);
	clock_t end = clock();
	double time_spent = (double)(end - begin);
	printf("time spent = %lf\n", time_spent);

	//printf("Matrix [C] = [A]*[B]: \n");
	//print_matr(c, "%12.2f");

	//delete_matr(&a);
	//delete_matr(&b);
	//delete_matr(&c);
	getchar();
}