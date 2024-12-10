/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:41:10 by juportie          #+#    #+#             */
/*   Updated: 2024/11/28 13:14:49 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	ft_strlen(char *s)
{
	ssize_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*malloc_cat(
	char *buffer, ssize_t *nl_pos, ssize_t line_len, ssize_t *len, ssize_t read_ret
)
{
	char	*cat;

	if (*nl_pos == -1)
		*nl_pos = 0;
	*len = get_line_len(buffer + *nl_pos, read_ret - *nl_pos);
	if (*len == -1)
		*len = read_ret - *nl_pos;
	cat = malloc(sizeof(char) * (line_len + *len + 1));
	return (cat);
}

char	*ft_cat(char *line, char *buffer, ssize_t nl_pos, ssize_t read_ret)
{
	ssize_t	line_len;
	char	*cat;
	ssize_t	i;
	ssize_t	len;

	line_len = ft_strlen(line);
	cat = malloc_cat(buffer, &nl_pos, line_len, &len, read_ret);
	if (cat == NULL)
	{
		free(line);
		return (NULL);
	}
	i = -1;
	while (++i < line_len)
		cat[i] = line[i];
	free(line);
	while (i < line_len + len)
	{
		cat[i] = buffer[i - line_len + nl_pos];
		i++;
	}
	cat[i] = '\0';
	return (cat);
}

// The argument max_len is here to secure the reading,
// because neither the buffer or the file are true strings.
// The file can contain '\0' too (but why doing that ?).
ssize_t	get_line_len(char *buffer, ssize_t max_len)
{
	ssize_t	i;

	i = 0;
	while (i <= max_len)
	{
		i++;
		if (buffer[i - 1] == '\n')
			return (i);
	}
	return (-1);
}
