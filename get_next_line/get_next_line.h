/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:00:47 by tquintan          #+#    #+#             */
/*   Updated: 2021/03/04 12:41:25 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen1(const char *str);
int		ft_strchr1(const char *str);
char	*ft_strjoin1(char *s1, char *s2);
int		get_next_line(int fd, char **line);
char	*ft_substr1(char const *s, unsigned int start, size_t len);
#endif
