/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:41:10 by juportie          #+#    #+#             */
/*   Updated: 2024/11/27 14:00:54 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//ssize_t	fill_buffer(char *buffer)
//{
//	if (buffer == NULL)
//		return (-1);
//	return (read(fd, stock_buffer, BUFFER_SIZE));
//}
//
ssize_t	fill_buffers(char *buffer, char *stock_buffer)
{
	static ssize_t	stock_len;
	static ssize_t	line_len;

	if (stock_len == 0)
	{
		free(stock_buffer);
		stock_buffer = malloc(sizeof(char) * BUFFER_SIZE);
		if (stock_buffer == NULL)
			return (stock_len = -1);
		stock_len = read(fd, stock_buffer, BUFFER_SIZE);
	}
	while (line_len < BUFFER_SIZE)
	{
		if (stock_buffer[line_len == '\n')
			return (stock_buffer);
		line_len++;
	}
	// create and fill buffer with line len
	return (stock_len);
}
	
















static char	*create_buffer(char *buffer)
{
	char	*new_buffer;

	new_buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (new_buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	return (new_buffer);
}

char	*cat_line(char *buffer)
{
	char	*new_buffer;
	ssize_t	i;

	i = 0;
	new_buffer = create_buffer(buffer);
	if (new_buffer == NULL)
		return (NULL);
	if (buffer)
	{
		while (buffer[i])
		{
			new_buffer[i] = buffer[i];
			i++;
		}
		free(buffer);
	}
	return (new_buffer);
}
//char	*cat_line(ssize_t line_len, char *buffer)
//{
//	char	*new_buffer;
//	ssize_t	i;
//
//	i = 0;
//	new_buffer = create_buffer(buffer);
//	if (new_buffer == NULL)
//		return (NULL);
//	if (buffer)
//	{
//		while (buffer[i])
//		{
//			new_buffer[i] = buffer[i];
//			i++;
//		}
//		free(buffer);
//	}
//	return (new_buffer);
//}
//static char	*create_buffer(ssize_t line_len, char *buffer)
//{
//	char	*new_buffer;
//	ssize_t	malloc_size;
//
//	if (buffer)
//		malloc_size = line_len + 1;
//	else if (line_len == 0)
//		malloc_size = 1;
//	else
//	{
//		free(buffer);
//		return (NULL);
//	}
//	new_buffer = malloc(sizeof(char) * malloc_size);
//	if (new_buffer == NULL)
//	{
//		free(buffer);
//		return (NULL);
//	}
//	new_buffer[line_len] = '\0';
//	return (new_buffer);
//}
