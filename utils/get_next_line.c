#include "utils.h"

char	*str_to_print(char *str)
{
	int		i;
	char	*line;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	i = 0;
	if (ft_strchr(str, '\n'))
		while (str[i] != '\n')
			i++;
	else
		i = ft_strlen(str);
	line = (char *)malloc((i + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clean_static(char *str)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	else if (str[i] == '\n')
		i++;
	buf = (char *)malloc(ft_strlen(str) + 1 - i);
	if (buf == NULL)
		return (NULL);
	while (str[i + j] != '\0')
	{
		buf[j] = str[i + j];
		j++;
	}
	buf[j] = '\0';
	free(str);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*line;
	int				read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(str, '\0') && read_size > 0)
	{
		read_size = read(fd, line, BUFFER_SIZE);
		if (read_size == -1)
			return (free(line), NULL);
		line[read_size] = '\0';
		str = ft_strjoin(str, line);
	}
	if (!str)
		return (free(line), NULL);
	free(line);
	line = str_to_print(str);
	str = clean_static(str);
	return (line);
}
