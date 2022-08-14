#include<stdio.h>
#include<stdlib.h>
#include <dirent.h> 
#include <getopt.h>
#include <string.h>

//cat
int cat(char *file_name)
{
  FILE *f = fopen(file_name, "r");
  if (f == NULL)
  {
    perror("Could not open file\n");
    return -1;
  }
  int cur_sym;
  while ((cur_sym = fgetc(f)) != EOF)
  {
    printf("%c", cur_sym);
  }
  fclose(f);
  return 0;
}

//head - first 10 lines
int head(char *file_name)
{

  FILE *f = fopen(file_name, "r");
  if (f == NULL)
  {
    perror("Could not open file\n");
    return -1;
  }
  char line[50];
  for (int i = 0; i < 10; i++)
  {
    fscanf(f, "%s", line);
    printf("%s\n", line);
  }

  fclose(f);
  return 0;
}

//tail - last 10 lines
int tail(char *file_name)
{
  FILE *f = fopen(file_name, "r");
  if (f == NULL)
  {
    perror("Could not open file\n");
    return -1;
  }

  // count lines
  char new_line = getc(f);
  int line_counter;
  while (new_line != EOF)
  {
    if (new_line == '\n') line_counter++;
    new_line = getc(f);
  }

  rewind(f);

  char ignore[50];
  for (size_t i = 0; i <= line_counter - 10; i++)
  {
    fgets(ignore, sizeof(ignore), f);
  }

  char line[50];
  for (int i = 0; i < 10; i++)
  {
    fscanf(f, "%s", line);
    printf("%s\n", line);
  }
  fclose(f);
  return 0;
}

//mv 
int move(char* source, char* destination) 
{ 
  struct dirent *directory;
  DIR *dir_ptr = opendir(source); // open source folder
  if (!dir_ptr)
  {
    perror("Open directory failed\n");
    return -1;
  }

  chdir(source);

  while ((directory = readdir(dir_ptr)) != NULL)
  {
    lstat(directory->d_name, &statbuf);

    if (!S_ISDIR(statbuf.st_mode))
    {
      sprintf(source, "%s%s", source, directory->d_name);
      sprintf(destination, "%s%s", destination, directory->d_name);
      printf("%s----------------%s\n", directory->d_name, destination);
      rename(source, destination);
    }
  }

    chdir("..");
    closedir(dir_ptr);
    return 0;


  //move
  FILE *source = fopen(file_name, "r");
  int ret;

  if(!(ret = remove(file_name))) {
    printf("File deleted successfully");
    return 0;
  } else {
    perror("Error: unable to delete the file");
    return -1;
  }
  
} 


int copy(char* file1, char* file2) 
{ 
  FILE *source = fopen(file1, "r");
  FILE *target = fopen(file2,"w+");
	//system("cd D:"); 

	char character;
  if (!source || !target)
  {
    perror("Open failed\n");
    return -1;
  }
   
	while((character=fgetc(source))!=EOF) 
	{ 
		fputc(character,target); 
	} 
	fclose(source); 
	fclose(target);
  return 0;
	 
} 
 
//ls
int ls(char* dir_name){
  struct dirent *directory;
  DIR *dir_ptr = opendir(dir_name);
  if (!dir_ptr)
  {
    perror("Open directory failed\n");
    return -1;
  }
  while ((directory = readdir(dir_ptr)) != NULL) 
  {
    printf("%s\n", directory->d_name);
  }
  closedir(dir_ptr);
  return 0;
}


int main(int argc, char **argp) {

  if (!strcmp(argp[1], "cat"))
  {
    cat (argp[2]);
  }
  else if (!strcmp(argp[1], "head"))
  {
     head(argp[2]);
  }
  else if (!strcmp(argp[1], "tail"))
  {
    tail(argp[2]);
  }
  else if (!strcmp(argp[1], "cp"))
  {
    copy(argp[2], argp[3]);
  }
  else if (!strcmp(argp[1], "mv"))
  {
   move(argp[2], argp[3]);
  }
  else if (!strcmp(argp[1], "ls"))
  {
    ls(argp[2]);
  }

  return 0;
}

