#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	f_exit(void)
{
	write(2, "Error", 6);
	exit(-1);
}

void	space_or_empty_check(char	**av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (!(av[i][j]))
			f_exit();
		while (av[i][j] && (av[i][j] == 32 
		|| (av[i][j] >= 9 && av[i][j] <= 13)))
		{
			if (av[i][j + 1] == '\0')
				f_exit();
			j++;
		}
		i++;
	}
}

void	diff_char_check(char	**av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	space_or_empty_check(av);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (av[i][j + 1] == '\0' 
					|| (!(av[i][j + 1] >= '0' && av[i][j + 1] <= '9')))
					f_exit();
			}
			else if (!(av[i][j] >= '0' && av[i][j] <= '9') 
				&& !(av[i][j] == 32 || (av[i][j] >= 9 && av[i][j] <= 13)))
				f_exit();
			j++;
		}
		i++;
	}
}

int main()
{
    char *av[] = {" 1  3", "  1",0};
   diff_char_check(av);
}