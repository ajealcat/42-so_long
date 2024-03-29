#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	unsigned char	tmp_c;
	size_t			i;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	tmp_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		if (tmp_src[i] == tmp_c)
		{
			tmp_dest[i] = tmp_src[i];
			return (tmp_dest + i + 1);
		}
		++i;
	}	
	return (NULL);
}
