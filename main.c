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
    res2 = printf("real printf c : %-2.2s\n", "abc");
    res1 = ft_printf("myyy printf c : %-2.2s\n", "abc");

    printf("%d\n", res1);
    printf("%d", res2);
}
