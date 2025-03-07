#include "parser.h"

static char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*readmore(char *located, int fd, int *readed)
{
	char	*buffer;
	char	*tmp;

	*readed = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&located));
	buffer[0] = '\0';
	while (*readed > 0 && !ft_strchr(buffer, '\n'))
	{
		*readed = read(fd, buffer, BUFFER_SIZE);
		if (*readed > 0)
		{
			buffer[*readed] = '\0';
			tmp = ft_strjoin(located, buffer);
			free(located);
			located = tmp;
		}
		else if (*readed == 0)
			return (ft_free(&buffer), ft_free(&located));
	}
	ft_free(&buffer);
	if (*readed == -1)
		return (ft_free(&located));
	return (located);
}

static char	*ft_full_line(char *located)
{
	char	*ptr;
	size_t	len;
	char	*full_line;

	ptr = ft_strchr(located, '\n');
	len = (ptr - located) + 1;
	full_line = ft_substr(located, 0, len);
	if (!full_line)
		return (NULL);
	return (full_line);
}

static char	*clean_locate(char *located)
{
	char	*ptr;
	char	*new_locate;
	size_t	len;

	ptr = ft_strchr(located, '\n');
	if (!ptr)
	{
		new_locate = NULL;
		return (ft_free(&located));
	}
	else
	{
		len = (ptr - located) + 1;
		new_locate = ft_substr(located, len, ft_strlen(located));
		ft_free(&located);
	}
	return (new_locate);
}

char	*get_next_line(int fd)
{
	static char	*located;
	char		*line;
	int			readed;

	readed = 1;
	if (!located)
		located = ft_strdup("");
	if (fd < 0)
		return (NULL);
	if (!located || (located && !ft_strchr(located, '\n')))
		located = readmore(located, fd, &readed);
	if (!located)
		return (NULL);
	line = ft_full_line(located);
	if (!line)
		return (ft_free(&located));
	located = clean_locate(located);
	return (line);
}
