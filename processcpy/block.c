#include"pcpy.h"


int block(const char *SFile,int pronum)
{
	int FileSize;
	int fd = open(SFile,O_RDONLY); //获取文件大小


	FileSize = lseek(fd,0,SEEK_END);

	if(FileSize % pronum==0)
		return FileSize / pronum;
	else
		return FileSize / pronum +1; //每个进程分1字节,处理余数
	
}
