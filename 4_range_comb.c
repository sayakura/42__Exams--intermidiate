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

#define DEBUG 1
#if DEBUG
    #include <stdio.h>
    #define PRINT 3 
#endif

#define PUSH 1
#define POP 2
#define CLEAR 0

int     **ret;
int     g_index;
int     max;

int    factorial(int n) {
    int i = n;
    while (--n) 
        i *= n;
    return i;
}

void    arr_op(int *arr, int op, int val) {
    static int p = 0;

    if (op == PUSH)
        arr[p++] = val;
    else if (op == POP)
        p--;
    else if (op == CLEAR)
        p = 0;
#if DEBUG 
    else if (op == PRINT) {

        for (int i = 0; i < max; i++) 
            printf("%d ", arr[i]);
        printf("\n");
    }
#endif
}

void   dfs(int level, int state, int *arr)
{
    if (level != max) {
        for (int i = 0; i < max; i++) {
            if (!(state >> i & 1)) {
                arr_op(arr, PUSH, i);
                dfs(level + 1, state | 1 << i, arr);
                arr_op(arr, POP, i);
            }
        }
    } else
    {
        unsigned int siz = sizeof(int) * max;
        ret[g_index] = malloc(siz);
        memcpy(ret[g_index++], arr, siz);
        arr_op(arr, PRINT, 0);
    }
}

int    **range_comb(int n)
{
    int siz = sizeof(int *) * factorial(n) + 1;
    
    g_index = 0;
    max = n;
    ret = malloc(siz);
    ret[siz - 1] = 0;

    int     *arr = malloc(sizeof(int) * n);
    dfs(0, 0, arr);
    return ret;
}

#if DEBUG 
int     main(int ac, char **av)
{
    range_comb(2);
    printf("-----\n");
    range_comb(3);
    printf("-----\n");
    range_comb(4);
    return (0);
}
#endif
