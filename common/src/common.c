#include <stdio.h>

#include "common.h"

#ifdef A_PROJECT
static const char *name = "A Project";
#elif defined(B_PROJECT)
static const char *name = "B Project";
#else
static const char *name = "Unknown Project";
#endif

void printProjectName(void)
{
    printf("Project %s\n", name);
}