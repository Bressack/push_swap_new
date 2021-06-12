/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:56:08 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/12 17:13:44 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static t_str	*creat_new_node(const int fd, char *buf, t_str **sstr)
{
	t_str			*new_node;

	new_node = try_malloc(sizeof(t_str));
	new_node->fd = fd;
	new_node->str = ft_strdup(buf);
	new_node->next = *sstr;
	*sstr = new_node;
	return (new_node);
}

static t_str	*check_fd_node(const int fd, t_str *sstr)
{
	while (sstr)
	{
		if (sstr->fd == fd)
			return (sstr);
		sstr = sstr->next;
	}
	return (NULL);
}

static int	check_node(const int fd, char *buff, t_str **sstr)
{
	t_str			*node;
	char			*tmp;

	node = check_fd_node(fd, *sstr);
	if (!node)
		node = creat_new_node(fd, buff, sstr);
	else
	{
		tmp = ft_strjoin(2, node->str, buff);
		ft_strdel(&node->str);
		node->str = tmp;
	}
	if (ft_strfind(node->str, '\n') != -1)
		return (1);
	return (0);
}

static char	*find_newline(const int fd, t_str *sstr)
{
	t_str			*node;
	char			*tmp;
	char			*ret_line;
	int				ret;

	ret_line = NULL;
	node = check_fd_node(fd, sstr);
	if (!node || !node->str)
		return (NULL);
	ret = ft_strfind(node->str, '\n');
	if (ret != -1)
	{
		ret_line = ft_strsub(node->str, 0, ret);
		tmp = ft_strdup(node->str + ret + 1);
		ft_strdel(&node->str);
		node->str = tmp;
	}
	else
	{
		if (ft_strlen(node->str) != 0)
			ret_line = ft_strdup(node->str);
		ft_strdel(&node->str);
	}
	return (ret_line);
}

int	get_next_line(const int fd, char **line)
{
	static t_str	*sstr;
	char			buf[BUFF_SIZE_GNL + 1];
	int				ret;
	int				back;

	if (*line)
		ft_strdel(line);
	if (fd < 0 || (!(line)) || BUFF_SIZE_GNL < 1)
		return (-1);
	while (1)
	{
		ret = read(fd, buf, BUFF_SIZE_GNL);
		if (ret < 0)
			return (-1);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		back = check_node(fd, buf, &sstr);
		if (back == 1)
			return (((long)(*line = find_newline(fd, sstr))) * 0 + 1);
		if (back == -1)
			return (-1);
	}
	*line = find_newline(fd, sstr);
	return (*line != NULL);
}
