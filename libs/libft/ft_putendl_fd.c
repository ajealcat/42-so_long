#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	if (!(str == NULL))
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
}
