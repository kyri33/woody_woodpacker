#include "woody.h"

Elf64_Shdr	*find_elf_sec(t_env *e, char *sname)
{
	char		*name;
	Elf64_Shdr	*elf_sec;
	Elf64_Shdr	*elf_strtab;
	const char	*tabnames;
	int			i;
(void) sname;
	elf_sec = (Elf64_Shdr *)(e->bin + e->elf_head->e_shoff);
	elf_strtab = &elf_sec[e->elf_head->e_shstrndx];
	tabnames = e->bin + elf_strtab->sh_offset;
	i = 0;
	while (i < e->elf_head->e_shnum)
	{
		name = (char *) (tabnames + elf_sec[i].sh_name);
		if (!ft_strcmp(sname, name))
			return &elf_sec[i];
		i++;
	}
	return NULL;
}

void	find_elf_gap(t_env *e, int *start, int *len)
{
	int	i;
	int	end;
	int	gap;

	gap = 1000000000;

	i = 0;
	while (i < e->elf_head->e_phnum)
	{
		if (e->elf_prog[i].p_type == PT_LOAD && e->elf_prog[i].p_flags & 0x011) {
			end = e->elf_prog[i].p_offset + e->elf_prog[i].p_filesz;
		}else if (e->elf_prog[i].p_type == PT_LOAD && ((int)e->elf_prog[i].p_offset - end) < gap){
			gap = e->elf_prog[i].p_offset - end;
		}
		i++;
	}
	*start = end;
	*len = gap;
}
