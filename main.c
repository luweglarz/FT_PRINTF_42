#include <stdio.h>
#include "ft_printf.h"
int main()
{
    int hint;
    int res1;
    int res2;

    int  *testint;
    hint = 42;
    testint = &hint;	
	//ft_printf("\\!/%15c\\!/ \n");

    res1 = ft_printf("c : %c\n s : %.*s\n p : %p\n d : %d\n i : %i\n u : %u\n x : %x\n X : %X\n %%\n", 'a', 2, "test", testint, 42, 42, -4211, 532423, 6232);
    res2 = printf("c : %c\n s : %.2s\n p : %p\n d : %d\n i : %i\n u : %u\n x : %x\n X : %X\n %%\n", 'a', "test", testint, 42, 42, -4211, 532423, 6232);
    printf("%d\n", res1);
    printf("%d", res2);
}
