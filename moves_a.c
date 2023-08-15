#include <push_swap.h>

t_stack sa(stack_a)
{
    if(stack_a[1] > stack_a[0] > stack_a[2])
        int temp = stack_a[0];
        stack_a[0] = stack_a[1];
        stack_a[1] = temp;
}