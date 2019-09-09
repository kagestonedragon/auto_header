#include "auto_header.h"
#include <string.h>
#include <sys/stat.h>

static int  is_return_type(char *line)
{
    if ((line[0] >= 'a' && line[0] <= 'z') || (line[0] >= 'A' && line[0] <= 'Z'))
        return (0);
    return (1);
}

static int  is_static(char *line)
{
    if (!strncmp("static", line, 6))
        return (1);
    return (0);
}

static int  is_spaces_tabs(char *line)
{
    int     i;

    i = -1;
    while (line[++i])
        if (line[i] == ' ' || line[i] == '\t')
            return (0);
    return (1);
}

static int  is_opened_bracket(char *line)
{
    int     i;

    i = -1;
    while (line[++i])
        if (line[i] == '(')
            return (0);
    return (1);
}

static int  is_closed_bracket(char *line)
{
    int     i;

    i = -1;
    while (line[++i])
        if (line[i] == ')')
            return (0);
    return (1);
}

int         is_prototype(char *line)
{
    if (is_static(line))
        return (0);
    if (is_return_type(line))
        return (0);
    if (is_spaces_tabs(line))
        return (0);
    if (is_opened_bracket(line))
        return (0);
    if (is_closed_bracket(line))
        return (0);
    return (1);
}

int             is_source_file(char *file_name)
{
    int         length;

    length = strlen(file_name);
    if (file_name[length - 1] == 'c' && file_name[length - 2] == '.')
        return (1);
    return (0);
}

int             is_folder(char *folder_name)
{
    struct stat sb;

    if (!stat(folder_name, &sb) && S_ISDIR(sb.st_mode))
        return (1);
    return (0);
}

int             is_header_file(char *file_name)
{
    int         length;

    length = strlen(file_name);
    if (file_name[length - 1] == 'h' && file_name[length - 2] == '.')
        return (1);
    return (0);
}

int             is_file(char *file_name)
{
    struct stat sb;

    if (!stat(file_name, &sb) && S_ISREG(sb.st_mode))
        return (1);
    return (0);
}

int             is_slash(char *folder_name)
{
    int         length;

    length = strlen(folder_name);
    if (folder_name[length - 1] == '/')
        folder_name[length - 1] = '\0';
    return (0);
}
