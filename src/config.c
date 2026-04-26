#include"include.h"


char* expand_config_path(const char* path){
  wordexp_t exp;

  if(wordexp(path, &exp, WRDE_NOCMD) != 0)
    {
      return NULL;
    }

  char* expanded = strdup(exp.we_wordv[0]);
  wordfree(&exp);
  return expanded;
}
