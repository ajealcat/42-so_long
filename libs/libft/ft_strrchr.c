#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t			size;

	size = ft_strlen(str);
	if (!str)
		return (NULL);
	while (size + 1)
	{
		if (str[size] == (char)c)
			return ((char *)(str + size));
		--size;
	}
	return (NULL);
}
