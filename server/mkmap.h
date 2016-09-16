
#if _XOPEN_SOURCE < 500
#define _XOPEN_SOURCE 500
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG_MK_MAP

int mkmap(long sz, char *sz_units, char **terrain, double terrain_prob[]);
