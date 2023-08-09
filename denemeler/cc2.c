int main()
{
    typedef struct s_stack
    {
	int				data;
	struct s_stack	*next;
    }				t_stack;
    
    t_stack *stacks;

	stacks = malloc(sizeof(t_stack) * 2);
    stacks[0].data = 1;
	fun(stacks[0])
    return 0;
}
