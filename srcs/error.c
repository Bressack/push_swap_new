/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:30:39 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/12 17:22:00 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>

int		error(char *bin, enum e_errortype type, char *msg, char *arg) // TOOLONG
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
			dprintf(2, "%d error(s) generated.\n", nb_error); // TOFT
		if (nb_warn)
			dprintf(2, "%d warning(s) generated.\n", nb_warn); // TOFT
		return (SUCCESS);
	}
	dprintf(2, ""C_G_GREY"%s: "C_RES, bin);
	if (type == ERR)
	{
		dprintf(2, ""C_G_RED"error: "C_RES""); // TOFT
		nb_error++;
	}
	if (type == FATALERR)
	{
		dprintf(2, ""C_G_RED"fatal error: "C_RES""); // TOFT
		nb_error++;
	}
	if (type == WARN)
	{
		dprintf(2, ""C_G_MAGENTA"warning: "C_RES""); // TOFT
		nb_warn++;
	}
	if (type == INFO)
		dprintf(2, ""C_G_GREY"info:"C_RES""); // TOFT
	dprintf(2, ""C_G_WHITE"%s"C_RES" ", msg); // TOFT
	if (arg)
		dprintf(2, ""C_G_WHITE"\'"C_G_GREY"%s"C_G_WHITE"\'"C_RES, arg);
	dprintf(2, "\n");
	if (type == ERR)
		return (1);
	if (type == FATALERR)
		exit(-1);
	return (FAILURE);
}
