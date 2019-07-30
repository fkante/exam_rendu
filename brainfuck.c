#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2048
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	brainfuck(char *av)
{
	int	i;
	int	loop;
	char	*ptr;

	i = 0;
	loop = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return ;
	while (i <= BUFF_SIZE)
		ptr[i++] = '\0';
	i = 0;
	while (av[i])
	{
		av[i] == '<' ? ptr = ptr + 1 : ptr;
		av[i] == '>' ? ptr = ptr - 1 : ptr;
		av[i] == '+' ? *ptr = *ptr + 1 : *ptr;
		av[i] == '-' ? *ptr = *ptr - 1 : *ptr;
		if (av[i] == '.')
			ft_putchar(*ptr);
		if (av[i] == '[' && !*ptr)
		{
			loop = 1;
			while(loop)
			{
				i++;
				av[i] == '[' ? loop = loop + 1 : loop;
				av[i] == ']' ? loop = loop - 1 : loop;
			}
		}
		if (av[i] == ']' && *ptr)
		{
			loop = 1;
			while (loop)
			{
				i--;
				av[i] == '[' ? loop = loop - 1 : loop;
				av[i] == ']' ? loop = loop + 1 : loop;
			}
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		ft_putchar('\n');
	return (0);
}
