/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:40:30 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/06/27 22:40:42 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	char	c;
	ssize_t	count;

	count = 0;
	if (n == INT_MIN)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	count += write(fd, &c, 1);
	return (count);
}

// int	main(void)
// {
// 	int fd = open("text.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		perror("file not opened");
// 		return (1);
// 	}
// 	ft_putnbr_fd(0, fd);
// 	char buff[SIZE];
// 	lseek(fd, 0, SEEK_SET);
// 	size_t size = read(0fd, buff, sizeof(buff) - 1);
// 	buff[size] = '\0';
// 	printf("%s", buff);
// 	close(fd);
// 	return (0);
// }
