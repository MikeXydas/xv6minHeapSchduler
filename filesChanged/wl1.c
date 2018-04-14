#include "types.h"
#include "stat.h"
#include "user.h"


//CPU only intensive proc
int main(int argc, char * argv[])
{

	double k = 0;
	for(int i = 1; i < 80000; i++)
		for(int j = 1; j < 20000; j++)
				k +=  i / j / i + 1;

	printf(1,">>>Finished wl1, output: %d\n", (int) k);
	exit();
}
