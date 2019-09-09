#include "auto_header.h"
#include <stdlib.h>
#include <string.h>

t_folders       *add_folder(char *data)
{
    t_folders   *new;

    new = (t_folders *)malloc(sizeof(t_folders));
    new->data = data;
    new->directories = NULL;
    new->next = NULL;
    return (new);
}

t_list          *add_include(char *data)
{
    t_list      *new;
    
    new = (t_list *)malloc(sizeof(t_list));
    new->data = data;
    new->prototype = NULL;
    new->next = NULL;
    return (new);
}

t_list          *new_file(char *data)
{
    t_list      *new;

    new = (t_list *)malloc(sizeof(t_list));
    new->data = data;
    new->prototype = NULL;
    new->next = NULL;
    return (new);
}

t_list          *add_file(t_list *list, char *data)
{
    list->next = (t_list *)malloc(sizeof(t_list));
    list->next->data = data;
    list->next->prototype = NULL;
    list->next->next = NULL;
    return (list->next);
}

t_prot          *new_prototype(char *data)
{
    t_prot      *new;

    new = (t_prot *)malloc(sizeof(t_prot));
    new->type_data = get_type(data);
    new->info_data = get_info(data, strlen(new->type_data));
    new->next = NULL;
    return (new);
}

t_prot          *add_prototype(t_prot *list, char *data)
{
    list->next = (t_prot *)malloc(sizeof(t_prot));
    list->next->type_data = get_type(data);
    list->next->info_data = get_info(data, strlen(list->next->type_data));
    list->next->next = NULL;
    return (list->next);
}

t_dir           *new_directory(char *data)
{
    t_dir       *dir;

    dir = (t_dir *)malloc(sizeof(t_dir));
    dir->data = data;
    dir->files = NULL;
    dir->next = NULL;
    return (dir);
}

t_dir           *add_directory(t_dir *list, char *data)
{
    list->next = (t_dir *)malloc(sizeof(t_dir));
    list->next->files = NULL;
    list->next->data = data;
    list->next->next = NULL;
    return (list->next);
}
