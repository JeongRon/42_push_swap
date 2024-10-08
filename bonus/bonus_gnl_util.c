/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_gnl_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:20:21 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/29 19:34:54 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*temp;
	int		i;

	src_len = ft_strlen(src);
	temp = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	free_all(char *a, char *b)
{
	free(a);
	free(b);
}

int	ft_linelen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *buff, char *tmp, int tmp_len)
{
	char	*join_buff;
	int		buff_len;
	int		i;

	buff_len = ft_strlen(buff);
	join_buff = (char *)malloc(sizeof(char) * (buff_len + tmp_len + 1));
	if (!join_buff)
		return (NULL);
	i = 0;
	while (i < buff_len)
	{
		join_buff[i] = buff[i];
		i++;
	}	
	i = 0;
	while (i < tmp_len)
	{
		join_buff[buff_len + i] = tmp[i];
		i++;
	}
	join_buff[buff_len + i] = '\0';
	free(buff);
	return (join_buff);
}
