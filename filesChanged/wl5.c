#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


//Every IO is followe by some CPU intensive calculations (buffer == 1000)
int main(int argc, char * argv[])
{
	int fileDesc, readFlag;
	int reps = 100;
	double l = 0;
	char inputCharacter[1000];
	if(argc <= 1)
	{
		printf(1, "Wl5 requires an input file (ex README)\n");
		exit();
	}
	
	for(int i = 0; i < reps; i++)
	{
		if((fileDesc = open(argv[1], O_RDONLY)) < 0)
		{
			printf(1,"Failed to open %s\n", argv[1]);
			exit();
		}

		while( (readFlag = read(fileDesc,inputCharacter,sizeof(inputCharacter))) > 0)
		{
			for(int j = 1; j < 100; j++)
				for(int k = 1; k < 50; k++)
					l += j / k / j + 1;	
		}
		close(fileDesc);
	}

	printf(1,">>>Finished Wl5, output: %d\n", (int) l);

	exit();
}
