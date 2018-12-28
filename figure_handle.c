#include "fillit.h"

static int		dots_n_sharps_only(char *str)
{
	while (*str)
	{
		if (*str != '.' &&  *str != '#')
			return (0);
		str++;
	}
	return (1);
}

static int		one_fig_handle(char *figure)
{
	int		i;

	i = 0;
	while (figure[i])
	{
		if (figure[i] == '#')
		{
			if (figure[i + 1] != '.')
				figure[i]++;
			if (figure[i - 1] != '.')
				figure[i]++;
			if (figure[i + 4] != '.')
				figure[i]++;
			if (figure[i - 4] != '.')
				figure[i]++;
		}
		i++;
	}
	printf("%s\n", figure);
	return (1);
}

static int		figures_handle(char *figures)
{
	char		*fig_cpy;
	int			fig_count;
	int			i;
	char		**fig_v;
	i = 0;
	fig_cpy = figures;

	fig_count = ft_strlen(figures) / 16;
	printf("FIGURES: %s\n", figures);
	fig_v = ft_strsplit(figures, ' ');
	while (*fig_v)
	{
		one_fig_handle(ft_strjoin("\0\0\0\0", *fig_v));
		fig_v++;
	}
	return (1);
}

int				check_n_fill(int fd)
{
	char	*str;
	int		line_c;
	char	*figures;
	char	*temp_figures;

	figures = ft_strnew(1);
	line_c = 1;
	while (get_next_line(fd, &str))
	{
		if (line_c % 5 == 0)
		{
			if (ft_strlen(str) != 0)
				return (0);
			temp_figures = figures;
			figures = ft_strjoin(figures, " ");
			free(temp_figures);
		}
		else
		{
			if (ft_strlen(str) != 4 || dots_n_sharps_only(str) != 1)
				return (0);
			temp_figures = figures;
			figures = ft_strjoin(figures, str);
			free(temp_figures);
		}
		free(str);
		line_c++;
	}
	if (line_c % 5 == 0)
		if (figures_handle(figures))
			return (1);
	return (0);
}
