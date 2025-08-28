#include "get_next_line.h"


static void	free_null_ptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static int	handle_nread(int fd, char *buf, char **stash)
{
	ssize_t	nread;
	char	*joined;

	nread = read(fd, buf, BUFFER_SIZE);
	if (nread == 0)
		return (0);
	if (nread < 0)
	{
		free_null_ptr((void **)stash);
		return (-1);
	}
	buf[nread] = '\0';
	if (*stash == NULL)
	{
		*stash = ft_strdup(buf);
		if (*stash == NULL)
			return (-1);
		return (1);
	}
	joined = ft_strjoin(*stash, buf);
	if (joined == NULL)
	{
		free_null_ptr((void **)stash);
		return (-1);
	}
	free(*stash);
	*stash = joined;
	return (1);
}

static ssize_t	fill_until_nl(int fd, char **stash, char *buf)
{
	int	rc;
	while if (!*stash || !ft_strchr(*stash, '\n'))
	{
		rc = handle_nread(fd, buf, stash);
		if (rc <= 0)
			return (rc);
	}
	return (1);
}

static char	*pop_line_from_stash(char **stash)
{
	char	*nl;
	size_t	len_line;
	size_t	len_rest;
	size_t	i;
	char	*line;

	if (!*stash || !**stash)
		return (NULL);
	nl = ft_strchr(*stash, '\n');
	if (nl)
		len_line = (size_t)(nl - *stash) + 1;
	else
		len_line = ft_strlen(*stash);
	line = ft_substr(*stash, 0, len_line);
	if (!line)
		return (NULL);
	len_rest = ft_strlen(*stash + len_line);
	if (len_rest == 0)
		free_null_ptr((void **)stash);
	else
	{
		
		i = 0;
		while (i <= len_rest)
		{
			(*stash)[i] = (*stash)[len_line + i];
			i++;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		rc;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rc = fill_until_nl(fd, &stash, buf);
	if (rc < 0)
		return (NULL);
	if (rc == 0 && (stash == NULL || *stash == '\0'))
		return (NULL);
	return (pop_line_from_stash(&stash));
}