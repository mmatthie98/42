#include "test.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_isn(char	*str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	int	i;
	int	j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = 0;
	}
	if (!s1 || ! s2)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;	
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free (s1);
	return (str);
}

char	*ft_restline(char	*save)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i])
	{
		str = malloc(sizeof(char) * ft_strlen(save) - i + 1);
		if (!str)
			return (NULL);
		j = 0;
		while (save[i])
			str[j++] = save[++i];
		str[j] = 0;
		free (save);
		return (str);
	}
	else
	{
		free (save);
		return (NULL);
	}
}

char	*ft_makeline(char	*save)
{
	int	i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		str = malloc(sizeof(char) * i + 2);
	else
		str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (save[++i] && save[i] != '\n')
		str[i] = save[i];
	if (save[i] == '\n')
	{
		save[i] = '\n';
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_get_next_line(char	**line)
{
	static char	*save;
	char	buf[BUFFER_SIZE + 1];
	int		byte_read;

	if (!line)
		return (1);
	byte_read = 1;
	while (byte_read && !ft_isn(save, '\n'))
	{
		byte_read = read(0, buf, BUFFER_SIZE);
		if (byte_read == -1)
			return (1);
		buf[byte_read] = 0;
		save = ft_strjoin(save, buf);
		if (!save)
			return (1);
	}
	*line = ft_makeline(save);
	save = ft_restline(save);
	return (0);
}


int main()
{
	char	*line;
	int byte_read;

	while ((byte_read = ft_get_next_line(&line)) != -1)
	{
		printf("%s\n", line);
		free (line);
		line = NULL;
	}
	printf("%s\n", line);
	free (line);
	line = NULL;
	return (0);
}