#include <unistd.h>

#define LINE_SIZE 1024

int main(int argc, char** argv, char** envp){

	char b[LINE_SIZE];
	int i, j, fd;
	//firstly open the file, and check if there was an error
	//read character in conditional statement,
	//	stopping if the number of bytes is 0 for end of file
	//	or if negative because of some other error
	//in the body check if the character read is a new line
	//	 the other characters in buffer are printed in reverse order
	//in the loop expression check if the character read is a new line
	//	if so write the character and set i to 0 (1 byte written -1)
	//
	//	otherwise i is incremented by 1, bounded by LINE_SIZE
	if((fd = open(argv[1],0))>0)
		for(i = 0;read(fd,b+i,1)>0;i = (*(b+i) == '\n')?write(1,b+i,1)-1:i+1%LINE_SIZE)
			if(*(b+i)=='\n')
				for(j=i-1;j>=0;j--)
					write(1,b+j,1);
	return 0;
}
