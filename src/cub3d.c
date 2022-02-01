#include <cub3d.h>
#include <fcntl.h>
#include <stdlib.h>


int main(void)
{
		int		fd;
	int		fd2;
	int		fd3;
	char	*line;

	fd = open("file", O_RDONLY);
	fd2 = open("file3", O_RDONLY);
	fd3 = open("file3", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);
	close(fd2);
	return (0);
}