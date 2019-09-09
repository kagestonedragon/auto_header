#include "auto_header.h"
#include <dirent.h>
#include <string.h>

static int          get_directories(t_dir *list, const char *path)
{
    DIR             *dir;
    struct dirent   *entry;
    char            *full_path;

    dir = opendir(path);
    while ((entry = readdir(dir)))
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
        {
            full_path = get_full_path((char *)path, entry->d_name);
            add_directory(get_last_directory(list), full_path);
            get_directories(list, full_path);
        }
    }
    closedir(dir);
    return (0);
}

int                 parsing_directories(t_auto_header *core)
{
    t_folders       *temporary;

    temporary = core->sources_folders;
    while (temporary)
    {
        temporary->directories = new_directory(temporary->data);
        get_directories(temporary->directories, temporary->data);
        temporary = temporary->next;
    }
    return (0);
}
