#include "auto_header.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static char         **check_empty_string(char **stack)
{
    if (!(*stack))
        *stack = ft_strnew(0);
    return (stack);
}

static int          generate_new_line(char **stack, char **line)
{
    char            *temporary;

    if (!(*stack)[0])
        return (0);
    if (strchr(*stack, '\n'))
    {
        *(strchr(*stack, '\n')) = '\0';
        *line = strdup(*stack);
        temporary = strdup(strchr(*stack, '\0') + 1);
        free(*stack);
        if (temporary)
        {
            *stack = strdup(temporary);
            free(temporary);
        }
    }
    else
    {
        *line = strdup(*stack);
        ft_memdel((void **)stack);
    }
    return (1);
}

static void         generate_new_string(char **stack, char *buffer)
{
    char            *temporary;

    temporary = strjoin(*stack, buffer);
    free(*stack);
    *stack = strdup(temporary);
    free(temporary);
}

int                 get_next_line(const int fd, char **line)
{
	static char     *stack[10240];
	char            buffer[BUFF_SIZE + 1];
	int             amount;

	if (fd < 0 || read(fd, buffer, 0) || !line)
		return (-1);
	check_empty_string(&(stack[fd]));
	while (!(strchr(stack[fd], '\n')))
	{
		amount = read(fd, buffer, BUFF_SIZE);
		buffer[amount] = '\0';
		if (!amount)
            break ;
		generate_new_string(&(stack[fd]), buffer);
	}
	return (generate_new_line(&(stack[fd]), line));
}
