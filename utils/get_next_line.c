/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:42:31 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/09 15:31:19 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_struct_lign(int fd, char *str_final)
{
	char	*str_lign;
	int		fp;

	fp = 1;
	str_lign = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_lign)
		return (NULL);
	while ((ft_find(str_final) <= 0) && fp)
	{
		fp = read(fd, str_lign, BUFFER_SIZE);
		if (fp == -1)
		{
			free(str_lign);
			return (NULL);
		}
		str_lign[fp] = '\0';
		str_final = ft_strjoin(str_final, str_lign);
	}
	free(str_lign);
	return (str_final);
}

char	*get_next_line(int fd)
{
	static char	*str_final = NULL;
	char		*str_back;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	str_final = ft_struct_lign(fd, str_final);
	if (!str_final)
	{
		free(str_final);
		return (NULL);
	}
	str_back = ft_print_lign(str_final);
	str_final = ft_memory_lign(str_final);
	return (str_back);
}
