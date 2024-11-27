/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:18:21 by juportie          #+#    #+#             */
/*   Updated: 2024/11/26 12:13:06 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	#include <stdio.h>
char	*get_next_line(int fd)
{
	char	*buffer;
	char	*stock_buffer;
	ssize_t	stock_len;

	if (fd < 0)
		return (NULL);
	buffer = NULL;
	stock_buffer = NULL;
	stock_len = 0;
	printf("%zu\n", fill_buffers(buffer, stock_buffer));
	return (buffer);
}













#include <fcntl.h>
int	main(void)
//int	main(int argc, char *argv[])
{
//	if (argc)
	int	fd = open("lorem_ipsum.txt", O_RDONLY);
	ssize_t	i = 0;
	//char	*str = malloc(10);
	//read(fd, str, 10);
	//write(1, str, 10);
	while (i++ < 5)
		get_next_line(fd);
	return (0);
}
//char	*get_next_line(int fd)
//{
//	int	char_read;
//	ssize_t	line_len;
//	char	*buffer;
//
//	if (fd < 0)
//		return (NULL);
//	line_len = 0;
//	buffer = cat_line(line_len, NULL);
//	if (buffer == NULL)
//		return (NULL);
//	while (buffer[line_len] != '\n')
//	{
//		buffer = cat_line(line_len, buffer);
//		if (buffer == NULL)
//			return (NULL);
//		char_read = read(fd, buffer + line_len, 1);
//		if (char_read == 0)
//		{
//			buffer[line_len + 1] = '\0';
//			return (buffer);
//		}
//		else if (char_read == -1)
//		{
//			free(buffer);
//			return (NULL);
//		}
//		line_len += char_read;
//	}
//	return (buffer);
//}
