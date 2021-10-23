using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MatMulLib
{
    public class MatMulTest
    {
        public static void MatMul(double[][] C, double[][] A, double[][] B, int n)
        {
            //for (int i = 0; i < n; i++)
            Parallel.For(0, n, i => 
            {            
                for (int j = 0; j < n; j++)
                {
                    C[i][j] = 0.0;
                    for (int k = 0; k < n; k++)
                        C[i][j] += A[i][k] * B[k][j];
                }
            });
        }
    }
}
