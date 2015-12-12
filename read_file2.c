#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
typedef struct student
{
	char name[20];
	int age;
	char sex[10];
	double score;
	
}stu;
#define SIZE sizeof(stu)
int main(int argc, char const *argv[])
{
	int fd;
	fd = open("/mnt/hgfs/linux_share/day20151211/fang",O_RDWR,0777);
	if(fd == -1)
	{
		perror("open error  :");
	}

	stu *p;
	// stu *pos;

	p =(stu *)mmap(NULL,SIZE,PROT_EXEC|PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(p == NULL) 
	{
		perror("mmap error");
	}
	char _name[20];
	strcpy(_name,p->name);
	printf("%d\n",p -> age);
	printf("%s\n",_name );


	int _munmap;
	_munmap = munmap(p,SIZE);

	if(_munmap == -1)
	{
		perror("munmap error");
	}

	p = NULL;
	return 0;
}
