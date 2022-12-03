/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:51:55 by znaoui            #+#    #+#             */
/*   Updated: 2022/05/09 15:31:24 by znaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_find(const char *str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strjoin(char *str_final, char *str_lign)
{
	char	*str_join;
	int		i;
	int		x;

	i = -1;
	x = 0;
	if (!str_final)
	{
		str_final = (char *)malloc(sizeof(char) * 1);
		str_final[0] = '\0';
	}
	if (!str_final || !str_lign)
		return (NULL);
	str_join = (char *)malloc(sizeof(char)
			* (ft_strlen(str_final) + ft_strlen(str_lign) + 1));
	if (!str_join)
		return (NULL);
	while (str_final[++i])
		str_join[i] = str_final[i];
	while (str_lign[x])
		str_join[i++] = str_lign[x++];
	str_join[i] = '\0';
	free(str_final);
	return (str_join);
}

char	*ft_print_lign(char *str_final)
{
	char	*str_print;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str_final[i])
		return (NULL);
	while (str_final[len] && str_final[len] != '\n')
		len++;
	str_print = (char *)malloc(sizeof(char) * (len + 2));
	if (!str_print)
		return (NULL);
	while (str_final[i] && str_final[i] != '\n')
	{
		str_print[i] = str_final[i];
		i++;
	}
	if (str_final[i] == '\n')
	{
		str_print[i] = str_final[i];
		i++;
	}
	str_print[i] = '\0';
	return (str_print);
}

char	*ft_memory_lign(char *str_final)
{
	char	*str_memory;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str_final[len] && str_final[len] != '\n')
		len++;
	if (!str_final[len])
	{
		free(str_final);
		return (NULL);
	}
	str_memory = (char *)malloc(sizeof(char) * (ft_strlen(str_final) - len));
	if (!str_memory)
		return (NULL);
	len += 1;
	while (str_final[len])
		str_memory[i++] = str_final[len++];
	str_memory[i] = '\0';
	free(str_final);
	return (str_memory);
}
