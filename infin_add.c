
#include <stdlib.h>
#include <stdio.h>
#define max(a, b)  a > b ? a : b


int     parseInt(char c){
    return (c - '0');
}

void    b0(char *str, int size) {
    int i = 0;
    while (i < size) {
        str[i] = '\0';
        i++;
    }
}

int     strl(char *str){
    int     index;

    index = 0;
    while (str[index])
        index++;
    return (index);
}

char    *sub(char *a, char *b){
    if (*a == '-') a++;
    if (*b == '-') b++;
    int     lenA = strl(a);
    int     lenB = strl(b);
    int     lenRet = max(lenA, lenB);
    char    *ret = malloc(lenRet * sizeof(char) + 1);
    int     carry = 0;

}

char    *add(char *a, char *b){
    if (*a == '-') a++;
    if (*b == '-') b++;
    
    int     lenA = strl(a);
    int     lenB = strl(b);
    int     lenRet = max(lenA, lenB) + 1;
    char    *ret = malloc(lenRet * sizeof(char) + 1);
    int     carry = 0;
    
    b0(ret, lenRet + 1);
    for (int    i = lenA - 1,
                j = lenB - 1;
                i >= 0 || j >= 0;   i--, j--) {
        int temp = carry;
        temp += i < 0 ? 0 : parseInt(a[i]);
        temp += j < 0 ? 0 : parseInt(b[j]);
        if (temp > 10)
        {
            carry = temp / 10;
            temp = temp % 10;
        }
        else 
            carry = 0;
        ret[--lenRet] = '0' + temp;
    }
    if (carry)
        ret[--lenRet] = carry + '0';
    else 
        ret++;
    return (ret);
}

int     main(int ac, char **av) {
    if (ac != 3)
        return (0);
    int isANeg = 0, isBNeg = 0;
    if (av[1][0] == '-')
        isANeg = 1;
    if (av[2][0] == '-') 
        isBNeg = 1;
    char *ret = add(av[1], av[2]);
    printf("%s\n", ret);
    return (0);
}