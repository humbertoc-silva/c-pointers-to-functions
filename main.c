#include <stdio.h>

int sum(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);
int calc(int, int, int (*)(int, int));

int main(int argc, char const *argv[])
{

    /* operations is an array of pointers to functions that receive two integers and return an integer */
    int (*operations[4])(int, int) = { &sum, &sub, &mul, &div };

    for (int i = 0; i < 4; i++) {
        /* the result will change according to the operation used by calc function */
        printf("Result: %d.\n", calc(10, 5, operations[i]));
    }

    return 0;    
}

/* sum: sum two integral numbers. */
int sum( int x, int y)
{
    return x + y;
}

/* sub: subtracts two integral numbers. */
int sub(int x, int y)
{
    return x - y;
}

/* mul: multiplies two integral numbers. */
int mul(int x, int y)
{
    return x * y;
}

/* div: divides two integral numbers. */
int div(int x, int y)
{
    return x / y;
}

/* calc: receives two integral numbers and returns an integral number that is the result of the supplied operation. */
int calc(int x, int y, int (*operation)(int, int))
{
    return (*operation)(x, y);
}
