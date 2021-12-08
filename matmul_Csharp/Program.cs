using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using MatMulLib;

namespace matmul_Csharp
{

    class Real
    {
        private double val;

        public Real()
        {
            this.val = 0.0;
        }

        public Real(double val)
        {
            this.val = val;
        }

        public static Real operator+(Real a, Real b)
        {
            Real c = new Real();
            c.val = a.val + b.val;
            return c;
        }

        public static Real operator*(Real a, Real b)
        {
            Real c = new Real();
            c.val = a.val * b.val;
            return c;
        }
    }

    class Matrix
    {
        private int n, m;
        private double[] data;

        public Matrix(int n, int m) 
        {
            this.n = n;
            this.m = m;
            this.data = new double[n * m];
        }

        public double this[int i, int j]
        {
            get { return data[(i - 1) * m + j - 1]; }
            set { data[(i - 1) * m + j - 1] = value; }
        }

        public static Matrix operator*(Matrix A, Matrix B)
        {
            int n = A.n, m = A.m;
            Matrix C = new Matrix(n,m);
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                {
                    C[i, j] = 0.0;
                    for (int k = 1; k <= n; k++)
                        C[i, j] = C[i, j] + A[i, k] * B[k, j];
                }
            return C;
        }

        public void RandomFill(Random rnd)
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (i == j)
                        this[i,j] = rnd.NextDouble() * 100;
                    else
                        this[i,j] = rnd.NextDouble() * 10;
        }
    }

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
        
        static void Main2(string[] args)
        {
            Random random = new Random();

            int n = 2000;
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
            //MatMulTest.MatMul(C, A, B, n);
            MatMul(C, A, B, n);
            stopWatch.Stop();
            Console.WriteLine($"Execution Time: {stopWatch.ElapsedMilliseconds} ms");
            Console.ReadLine();
        }

        static void Main(string[] args)
        {
            Random random = new Random();

            int n = 2000;
            Matrix A = new Matrix(n,n);
            A.RandomFill(random);
            Matrix B = new Matrix(n,n);
            B.RandomFill(random);
            Matrix C = new Matrix(n,n);
            C.RandomFill(random);

            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            C = A * B;
            stopWatch.Stop();
            Console.WriteLine($"Execution Time: {stopWatch.ElapsedMilliseconds} ms");
            Console.ReadLine();
        }
    }
}
