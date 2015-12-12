#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

void travel(char *dir_name)
{
	DIR * _dir;
	_dir = opendir(dir_name);
	// printf("-----------\n");
	struct dirent *_dirent;

	_dirent = readdir(_dir);

	char buf[1024];
	while(1)
	{
		if(strcmp(_dirent -> d_name,".") == 0|| strcmp(_dirent -> d_name,"..") == 0)
		{
			_dirent = readdir(_dir);
			continue;
		}
		// struct stat st;
		// stat(_dirent -> d_name,&st);
		// if(S_ISDIR(st.st_mode))
		if(_dirent -> d_type == DT_DIR)
		{
			// printf("*******\n");
			printf("%s/%s\n",dir_name,_dirent -> d_name);
			travel(_dirent -> d_name);
		}
		else
		{
			// printf("-----------\n");
			printf("%s\n",_dirent -> d_name );
		}
		_dirent = readdir(_dir);		
	}
}
void   readdirent(char* path)
{   
   DIR* dir=opendir(path);   
   //chdir(path);
   struct dirent* ent = readdir(dir);
   while(ent!=NULL)
   {
   	  if(strcmp(ent->d_name,".")==0 ||strcmp(ent->d_name,"..")==0)
   	  {
          ent=readdir(dir);
   		   continue;
   	  }
   	  struct stat st;
    	stat(ent->d_name,&st);
   	  if(S_ISDIR(st.st_mode))
   	  {
          printf("dir:%s\n",ent->d_name);       
          readdirent(ent->d_name);       
   	  }
   	  else
   	  {
   		   printf("file:%s\n",ent->d_name);
         printf("%s:%d\n",ent->d_name,ent->d_off);
   	  }   	
   	  ent=readdir(dir);   	
   } 
   closedir(dir);
   //chdir("..");
}

int main(int argc, char const *argv[])
{
	travel("/mnt/hgfs/linux_share/day20151211/A");
	return 0;
}
