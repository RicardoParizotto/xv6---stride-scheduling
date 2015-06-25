#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main()
{
	int PID, i,k;

	PID = fork(1000,1);

	if(PID == 0)	{
		for(i = 0; i < 1000; i++)
			printf(1,"Filho %d\n",i);
		exit();
	} 
	else if(PID > 0)	{
		for(k = 0; k < 1000; k++)
			printf(1,"Pai %d\n",k);
		exit();
	}
	else
		printf(1,"Erro\n");

	return 0;
}
