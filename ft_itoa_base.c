#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	const char	*base_str;
	char	*ptr;
	int		nb;
	int		len;

	if (value == 0)
		return (0);
	base_str = "0123456789ABCDEF";
	len = 0;
	nb = value;
	while (nb)
	{
		nb = nb / base;
		len++;
	}
	nb = value;
	if (nb < 0)
	{
		if (base == 10)
			len++;
		nb = -nb;
	}
	if (!(ptr = (char*)malloc(sizeof(char) *len + 1)))
		return (NULL);
	ptr[len] = '\0';
	while (nb)
	{
		ptr[--len] = base_str[nb % base];
		nb = nb / base;
	}
	if (value < 0 && base == 10)
		ptr[0] = '-';
	return (ptr);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	printf("base: %s\nitoa: %s\n", av[2], ft_itoa_base(atoi(av[1]), atoi(av[2])));
	return (0);
}
