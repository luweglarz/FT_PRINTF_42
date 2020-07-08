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

    res1 = ft_printf("s : %-*s t\n", 10, "test");
    res2 = printf("s : %-10s t\n", "test");
    printf("%d\n", res1);
    printf("%d", res2);
}
