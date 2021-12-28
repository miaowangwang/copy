#include"pcpy.h"



int main(int argc,char **argv)
{
	int pos = atoi(argv[4]);
	int blocksize= atoi(argv[3]);
	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));
	//argv[1] = sfil argv[2] = desfile argv[3] = blocksize  argv[4] = pos  

	int sfd = open(argv[1],O_RDONLY);
	int dfd = open(argv[2],O_WRONLY|O_CREAT,0664);
	lseek(sfd,pos,SEEK_SET);
	lseek(dfd,pos,SEEK_SET);
	printf("Copy Cpro pid [%d] Pos [%d] Block [%d]\n",getpid(),pos,blocksize);
	int rsize;
	rsize = read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,rsize);
	printf("拷贝完毕..\n");
	return 0;
	
	
	
		
}
