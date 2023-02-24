#include "libft.h"

static int	ft_dif(size_t len1, size_t len2)
{
	if (len1 < len2)
		return (len1);
	else
		return (len2);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (str == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * ft_dif(len, ft_strlen(str)) + 1);
	if (ret == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && str[i] && i < ft_strlen(str))
	{
		ret[j] = str[i];
		++j;
		++i;
	}
	ret[j] = '\0';
	return (ret);
}
