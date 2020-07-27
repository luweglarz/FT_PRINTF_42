#include <stdio.h>
#include "ft_printf.h"
int main()
{
    int res1;
    int res2;
	//ft_printf("\\!/%15c\\!/ \n", 'c');
    //res2 = printf("myyy printf c : %%-.00s \n", "hi low");
    //ft_printf("%d");
    res1 = printf("%0-8.5dt\n", -2147483648);
    res2 = ft_printf("%0-8.5dt\n", -2147483648);
   printf("%d\n", res1);
    printf("%d", res2);
}
