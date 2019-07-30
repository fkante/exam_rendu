#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_hex(int octet, int rem)
{
	const char *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, base + (octet % 16), 1);
}

void	sp_putchar(unsigned char const *ptr)
{
	char const c = *ptr;

	if (' ' <= c && c <= '~')
		write(1, ptr, 1);
	else
		write(1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t i;
	size_t j;
	u_int8_t *ptr = addr;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16 && j + i < size)
		{
			ft_putnbr_hex(*(ptr + i + j), 2);
			if (j % 2)
				ft_putchar(' ');
			j++;
		}
		while (j < 16)
		{
			ft_putchar(' ');
			ft_putchar(' ');
			if (j % 2)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		while (j < 16 && j + i < size)
		{
			sp_putchar(ptr + j + i);
			j++;
		}
		ft_putchar('\n');
		i += 16;
	}
}

int		main(int ac, char **av)
{
	int		tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

	print_memory(tab, sizeof(tab));

	return (0);
}

