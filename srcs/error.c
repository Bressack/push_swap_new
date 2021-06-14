/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:30:39 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 15:53:00 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>

//			'd' -> int
//			's' -> string
void		print_things(int fd, int nb_things, ...)
{
	va_list	ap;
	char	opt;
	int		val_d;
	char	*val_s;

	va_start(ap, nb_things);
	while (nb_things)
	{
		opt = va_arg(ap, int);
		if (opt == 'd')
		{
			val_d = va_arg(ap, int);
			ft_putnbr(val_d);
		}
		else if (opt == 's')
		{
			val_s = va_arg(ap, char *);
			write(fd, val_s, ft_strlen(val_s));
		}
		nb_things--;
	}
}

int	error(char *bin, enum e_errortype type, char *msg, char *arg) // TOOLONG
{
	static int nb_error = 0;
	static int nb_warn = 0;

	if (type == RESET)
	{
		nb_error = 0;
		nb_warn = 0;
		return (SUCCESS);
	}
	else if (type == CHECK)
	{
		if (nb_error)
			return (FAILURE);
		return (SUCCESS);
	}
	else if (type == COUNT)
	{
		if (nb_error)
			print_things(2, 2, 'd', nb_error, 's', "error(s) generated.\n");
		if (nb_warn)
			print_things(2, 2, 'd', nb_warn, 's', "warning(s) generated.\n");
		return (SUCCESS);
	}
	print_things(2, 3, 's', C_G_GREY, 's', bin, 's', ": "C_RES);
	if (type == ERR)
	{
		print_things(2, 1, 's', ""C_G_RED"error: "C_RES);
		nb_error++;
	}
	if (type == FATALERR)
	{
		print_things(2, 1, 's', ""C_G_RED"fatal error: "C_RES);
		nb_error++;
	}
	if (type == WARN)
	{
		print_things(2, 1, 's', ""C_G_MAGENTA"warning: "C_RES);
		nb_warn++;
	}
	if (type == INFO)
		print_things(2, 1, 's', ""C_G_GREY"info: "C_RES);
	print_things(2, 3, 's', C_G_WHITE, 's', msg, 's', C_RES);
	if (arg)
		print_things(2, 3, 's', ""C_G_WHITE" \'"C_G_GREY, 's', arg, 's', C_G_WHITE"\'"C_RES);
	print_things(2, 1, 's', "\n");
	if (type == ERR)
		return (1);
	if (type == FATALERR)
		exit(-1);
	return (FAILURE);
}
