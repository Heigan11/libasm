/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:38:44 by Jraye             #+#    #+#             */
/*   Updated: 2021/02/23 17:43:54 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void		look_write(int fd)
{
	write(1, "\n", 1);
	write(1, "write:", 6);
	write(1, "\n", 1);
	write(1, "hello", 5);
	write(1, "\n", 1);
	ft_write(1, "hello", 5);
	write(1, "\n", 1);
	printf("1 = %zd\n", write(-1, "hello", 5));
	write(1, "\n", 1);
	printf("2 = %zd\n", ft_write(-1, "hello", 5));
	write(1, "\n", 1);
	write(0, "stdout", 6);
	write(1, "\n", 1);
	ft_write(0, "stdout", 6);
	write(1, "\n", 1);
	write(fd, "stdout", 6);
	write(1, "\n", 1);
	ft_write(fd, "stdout", 6);
}

void		look_read_strdup(int fd)
{
	char	buf[100];
	char	*str6;

	write(1, "\n", 1);
	write(1, "read:", 5);
	write(1, "\n", 1);
	read(fd, buf, 20);
	printf("read fd = %zd\n", read(fd, buf, 20));
	printf("ft_read fd = %zd\n", ft_read(fd, buf, 20));
	printf("read 0 = %zd\n", read(0, buf, 20));
	printf("ft_read 0 = %zd\n", ft_read(0, buf, 20));
	printf("read -1 = %zd\n", read(-1, buf, 20));
	printf("ft_read -1 = %zd\n", ft_read(-1, buf, 20));
	str6 = "strduphudfhjfdhiufru990ir3903490fekofklfsklfsklrwi043030o0-2r30-o23rokdekdsklsdlk";
	printf("ft_strdup = %s\n", ft_strdup(str6));
	printf("strdup = %s\n", strdup(str6));
	str6 = "";
	printf("ft_strdup = %s\n", ft_strdup(str6));
	printf("strdup = %s\n", strdup(str6));
}

void		look_strcmp(void)
{
	char	*str;
	char	*str1;

	printf("strcmp = %d\n", strcmp("", ""));
	printf("ft_strcmp = %d\n", ft_strcmp("", ""));
	str = "";
	str1 = "hello";
	printf("strcmp = %d\n", strcmp(str, str1));
	printf("ft_strcmp = %d\n", ft_strcmp(str, str1));
	printf("strcmp = %d\n", strcmp("hello", ""));
	printf("ft_strcmp = %d\n", ft_strcmp("hello", ""));
	str = "\xff";
	str1 = "\xff\xff";
	printf("strcmp = %d\n", strcmp(str, str1));
	printf("ft_strcmp = %d\n", ft_strcmp(str, str1));
	printf("strcmp = %d\n", strcmp("hello", "hello"));
	printf("ft_strcmp = %d\n", ft_strcmp("hello", "hello"));
}

int			main(void)
{
	char	dst[10];
	char	*str;
	char	dst1[10];
	char	*str1;
	int		fd;

	fd = open("alphabet", O_RDONLY);
	printf("strlen = %lu\n", strlen(""));
	printf("ft_strlen.s = %lu\n", ft_strlen(""));
	printf("strlen = %lu\n", strlen("12981237812376812768147681346789147891289 ijhefbsjfbsdbnmfsdnmsdbmnfsdfsf"));
	printf("ft_strlen.s = %lu\n", ft_strlen("12981237812376812768147681346789147891289 ijhefbsjfbsdbnmfsdnmsdbmnfsdfsf"));
	str = "hello";
	strcpy(dst, str);
	printf("strcpy = %s\n", dst);
	ft_strcpy(dst1, str);
	printf("ft_strcpy = %s\n", dst1);
	look_strcmp();
	look_write(fd);
	look_read_strdup(fd);
	close(fd);
	return (0);
}
