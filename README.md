# Auto_header

Auto_header it's easiest way to create your own header file with prototypes. 
<b>C Language projects only.</b>

Also try Auto_make. With it, you can write a script that will help automate routine work.

### Not working

* `Maybe some things :)` Let me know about it.

### How to install

1) Clone repository to the root directory
```
git clone https://github.com/kagestonedragon/auto_header.git ~/auto_header
```

2) Compile
```
make -C ~/auto_header
```

3) Copy Auto_header to your project directory with header files (ex. "includes/")
```
cp ~/auto_header/auto_header <path to the project directory with header files>
```

### How to use

```
./auto_header <output file> -S <sd1> <sd2> ... -I f1.h f2.h ...
```
Run auto_header with parameters:
* `<output file>` — name of the output file (`%.h file`)
* `-S` — recursive search in directories (only `%.c` files)
* `-I` — add others header files to the output file (only `%.h` files)

<b>For example</b>
```
./auto_header auto_header.h -S ../sources -I core.h
```

<p align="left">
  <img src="/pics/console.png" width="75%" alt="auto_make information"/>
</p>


### Generated header file

It uses `\t` instead of spaces, because norminette of 42 Ecole :)

```c
/*
** |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
** |--------------GENERATED BY AUTO_HEADER--------------|
** |                                                    |
** |   https://github.com/kagestonedragon/auto_header   |
** |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/

#ifndef AUTO_HEADER_H
# define AUTO_HEADER_H
# include "core.h"

/*
** ../sources/create_header.c
*/
int					create_prototype(t_auto_header *core);

/*
** ../sources/errors.c
*/
int					initialization_errors(int argc, char **argv);
int					parsing_errors(int error, char *name);

/*
** ../sources/main.c
*/
int					main(int argc, char **argv);

/*
** ../sources/miscellaneous/add.c
*/
t_folders			*add_folder(char *data);
t_list				*add_include(char *data);
t_list				*new_file(char *data);
t_list				*add_file(t_list *list, char *data);
t_prot				*new_prototype(char *data);
t_prot				*add_prototype(t_prot *list, char *data);
t_dir				*new_directory(char *data);
t_dir				*add_directory(t_dir *list, char *data);

/*
** ../sources/miscellaneous/get.c
*/
char				*get_type(char *line);
char				*get_info(char *line, int start);
int					get_max_tabulation(t_dir *dir);
t_dir				*get_last_directory(t_dir *dir);
int					get_define(t_auto_header *core);

/*
** ../sources/miscellaneous/is.c
*/
int					is_prototype(char *line);
int					is_source_file(char *file_name);
int					is_folder(char *folder_name);
int					is_header_file(char *file_name);
int					is_file(char *file_name);
int					is_slash(char *folder_name);

/*
** ../sources/miscellaneous/string.c
*/
char				*strjoin(char const *s1, char const *s2);
void				*ft_strnew(int size);
void				ft_memdel(void **ap);
char				*get_full_path(char *folder, char *file_name);

/*
** ../sources/parsing/get_next_line.c
*/
int					get_next_line(const int fd, char **line);

/*
** ../sources/parsing/parsing.c
*/
t_auto_header		*parsing(int argc, char **argv);

/*
** ../sources/parsing/parsing_directories.c
*/
int					parsing_directories(t_auto_header *core);

/*
** ../sources/parsing/parsing_files.c
*/
int					parsing_files(t_auto_header *core);

/*
** ../sources/parsing/parsing_prototypes.c
*/
int					parsing_prototypes(t_auto_header *core);

#endif
```
