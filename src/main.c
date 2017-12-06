#include "woody.h"

void	ft_error(char *message)
{
	dprintf(2, "%s", message);
	exit(0);
}

void	check_file(t_env *e)
{
	char	*magic;

	magic = &((char*)e->bin)[0];
	if (*magic != 0x7f || *(++magic) != 0x45 || *(++magic) != 0x4c || *(++magic) != 0x46)
		ft_error("File is not ELF format\n");
	if (*(++magic) != 2)
		ft_error("ELF File is not 64 bits\n");
	e->elf_head = (Elf64_Ehdr *)e->bin;
	e->numheads = e->elf_head->e_phnum;
	e->elf_prog = (Elf64_Phdr *)(e->bin + e->elf_head->e_phoff);
	e->entry = e->elf_head->e_entry;
}

void	map_file(char *file, t_env *e)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("Error opening file\n");
	if ((e->size = lseek(fd, 0, SEEK_END)) == -1)
		ft_error("Error reading file size\n");
	if ((e->bin = mmap(0, e->size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		ft_error("Error mapping file\n");
}

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
	{
		dprintf(2, "No File Specified\n");
		return (0);
	}
	map_file(argv[1], &e);
	check_file(&e);

	Elf64_Shdr	*text_sec;
	if ((text_sec = find_elf_sec(&e, ".data")) == NULL)
		ft_error("No .text section found\n");
	int i = 0;
	unsigned char *bytes = (unsigned char *) e.bin;
	while (i < (int)text_sec->sh_size)
	{
		printf("%02x%s",  bytes[text_sec->sh_offset + i], ((i % 10 == 0 && i > 0) ? "\n" : " "));
		i++;
	}
	printf("\ntext size %llu\n", text_sec->sh_size);	
	/*int len, start;

	find_elf_gap(&e, &start, &len);
	printf("\ngap size %i\n", len);
	i = 0;
	while (i < len + 20)
	{
		printf("%02x%s", bytes[start - 10 + i], ((i % 10 == 0 && i > 0) ? "\n" : " "));
		i++;
	}*/
	printf("\n");

	int j = 0;
	while (j < e.elf_head->e_phnum)
	{
		printf("\nflags %02x\n", e.elf_prog[i].p_flags);
		if (e.elf_prog[i].p_type == PT_LOAD && e.elf_prog[i].p_flags & 0x011) {
			printf("\nfound 1\n");
		}
		else if (e.elf_prog[i].p_type == PT_LOAD)
		{
			printf("\nfound 2\n");
			e.elf_prog = &e.elf_prog[i];
			break;
		}
		j++;
	}
	i = 0;
	printf("\nprogram header\n");
	while (i < (int)e.elf_prog->p_memsz)
	{
		printf("%02x%s", bytes[e.elf_prog->p_offset + i], ((i % 10 == 0 && i > 0) ? "\n" : " " ));
		i++;
	} 
}
