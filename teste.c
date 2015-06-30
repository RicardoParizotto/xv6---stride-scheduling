/*
	Passar como parâmetro um número suficientemente grande para verificar a corretude do escalonador.
	Redirecionar a saída para um arquivo para melhor visualização do escalonamento.
	Exemplo de execução:
		./teste 10000 > arquivo_teste
*/

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "param.h"

int stoi(char * str_num)
{
        int k = 0;
        char * ptr = str_num;
        while(*ptr)	{
                k *= 10;
				k += *ptr-'0';
                ptr++;
        }
        return k;
}

void test(int T, int i, char * name){
		int j, k;
		for(j = 0; j < 100; j++){
				for(k = 0; k < T; k++);
				printf(1, "%s - %d tickets\n", name, i); 
		}
		exit();
}

int main(int argc, char **argv)
{
  int PID, T;

        PID = fork(100,1);
       
        T = stoi(argv[1]);
 
        if(PID == 0) {
				test(T, 100, "filho");               
		}else if(PID > 0)        {
				PID = fork(500, 1);
				if(PID == 0)	{
						test(T, 500, "filho");
				}else if(PID > 0)	{
						PID = fork(1000, 1);
						if(PID == 0){
									test(T, 1000, "filho");
						}else if(PID > 0){
								test(T, N_TICKETS, "pai");
				
						}
        
				}
		}
		
        return 0;
}
