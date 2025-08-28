#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	n;
	char	*dst;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	dst = (char *)malloc(n + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[n] = '\0';
	return (dst);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*dst;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		dst = (char *)malloc(1);
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (len > s_len - start)
		len = s_len - start;
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	n1;
	size_t	n2;
	char	*out;

	n1 = s1 ? ft_strlen(s1) : 0;
	n2 = s2 ? ft_strlen(s2) : 0;
	out = (char *)malloc(n1 + n2 + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < n1)
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < n2)
	{
		out[i + j] = s2[j];
		j++;
	}
	out[n1 + n2] = '\0';
	return (out);
}
