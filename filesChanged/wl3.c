#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


//Only 	IO proc (buffer == 1000)
int main(int argc, char * argv[])
{
	
	int fileDesc, readFlag;
	int reps = 1500;
	char inputCharacter[1000];
	if(argc <= 1)
	{
		printf(1, "Wl3 requires an input file (ex README)\n");
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
			;
		close(fileDesc);
	}

	printf(1,">>>Finished Wl3\n");
	exit();
}
		
	
