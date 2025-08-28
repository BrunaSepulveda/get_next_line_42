
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>  
# include <stdlib.h>  
# include <limits.h>
#include <stddef.h> 

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

typedef struct s_lineinfo
{
	char	*line;      
	size_t	len_line;   
}	t_lineinfo;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int arg);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t count);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
