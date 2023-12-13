//20301125


#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    n = 5; // Number of processes
    m = 4; // Number of resources

    int alloc[5][4] = {
        {0, 1, 0, 3}, // P0 // Allocation Matrix
        {2, 0, 0, 0}, // P1
        {3, 0, 2, 0}, // P2
        {2, 1, 1, 5}, // P3
        {0, 0, 2, 2}  // P4
    };

    int max[5][4] = {
        {6, 4, 3, 4}, // P0 // MAX Matrix
        {3, 2, 2, 1}, // P1
        {9, 1, 2, 6}, // P2
        {2, 2, 2, 8}, // P3
        {4, 3, 3, 7}  // P4
    };

    int avail[4] = {3, 3, 2, 1}; // Available Resources

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }

                if (flag == 1) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int deadlock = 0;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            deadlock = 1;
            printf("Deadlock Ahead\n");
            break;
        }
    }

    if (deadlock == 0) {
        printf("Safe here\n");
    }

    return 0;
}
