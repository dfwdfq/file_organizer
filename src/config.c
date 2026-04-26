#include"include.h"

struct Config* config = NULL;
size_t config_size = 7;

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
int _read_dir_name(char* dir_name, char* buffer){
  int pos = 0;
  while(buffer[pos] != ':')
    {      
      if(pos >= 64) return -1;
      if(buffer[pos] == '\0') return -1;
      
      dir_name[pos] = buffer[pos];
      ++pos;
    }
  dir_name[pos] = '\0';
  return pos;
}
int read_ext(char* ext, char*buffer){
  int pos = 0;
  while(buffer[pos] != '\0')
    {
      if(isspace(buffer[pos])) continue;
      if(buffer[pos] == ',')
	{
	  buffer[pos] = '\0';
	  return pos;
	}
      
      ext[pos] = buffer[pos];
      ++pos;
    }
  return -2;
}

RETURN read_config_file(const char*path){
  FILE* fp = fopen(path,"r");
  if(!fp)
    {
      fprintf(stderr,"failed to read config file:%s!\n");
      return FAIL;
    }

  config = malloc(config_size* sizeof(struct Config));
  char buf[256];

  size_t current_element = 0;
  while(fgets(buf, sizeof(buf), fp))
    {
      buf[strcspn(buf, "\n")] = '\0';
      
      char dir_name[64];
      int delim_pos = _read_dir_name(dir_name, buf);
      if(delim_pos == -1)
	{
	  fclose(fp);
	  return FAIL;
	}
      
      
      int ext_count = 0;
      char* ext_line = buf+delim_pos+1;
      size_t len = strlen(ext_line);
      for(int i = 0;i<len;++i)
	{
	  if(ext_line[i] == ',')ext_count++;
	}
      ext_count++; //count the last one

      char (*exts)[20] = malloc(ext_count* sizeof(*exts));
      if(exts == NULL)
	{
	  fclose(fp);
	  perror("malloc failed");
	  return FAIL;
	}

      int i = 0, j = 0;
      while(*ext_line != '\0')
	{	  
	  if(*ext_line == ',')
	    {
	      exts[i][j] = '\0';
	      i++;
	      j = 0;	      
	    }
	  else
	    {
              if(j < 19) exts[i][j++] = *ext_line;
            }
	  
	  ext_line++;
	}
      if(j > 0) exts[i][j] = '\0';

      /*
	So, we have directory name and array of extensions
	TODO: make one-to-many
      */
    }

  fclose(fp);

}

