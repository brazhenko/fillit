#ifndef FILLIT_H
# define FILLIT_H
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

int			check_n_fill(int fd);

typedef struct		s_figure
{
	char a[4];
	char b[4];
	char c[4];
	char d[2];
}					t_figure;
#endif
