#include "auto_header.h"

int                 main(int argc, char **argv)
{
    t_auto_header   *core;

    initialization_errors(argc, argv);
    core = parsing(argc, argv);
    parsing_directories(core);
    parsing_files(core);
    parsing_prototypes(core);
    create_prototype(core);
    return (0);
}
