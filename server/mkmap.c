
#include "mkmap.h"

#ifdef DEBUG_MK_MAP
int main( int argc, char *argv[] )
{
  if( argc == 1 ) {
    printf("usage: %s <size> <size-units> ", argv[0]);
    printf("<terrain1 terr1-prob [terr2 terr2-prob ...]>\n");
    printf("\tsize       = <int>\n");
    printf("\tsize-units = <string>\n");
    printf("\tterrain    = <string>\n");
    printf("\tterr-prob  = <double in [0,1]>\n");
    exit(0);
  }
  if( argc < 5 ) {
    printf("ERROR not enough arguments.\n");
    printf("usage: %s <size> <size-units> ", argv[0]);
    printf("<terrain1 terr1-prob [terr2 terr2-prob ...]>\n");
    exit(0);
  }
  if( !(argc % 2) ) {
    printf("ERROR missing at least 1 argument.\n");
    printf("All given arguments will be part of a pair.\n");
    exit(0);
  }
  int i;
  long sz; 
  char *sz_units;
  char *terr[argc-5+2];       //+1 extra for a '0'
  double terr_prob[argc-5+1];
  
  sz = atoi(argv[1]);
  sz_units = strdup(argv[2]);
  for( i = 3; i < argc; i += 2 ) {
    terr[(i/2)-1] = strdup(argv[i]);
    terr_prob[(i/2)-1] = atof(argv[i+1]);
  }
  terr[(i/2)-1] = NULL;
  mkmap(sz, sz_units, terr, terr_prob);
  free(sz_units);
  i = 0;
  while(terr[i]) {
    free(terr[i++]);
  }
}
#endif

int mkmap(long sz, char *sz_units, char **terr, double terr_prob[])
{
  int i;
#ifdef DEBUG_MK_MAP
  printf("size: %ld %s\n", sz,sz_units);
  while( terr[i] ) {
    printf("%s: %.1lf%%\n", terr[i], terr_prob[i]*100);
    i++;
  }
#endif
  return 0;
}
