#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


//Only inputs proc (buffer == 1)
int main(int argc, char * argv[])
{
	
	int fileDesc, readFlag;
	int reps = 50;
	char inputCharacter[1];
	if(argc <= 1)
	{
		printf(1, "Wl2 requires an input file (ex README)\n");
		exit();
	}
	
	for(int i = 0; i < reps; i++)
	{
		if((fileDesc = open(argv[1], O_RDONLY)) < 0)
		{
			printf(1,"Failed to open %s\n", argv[1]);
			exit();
		}

		while( (readFlag = read(fileDesc,inputCharacter,1)) > 0)
			;
		close(fileDesc);
	}

	printf(1,">>>Finished wl2\n");
	exit();
}
		
	
