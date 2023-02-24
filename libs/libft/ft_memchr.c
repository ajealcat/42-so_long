#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	tmp_c;
	size_t			i;

	tmp_src = (unsigned char *)src;
	tmp_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (tmp_src[i] == tmp_c)
			return (tmp_src + i);
		i++;
	}
	return (NULL);
}
