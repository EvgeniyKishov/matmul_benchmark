#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kemak_math.h"

double rnd(double scale)
{
	return ((double)rand()/RAND_MAX)*scale;
}

void rnd_fill_matr(struct matr *m)
{	
	for (int i = 0; i < m->n; i++)
		for (int j = 0; j < m->n; j++)
			if (i == j)
				m->v[i][j] = rnd(100.0);
			else
				m->v[i][j] = rnd(10.0);
}

void rnd_fill_vec(struct vec *v)
{
	for (int i = 0; i < v->n; i++)
		v->v[i] = rnd(10);
}

void main()
{
	srand((unsigned int)time(0));

	int n = 2000;
	struct matr *a = create_matr(n, n);
	rnd_fill_matr(a);
	//printf("Matrix [A]: \n");
	//print_matr(a, "%6.2f");

	struct matr *b = create_matr(n, n);
	rnd_fill_matr(b);
	//printf("Matrix [B]: \n");
	//print_matr(b, "%6.2f");

	struct matr *c = create_matr(n, n);
	clock_t begin = clock();
	matmul(c, a, b);
	clock_t end = clock();
	double time_spent = (double)(end - begin);
	printf("time spent = %lf\n", time_spent);

	//printf("Matrix [C] = [A]*[B]: \n");
	//print_matr(c, "%12.2f");

	delete_matr(&a);
	delete_matr(&b);
	delete_matr(&c);
	getchar();
}