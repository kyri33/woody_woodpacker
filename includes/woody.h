#ifndef FT_WOODY_WOODPACKER
# define FT_WOODY_WOODPACKER

#include "../libft/includes/libft.h"
# include <elf.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>

typedef struct	s_env
{
	void		*bin;
	int			size;
	Elf64_Ehdr	*elf_head;
	Elf64_Phdr	*elf_prog;
	Elf64_Shdr	*elf_sec;
	int			numheads;
	uint32_t	entry;
}				t_env;

Elf64_Shdr	*find_elf_sec(t_env *e, char *sname);
void		find_elf_gap(t_env *e, int *start, int *len);

#endif
