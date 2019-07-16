/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:12:01 by fkante            #+#    #+#             */
/*   Updated: 2019/07/15 14:15:32 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	dec_to_hexa(int dec_nbr)
{
	int		i;
	int		hex_nbr;

	i = 16;
	if (dec_nbr < 10)
		ft_putchar(dec_nbr + '0');
	else if (dec_nbr < 16)
		ft_putchar(dec_nbr + 'W');
	else
	{
		dec_to_hexa(dec_nbr / 16);
		dec_to_hexa(dec_nbr % 16);
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < (size*2))
	{
		if ((i % 16) == 0)
			dec_to_hexa(((int*)addr)[i]);
		ft_putchar(' ');
		if ((++i % 32) == 0)
			ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	int		tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

	print_memory(tab, sizeof(tab));

	return (0);
}
