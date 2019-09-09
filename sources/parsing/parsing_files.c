#include "auto_header.h"
#include <dirent.h>

static t_list       *find_files(char *path)
{
    DIR             *dir;
    struct dirent   *entry;
    t_list          *temporary;
    t_list          *list;

    list = (void *)0;
    dir = opendir(path);
    while ((entry = readdir(dir)))
    {
        if (entry->d_type == DT_REG && is_source_file(entry->d_name))
        {
            if (list)
            {
                temporary->next = add_file(temporary, entry->d_name);
                temporary = temporary->next;
            }
            else
            {
                temporary = new_file(entry->d_name);
                list = temporary;
            }
        }
    }
    return (list);
}

int                 parsing_files(t_auto_header *core)
{
    t_dir           *temporary;

    temporary = core->sources_folders->directories;
    while (temporary)
    {
        temporary->files = find_files(temporary->data);
        temporary = temporary->next;
    }
    return (0);
}
