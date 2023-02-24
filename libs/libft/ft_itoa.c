#include "libft.h"

static int	ft_div(long nbr)
{
	int	count;

	count = 1;
	if (nbr == 0)
		return (2);
	if (nbr < 0)
	{
		nbr *= -1;
		++count;
	}
	while (nbr)
	{
		nbr /= 10;
		++count;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	long int	nb;
	size_t		value;
	char		*ret;

	nb = nbr;
	value = ft_div(nb);
	ret = (char *)malloc(sizeof(char) * value);
	if (!ret)
		return (NULL);
	if (nb < 0)
	{
		ret[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		ret[0] = 48;
	--value;
	ret[value] = '\0';
	while (nb)
	{
		ret[value - 1] = (nb % 10) + 48;
		nb = nb / 10;
		--value;
	}
	return (ret);
}
