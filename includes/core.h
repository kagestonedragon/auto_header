#ifndef CORE_H
# define CORE_H
# define BUFF_SIZE          1024
# define ERROR_DIRECTORY    100
# define ERROR_HEADER       200

typedef struct          s_prot{
    char                *type_data;
    char                *info_data;
    int                 tab;
    struct s_prot       *next;
}                       t_prot;

typedef struct          s_list{
    char                *data;
    t_prot              *prototype;
    struct s_list       *next;
}                       t_list;

typedef struct          s_dir{
    char                *data;
    int                 max_tab;
    t_list              *files;
    struct s_dir        *next;
}                       t_dir;

typedef struct          s_folders{
    char                *data;
    t_dir               *directories;
    struct s_folders    *next;
}                       t_folders;

typedef struct          s_auto_header{
    char                *file_name;
    char                *file_variable;
    t_folders           *sources_folders;
    t_list              *includes_files;
}                       t_auto_header;

#endif
