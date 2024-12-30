/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:49:16 by ccalabro          #+#    #+#             */
/*   Updated: 2024/12/30 16:49:17 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join(char *s3, char *s1, char *s2);
char	*str_to_print(char *str);
char	*clean_static(char *str);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);
int		ft_endcmp(char *s1, char *end);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_puthex(unsigned long n, char format);
int		ft_putaddress(void *p);
int		ft_putunsigned(unsigned int n);

#endif
