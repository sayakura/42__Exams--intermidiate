/*
RANGE_COMB
Assignment name  : range_comb
Expected files   : range_comb.c
Allowed functions: malloc free memcpy
--------------------------------------------------------------------------------
Implement a function which computes, for a given integer n, all
the possible permutations of the numbers in the range from 0 to
(n - 1) inclusive.
The function returns a null-terminated array.
Your function must be declared as follows:
int    **range_comb(int n);
If n <= 0, the function returns -1;
Examples:
input  = 2
output = {{0, 1}, {1, 0}}
input  = 3
output = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}}
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int     perm(int n)
{
    int size = 1;

    for (int i = 1; i <= n; i++)
        size *= i;
    return (size);
}

void    swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void    add_to_arr(int size, int *A, int **ret)
{
    static int index;

    ret[index] = (int *)malloc(sizeof(int) * size);
    memcpy(ret[index], A, sizeof(int) * size);
    index++;
}

void    heap(int n, int *A, int size, int **ret)
{
    if (n == 1) {
        add_to_arr(size, A, ret);
    } else {
        for (int i = 0; i < (n - 1); i++) {
            heap(n - 1, A, size, ret);
            if (n % 2 == 0)
                swap(&A[i], &A[n - 1]);
            else
                swap(&A[0], &A[n - 1]);
        }
        heap(n - 1, A, size, ret);
    }
}

void    sort(int **ret, int size, int *cmp(int*, int*))
{






}

int    **range_comb(int n)
{
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        arr[i] = i;
    int p = perm(n);
    int **ret = (int **)malloc(sizeof(int *) * (p + 1));
    ret[p] = (int *)(0);
    heap(n, arr, n, ret);

    free(arr);
    return (ret);
}

int     main(int ac, char **av)
{
    int size = 4;
    int **ret = range_comb(size);
    int p = perm(size);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < size; j++)
            printf("%d ", ret[i][j]);
        printf("\n");
    }
    return (0);
}