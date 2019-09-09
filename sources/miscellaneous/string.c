#include <stdlib.h>
#include <string.h>

char        *strjoin(char const *s1, char const *s2)
{
    char    *join_result;
    char    *join_result_begin;
    int     size;

    if (!s1 || !s2)
        return (NULL);
    if (!(size = strlen(s1) + strlen(s2) + 1))
        return (NULL);
    if (!(join_result = (char *)malloc(sizeof(char) * size)))
        return (NULL);
    join_result_begin = join_result;
    while (*s1)
        *join_result++ = *s1++;
    while (*s2)
        *join_result++ = *s2++;
    *join_result = '\0';
    return (join_result_begin);
}

void        *ft_strnew(int size)
{
    char    *result;

    result = (char *)malloc(sizeof(char) * (size + 1));
    if (!result)
        return (NULL);
    memset(result, '\0', (size + 1));
    return (result);
}

void        ft_memdel(void **ap)
{
    if (!ap)
        return ;
    free(*ap);
    *ap = NULL;
}

char        *get_full_path(char *folder, char *file_name)
{
    char    *temporary;
    char    *temporary_2;

    temporary = strjoin(folder, "/");
    temporary_2 = strjoin(temporary, file_name);
    free(temporary);
    return (temporary_2);
}
