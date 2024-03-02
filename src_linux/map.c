//TODO: add header

#include "so_long.h"

//checks the width of the map (without the \n)
static int	width_map(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (str[len - 1] == '\n')
		len--;
	return (len);
}

//allocate memory for the matrix
//add the line to the matrix
//if the matrix is not empty, free it
//returns 1 if everything is ok
static int	add_line(t_game *map, char *line, int iter)
{
	int		i;
	char	**tmp;
	size_t	len;

	i = 0;
	if (line == NULL)
		return (0);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	tmp = (char **)malloc(sizeof(char *) * (iter + 2));
	if (tmp == NULL)
		return (0);
	tmp[iter] = NULL;
	while (i < iter)
	{
		tmp[i] = map->matrix[i];
		i++;
	}
	tmp[i] = line;
	tmp[i + 1] = NULL;
	map->matrix = tmp;
	map->height++;
	return (1);
}

static char	**read_files(char **av)
{
	int		fd;
	char	buf[1024];
	ssize_t	read_size;
	char	**lines;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (0);
	}
	read_size = read(fd, buf, sizeof(buf) - 1);
	if (read_size == -1)
	{
		close (fd);
		return (0);
	}
	buf[read_size] = '\0';
	lines = ft_split(buf, '\n');
	close (fd);
	return (lines);
}

static int	process_lines(t_game *map, char **lines)
{
	int	i;

	i = 0;
	while (lines[i] != NULL)
	{
		if (lines[i][0] == '\0')
		{
			ft_printf("Empty line found at line %d", i + 1);
			return (0);
		}
		if (!add_line(map, lines[i], i))
			break ;
		i++;
	}
	free (lines);
	map->height = i;
	map->width = width_map(map->matrix[0]);
	return (1);
}

//reads the map and stores it in a matrix
int	so_reading_the_map(t_game *map, char **av)
{
	char	**lines;

	lines = read_files(av);
	if (lines == NULL)
		return (0);
	return (process_lines(map, lines));
}
