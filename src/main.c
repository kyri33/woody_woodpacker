#include "woody.h"

void	ft_error(char *message)
{
	perror(message);
	exit(0);
}

void	check_file(t_env *e)
{
	char	magic;

	magic = ((char*)e->bin)[2];
	//if (magic == 0x7f)
		printf("Magic number is %x\n", magic);
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
}
