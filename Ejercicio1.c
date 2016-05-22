#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 3

int A[3][3]={{1,2,3},
	         {3,4,5},
	         {6,7,8}};
	         
int a[3]={0,0,0};
int b[3]={1,1,1};


void *SumMult(void *threadid)
{
	int *id_ptr, taskid;
	sleep(1);
	id_ptr = (int *) threadid;
	taskid = *id_ptr;
	int k,k1,k2,j,sum0=0,mult0=1,sum1=0,mult1=1,sum2=0,mult2=1;
	
	switch(taskid){
		case 0:	
				for(k=0;k<NUM_THREADS;k++){
				    sum0 = sum0 + A[0][k];
				    mult0 = mult0*A[k][0];
				}
					a[0] = sum0;
					b[0] = mult0;
			break;
			
		case 1: 
		       for(k1=0;k1<NUM_THREADS;k1++){
				    sum1 = sum1 + A[1][k1];
				    mult1 = mult1*A[k1][1];
				}
					a[1] = sum1;
					b[1] = mult1;
			break;
			
		case 2:	
		        for(k2=0;k2<NUM_THREADS;k2++){
				    sum2 = sum2 + A[2][k2];
				    mult2 = mult2*A[k2][2];
				}
					a[2] = sum2;
					b[2] = mult2;
			break;
	}		
	pthread_exit((void*)threadid);
}

int main(int argc, char *argv[]) 
{
	pthread_t threads[NUM_THREADS];
	int *taskids[NUM_THREADS];
	int rc;
    void *status;
    long t;

	for(t=0;t<NUM_THREADS;t++) {
		taskids[t] = (int *) malloc(sizeof(int));
		*taskids[t] = t;
		printf("Creando thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, SumMult,(void *) taskids[t]);
		if (rc) {
			printf("ERR; pthread_create() ret = %d\n", rc);
			exit(-1);
		}
	}

    for(t=0; t<NUM_THREADS; t++) 
	{
		rc = pthread_join(threads[t], &status);
		if (rc) 
		{
		printf("ERROR; return code is %d\n", rc);
		exit(-1);
		}
		printf("Main: Estado para el thread %ld: %ld\n",t, (long)status);
	}
	printf("Main: Programa finalizado.\n");

    int p,q;
    for(p=0;p<NUM_THREADS;p++){
		printf("El vector suma es :%d\n",a[p]);
	}
	
	for(q=0;q<NUM_THREADS;q++){
		printf("El vector mult es :%d\n",b[q]);
	}
	pthread_exit(NULL);
}

