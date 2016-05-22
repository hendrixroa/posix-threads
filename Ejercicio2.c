#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **params;
int numparms;

void *frequency(void *threadid)
{
	int *id_ptr, taskid;
	sleep(1);
	id_ptr = (int *) threadid;
	taskid = *id_ptr;
	char *cadena ,*car = params[taskid+1];
	int cont=0,i,tam,j;
	cadena = malloc(sizeof(char) * 128);
	
	printf("Ingrese cadena para thread :%d\n",taskid);
	scanf("%126s",cadena);
	tam = strlen(cadena);
	for(i=0;i<tam;i++){
		if(car[0]==cadena[i]){
		cont++;
		}
	}
	printf("Thread %d ",taskid);
	printf(":La letra %s",params[taskid+1]);
	printf(" aparece %d",cont);
	printf(" veces en %s",cadena);
	printf("\n");
	
	pthread_exit((void*)threadid);
}

int main(int argc, char **argv){
	
	params = argv;
	numparms = argc-1;
	
	pthread_t threads[argc-1];
	int *taskids[argc-1];
	int rc;
    void *status;
    long t;

	for(t=0;t<argc-1;t++) {
		taskids[t] = (int *) malloc(sizeof(int));
		*taskids[t] = t;
		printf("Creando thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL,frequency,(void *) taskids[t]);
		if (rc) {
			printf("ERR; pthread_create() ret = %d\n", rc);
			exit(-1);
		}
	}

   pthread_exit(NULL);
}
