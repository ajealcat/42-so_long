#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (src == NULL)
		return (0);
	while (src[len])
		++len;
	if (dest_size == 0)
		return (len);
	while (src[i] && (i < dest_size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (len);
}
