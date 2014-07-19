#include<stdio.h>
int fact(int n)
{
	int f=1,i;
	for(i=1;i<=n;i++)
	f*=i;
	return f;
}
int main()
{
	char temp[100000],str[100000];
	unsigned long long int t,n,i,j,count[100000],k=0,one_count;
	scanf("%llu",&t);
	while(t)
	{
		one_count=0;
		count[k]=0;
		scanf("%llu",&n);
		scanf("%s",temp);
		//cut all zeroes
		//count no of ones and make another array
		for(i=0;i<n;i++)
		{
			if(temp[i]=='1')
			one_count++;
			
		}
	//	for(i=0;i<one_count;i++)
		//str[i]='1';
		/*for(i=0;i<one_count;i++)
		{
			if(str[i]=='1')
			{
				count[k]++;
				//printf("%d",i);
				for(j=i+1;j<one_count;j++)
				{
					if(str[j]=='1')
					count[k]++;
				//printf("%d",j);
				}
			}
		}*/
		//use formula nC1+nC2....nCone_count
	/*	for(i=1;i<=one_count;i++)
		{
			
			count[k]+=fact(one_count)/(fact(i)*fact(one_count-i));
			printf("count:%d-",count[k]);
		}*/
		//printf("%d:",one_count);
		count[k]=one_count*(one_count+1)/2;
		k++;
		t--;
	}
	for(i=0;i<k;i++)
	printf("%llu\n",count[i]);
	return 0;
}
