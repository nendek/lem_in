
#include "libft.h"

char	*ft_strndup(const char *s, int start, int end)
{
	char 	*dest;

	if (s)
	{
		if (!(dest = ft_strnew(end)))
			return (0);
		while (end >= 0)
		{
			dest[start] = s[start];
			start++;
			end--;
		}
		dest[start] = '\0';
		return (dest);
	}
	return (NULL);
}
