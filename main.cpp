#include <stdio.h>
#include <stdlib.h>
// 16bit image 2**16 = 65536, GRBG pattern, row major storage type(m = i*N+j), copy two row column for boundaries
#define N 6 // N*N image

int main()
{
    int *r, *g, *b;
    r = new int[N * N];
    g = new int[N * N];
    b = new int[N * N];

    // image initialization
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            r[i] = i * N + j;
            g[i] = i * N + j;
            b[i] = i * N + j;
        }
    }
    // green interpolation, boundaries are included
    for (int j = 0; j < N * N; j += 2 * N)
    {
        for (int i = 1; i < N; i += 2)
        {
            // red pixel's green color
        }
    }

    // green interpolation, boundaries are neglected
    int alpha = 0, beta = 0;
    int A1, A3, A5, A7, A9;
    int G2, G4, G6, G8;
    int G5;
    for (int j = 2 * N; j < N * N - 2 * N; j += 2 * N)
    {
        for (int i = 3; i < N - 2; i += 2)
        {
            // finding red pixel's green color
            A1 = r[i + (j - 2 * N) + 1];
            A3 = r[(i - 2) + j + 1];
            A5 = r[i + j + 1];
            A7 = r[(i + 2) + j + 1];
            A9 = r[i + (j + 2 * N) + 1];
            G2 = g[i + (j - N) + 1];
            G4 = g[(i - 1) + j + 1];
            G6 = g[(i + 1) + j + 1];
            G8 = g[i + (j + N) + 1];
            alpha = abs(-A3 + 2 * A5 - A7) + abs(G4 - G6);
            beta = abs(-A1 + 2 * A5 - A9) + abs(G2 - G8);
            //finding G5
            if (alpha < beta)
                G5 = (G4 + G6) / 2 + (-A3 + 2*A5 - A7) / 2;

            else if(alpha > beta)
                G5 = (G2 + G8) / 2 + (-A1 + 2*A5 - A9) / 2;
            
            else if(alpha == beta)
                G5 = (G2+ G4 + G6 + G8)/4 +  (-A1 - A3 + 4*A5 - A7 - A9)/8;
            
            g[i+j+1] = G5;
            printf("alpha val=%d\n",alpha);
            printf("beta value=%d\n",beta);
            printf("G5=%d\n",G5);
        }
    }

    return 0;
}