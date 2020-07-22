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
	//ft_printf("\\!/%15c\\!/ \n", 'c');
    //res2 = printf("myyy printf c : %%-.00s \n", "hi low");
    res1 = ft_printf("%.0p\n", 0);

    printf("%d\n", res1);
    printf("%d", res2);
}
