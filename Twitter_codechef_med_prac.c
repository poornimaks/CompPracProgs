#include<string.h>
#include<stdio.h>
int f[1000];
int ops[1000];
void init(int n)
{
	int i;
	for(i=0;i<n;i++)
	f[i]=0;
}
int main()
{
int n,k,j=0,pos,c_open=0,i;
char str[10];

scanf("%d",&n);
scanf("%d",&k);

init(n);
	for(i=0;i<k;i++)
	ops[i]=0;
while(k)
{
	scanf("%s",str);
	if(strcmp(str,"CLICK")==0)
	{
		scanf("%d",&pos);
		pos--;
		//-1 the pos
		if(f[pos]==1)
		f[pos]=0;
		else
		f[pos]=1;
	}
	else 
	init(n);
	
	c_open=0;
	for(i=0;i<n;i++)
	{
		c_open+=f[i];
	}
	//printf("\n%d",c_open);
	ops[j++]=c_open;
	k--;
}
	for(i=0;i<j;i++)
	printf("%d\n",ops[i]);
return 0;
}
