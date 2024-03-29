#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, len);
	if (dest > src)
	{
		while (len--)
			tmp_dest[len] = tmp_src[len];
	}
	return (dest);
}
