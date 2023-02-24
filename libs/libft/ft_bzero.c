#include <strings.h>
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		*tmp = '\0';
		++tmp;
		++i;
	}
}
