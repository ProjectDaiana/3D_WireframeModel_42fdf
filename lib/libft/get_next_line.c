#include "libft.h"

static size_t ft_spec_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_spec_strjoin(char *str1, char *str2)
{
	int i;
	char *newstr;

	i = 0;
	newstr = malloc(ft_spec_strlen(str1) + ft_spec_strlen(str2) + 1);
	if (!newstr)
		return (NULL);
	while (str1 && str1[i])
	{
		newstr[i] = str1[i];
		i++;
	}
	free(str1);
	while (*str2)
	{
		newstr[i++] = *str2;
		if (*str2++ == '\n')
			break;
	}
	newstr[i] = '\0';
	return (newstr);
}

static int shift_buff(char *buff)
{
	int old_index;
	int end_of_line;
	int new_index;

	old_index = 0;
	new_index = 0;
	end_of_line = 0;
	while (buff[old_index])
	{
		if (end_of_line)
			buff[new_index++] = buff[old_index];
		if (buff[old_index] == '\n')
			end_of_line = 1;
		buff[old_index++] = '\0';
	}
	return (end_of_line);
}

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1];
	char *line;

	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd < 0 )
	{
		buff[0] = '\0';
		return (NULL);
	}
	while (*buff != '\0' || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_spec_strjoin(line, buff);
		if (shift_buff(buff))
			break;
	}
	return (line);
}