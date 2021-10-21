using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace matmul_Csharp
{
    class Program
    {
        static double Rnd(Random random, double scale)
        {            
            return random.NextDouble() * scale;
        }

        static void RndFillMatrix(Random random, double[][] A, int n)
        {            
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i == j)
                        A[i][j] = Rnd(random, 100.0);
                    else
                        A[i][j] = Rnd(random, 10.0);
        }

        static void MatMul(double[][] C, double[][] A, double[][] B, int n)
        {
            for (int i = 0; i < n; i++)
            //Parallel.For(0, n, i =>            
                for (int j = 0; j < n; j++)
                {
                    C[i][j] = 0.0;
                    for (int k = 0; k < n; k++)
                        C[i][j] += A[i][k] * B[k][j];
                }
            //});
        }

        static void Main(string[] args)
        {
            Random random = new Random();

            int n = 100;
            double[][] A;
            A = new double[n][];
            for (int i = 0; i < n; i++)
                A[i] = new double[n];
            RndFillMatrix(random, A, n);

            double[][] B;
            B = new double[n][];
            for (int i = 0; i < n; i++)
                B[i] = new double[n];
            RndFillMatrix(random, B, n);

            double[][] C;
            C = new double[n][];
            for (int i = 0; i < n; i++)
                C[i] = new double[n];

            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            MatMul(C, A, B, n);
            stopWatch.Stop();
            Console.WriteLine($"Execution Time: {stopWatch.ElapsedMilliseconds} ms");
            Console.ReadLine();
        }
    }
}
