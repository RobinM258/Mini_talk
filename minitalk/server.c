/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:31:29 by romartin          #+#    #+#             */
/*   Updated: 2023/03/31 18:34:40 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	c;
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = (long)nbr * -1;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	c = nbr % 10 + '0';
	write(fd, &c, 1);
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

void	sig(int code, siginfo_t *kieron, void *useless)
{
	char		*str;
	char		c;
	int			j;
	static int	nb_bit;
	static int	i;

	(void) useless;
	j = 0;
	str = "Message reçu\0";
	if (code == SIGUSR1)
		i |= (0x01 << nb_bit);
	nb_bit++;
	if (nb_bit == 8)
	{
		c = i;
		write(1, &c, 1);
		if (c == '\n')
		{
			while (str[j])
				ft_binaire(str[j++], kieron->si_pid);
			ft_binaire('\0', kieron->si_pid);
		}
		nb_bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int					i;
	struct sigaction	test;

	i = 0;
	test.sa_sigaction = sig;
	sigemptyset(&test.sa_mask);
	test.sa_flags = SA_SIGINFO;
	write(1, "serveur pid ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &test, NULL);
	sigaction(SIGUSR2, &test, NULL);
	while (1)
		pause();
	return (0);
}
