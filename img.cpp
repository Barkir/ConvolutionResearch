#include <stdio.h>
#include <sys/stat.h>

int LoadImg(const char * filename)
{
    stat filestats = {};
    stat(filename, &filestats);

    FILE * img = fopen(filename, "rb");
}
