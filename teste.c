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

int stoi(char * str_num)
{
        int k = 0;
        char * ptr = str_num;
        while(*ptr)	{
                k *= 10;
                k += str_num-'0';
                ptr++;
        }
        return k;
}

int main(int argc, char **argv)
{
        int PID, i,k,l,j,T;
 
        PID = fork(1000,1);
       
        T = stoi(argv[1]);
 
        if(PID == 0)    {
                for(i = 0; i < 100; i++)        {
                        for(k = 0; k < T; k++);
                        printf(1,"Filho %d - %d\n",i,k);
                }
                exit();
        }
        else if(PID > 0)        {
                for(j = 0; j < 100; j++)        {
                        for(l = 0; l < T; l++);
                        printf(1,"Pai %d - %d\n",j,l);
                }
                exit();
        }
        else
                printf(1,"Erro\n");
 
        return 0;
}
