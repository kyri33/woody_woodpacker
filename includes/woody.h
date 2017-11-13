#ifndef FT_WOODY_WOODPACKER
# define FT_WOODY_WOODPACKER

# include <elf.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>

typedef struct	s_env
{
	void	*bin;
	int		size;
}				t_env;

#endif
