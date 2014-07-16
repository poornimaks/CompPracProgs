//seive

#include<stdlib.h>
#include<stdio.h>
int main()
{
	int *prime;
	unsigned long long int i,limit=100000,j;
	
	prime = malloc(sizeof(int)*limit);
	
	for(i=2;i<100000;i++)
	prime[i]=1;
	
	for(i=2;i<limit;i++)
	{
		if(prime[i])
		{
		for(j=i;i*j<limit;j++)
		{
			prime[i*j]=0;
		}
	}
	}
	for(i=2;i<limit;i++)
	if(prime[i])
	printf("%d=",i);
return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000000 /*size of integers array*/
/*
int main(){
    unsigned long long int i,j;
    int *primes;
    int z = 1;

    primes = malloc(sizeof(int)*LIMIT);

    for (i=2;i<LIMIT;i++)
        primes[i]=1;

    for (i=2;i<LIMIT;i++)
        if (primes[i])
            for (j=i;i*j<LIMIT;j++)
                primes[i*j]=0;

    for (i=2;i<LIMIT;i++)
        if (primes[i])
            printf("%dth prime = %dn",z++,i);

return 0;
}
*/
