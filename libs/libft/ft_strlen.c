#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char *p;

	p = str;
	while (*str)
		++str;
	return (str - p);
}
