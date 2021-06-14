/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:25:05 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 15:36:07 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <commons.h>
typedef enum e_rettype
{
	SUCCESS,
	FAILURE
}							t_rettype;
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	quicksort(double *tab, size_t size, int rev);
void	ft_putstr_fd(int fd, char const *s);
long	ft_atol(const char *str);
char	*ft_itoa(int n);
char	*ft_strcpy(char *s1, const char *s2);
int		ft_strfind(char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		isnumber(char *str);
int		nbrlen(long nbr);
char	*ft_strjoin(int nb_str, ...);
void	ft_strdel(char **as);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr(int n);
#endif
