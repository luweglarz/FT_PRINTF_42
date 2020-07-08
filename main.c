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

    res1 = ft_printf("c : %-*c t\n", 10, 'c');
    res2 = printf("c : %-*c t\n", 10, 'c');
    printf("%d\n", res1);
    printf("%d", res2);
}
