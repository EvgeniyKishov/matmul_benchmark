
import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
    private static final int NUM_CORES = Runtime.getRuntime().availableProcessors();

    public static void main(String[] args) {
        testMul(2);
        testMul(100);
        testMul(500);
        testMul(1000);
        testMul(2000);
        System.out.println("Program completed");
    }

    public static void testMul(int n) {
        long timeBefore;
        long timeAfter;
        long elapsed;

        Random random = new Random();

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

        double[][] C2;
        C2 = new double[n][];
        for (int i = 0; i < n; i++)
            C2[i] = new double[n];

        timeBefore = System.currentTimeMillis();
        MatMul(C, A, B, n);
        timeAfter = System.currentTimeMillis();
        elapsed = timeAfter - timeBefore;
        System.out.println("n = " + n + ", Execution Time (for): " + elapsed + "ms");
        timeBefore = System.currentTimeMillis();
        ParallelMatMul(C2, A, B, n);
        timeAfter = System.currentTimeMillis();
        elapsed = timeAfter - timeBefore;
        System.out.println("n = " + n + ", Execution Time: (parallel.for)" + elapsed + "ms");
        System.out.println("**********************");
    }

    public static void MatMul(double[][] C, double[][] A, double[][] B, int n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                C[i][j] = 0.0;
                for (int k = 0; k < n; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }
    }

    public static void ParallelMatMul(double[][] C, double[][] A, double[][] B, int n) {
        Loop.withIndex(0, n, new Loop.Each() {
            public void run(int i) {
                for (int j = 0; j < n; j++)
                {
                    C[i][j] = 0.0;
                    for (int k = 0; k < n; k++)
                        C[i][j] += A[i][k] * B[k][j];
                }
            }
        });
    }

    static void RndFillMatrix(Random random, double[][] A, int n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i == j)
                    A[i][j] = Rnd(random, 100.0);
                else
                    A[i][j] = Rnd(random, 10.0);
    }

    static double Rnd(Random random, double scale) {
        return random.nextDouble() * scale;
    }
}

