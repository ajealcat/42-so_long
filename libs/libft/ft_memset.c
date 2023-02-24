#include <string.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char *)str;
	while (i < len)
	{
		*tmp = c;
		++i;
		++tmp;
	}
	return (str);
}
