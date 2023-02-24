#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!(str == NULL))
		write(fd, str, ft_strlen(str));
}
