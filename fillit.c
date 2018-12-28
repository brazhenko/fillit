#include "fillit.h"

int				main(int c, char **v)
{
	if (c == 2)
	{
		int fd;
		char *line;

		fd = open(v[1], O_RDONLY);
		int res = check_n_fill(fd);
		printf("%d\n", res);
	}
	return (0);
}
