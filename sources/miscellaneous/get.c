#include "auto_header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/* START GET PROTOTYPES */
char            *get_type(char *line)
{
    char        *type;
    int         i;

    i = -1;
    type = NULL;
    while (line[++i])
    {
        if (line[i] == ' ' || line[i] == '\t')
        {
            type = (char *)malloc(sizeof(char) * (i + 1));
            type[0] = '\0';
            type[i] = '\0';
            strncpy(type, line, i);
            break ;
        }
    }
    return (type);
}

char            *get_info(char *line, int start)
{
    char        *info;
    int         i;
    int         size;

    i = start;
    info = NULL;
    while (line[++i])
    {
        if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z') || line[i] == '*')
        {
            size = strlen(&(line[i]));
            info = (char *)malloc(sizeof(char) * (size + 1));
            info[0] = '\0';
            info[size] = '\0';
            strcpy(info, &(line[i]));
            break ;
        }
    }
    return (info);
}

int             get_max_tabulation(t_dir *dir)
{
    t_dir       *temporary_dir;
    t_list      *temporary_list;
    t_prot      *temporary_prot;
    int         tab;
    int         i;
    int         out_max_tab;

    out_max_tab = 0;
    temporary_dir = dir;
    while (temporary_dir)
    {
        temporary_list = temporary_dir->files;
        while (temporary_list)
        {
            temporary_prot = temporary_list->prototype;
            while (temporary_prot)
            {
                i = -1;
                tab = 0;
                while (temporary_prot->type_data[++i])
                    if (!((i + 1) % 4))
                        tab += 1;
                if (tab > out_max_tab)
                    out_max_tab = tab;
                temporary_prot->tab = tab;
                temporary_prot = temporary_prot->next;
            }
            temporary_list = temporary_list->next;
        }
        temporary_dir = temporary_dir->next;
    }
    return (out_max_tab);
}

/* END GET PROTOTYPES */



/* START GET DIRECTORIES */
t_dir           *get_last_directory(t_dir *dir)
{
    t_dir       *temporary;

    temporary = dir;
    while (temporary->next)
        temporary = temporary->next;
    return (temporary);
}
/* END GET DIRECTORIES */



/* START CREATE HEADER */
int             get_define(t_auto_header *core)
{
    int         i;

    i = -1;
    core->file_variable = strdup(core->file_name);
    while (core->file_variable[++i])
    {
        if (core->file_variable[i] == '.')
            core->file_variable[i] = '_';
        if (core->file_variable[i] == '/')
            core->file_variable[i] = '_';
        core->file_variable[i] = toupper(core->file_variable[i]);
    }
    return (0);
}
/* END CREATE HEADER */
