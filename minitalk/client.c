/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:30:23 by romartin          #+#    #+#             */
/*   Updated: 2023/03/31 18:38:06 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig(int code)
{
	char		c;
	static int	nb_bit;
	static int	i;

	if (code == SIGUSR1)
		i |= (0x01 << nb_bit);
	nb_bit++;
	if (nb_bit == 8)
	{
		c = i;
		write(1, &c, 1);
		if (c == '\0')
			exit(0);
		nb_bit = 0;
		i = 0;
	}
}

void	ft_binaire(char c, int pid)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(30);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		signal(SIGUSR1, &sig);
		signal(SIGUSR2, &sig);
		while (av[2][i])
		{
			ft_binaire(av[2][i], pid);
			i++;
		}
		ft_binaire('\n', pid);
		while (1)
			pause();
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
