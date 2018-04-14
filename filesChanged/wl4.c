#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


//Every input is followed by some cpu intensive calculations (buffer == 1000)
int main(int argc, char * argv[])
{
	
	int fileDesc, readFlag;
	int reps = 50;
	double l = 0;
	char inputCharacter[1];
	if(argc <= 1)
	{
		printf(1, "Wl4 requires an input file (ex README)\n");
		exit();
	}
	
	for(int i = 0; i < reps; i++)
	{
		if((fileDesc = open(argv[1], O_RDONLY)) < 0)
		{
			printf(1,"Failed to open %s\n", argv[1]);
			exit();
		}

		while((readFlag = read(fileDesc,inputCharacter,1)) > 0)
		{	
			for(int j = 1; j < 10; j++)
				for(int k = 1; k < 10; k++)
					l += j/k/j + 1;			
		}
		close(fileDesc);
	}
	
	printf(1,">>>Finished wl4, output: %d\n", (int) l);
	exit();
}
		
	
