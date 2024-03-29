#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		src_size;
	size_t		dest_size;

	i = 0;
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (size < dest_size)
		return (src_size + size);
	while (src[i] && (dest_size < size - 1))
	{
		dest[dest_size] = src[i];
		++i;
		++dest_size;
	}
	dest[dest_size] = '\0';
	return ((dest_size - i) + src_size);
}
