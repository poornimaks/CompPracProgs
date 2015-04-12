#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<fstream>
#define size 10000

using namespace std;
int a[5][5];
int arr[5][5][5];

void setup_matrix()
{
	a[1][1]=1;
	a[1][2]=2;
	a[1][3]=3;
	a[1][4]=4;

	a[2][1]=2;
	a[2][2]=-1;
	a[2][3]=4;
	a[2][4]=-3;

	a[3][1]=3;
	a[3][2]=-4;
	a[3][3]=-1;
	a[3][4]=2;

	a[4][1]=4;
	a[4][2]=3;
	a[4][3]=-2;
	a[4][4]=-1;
/**********************/
	arr[1][1][1]=1;
	arr[1][1][2]=2;
	arr[1][1][3]=3;
	arr[1][1][4]=4;

	arr[1][2][1]=2;
	arr[1][2][2]=-1;
	arr[1][2][3]=4;
	arr[1][2][4]=-3;

	arr[1][3][1]=3;
	arr[1][3][2]=-4;
	arr[1][3][3]=-1;
	arr[1][3][4]=2;

	arr[1][4][1]=4;
	arr[1][4][2]=3;
	arr[1][4][3]=-2;
	arr[1][4][4]=-1;

/**********************/

	arr[2][1][1]=2;
	arr[2][1][2]=-1;
	arr[2][1][3]=4;
	arr[2][1][4]=-3;

	arr[2][2][1]=-1;
	arr[2][2][2]=-2;
	arr[2][2][3]=-3;
	arr[2][2][4]=-4;

	arr[2][3][1]=4;
	arr[2][3][2]=3;
	arr[2][3][3]=-2;
	arr[2][3][4]=-1;

	arr[2][4][1]=-3;
	arr[2][4][2]=4;
	arr[2][4][3]=1;
	arr[2][4][4]=-2;
/**********************/

	arr[3][1][1]=3;
	arr[3][1][2]=-4;
	arr[3][1][3]=-1;
	arr[3][1][4]=2;

	arr[3][2][1]=-4;
	arr[3][2][2]=-3;
	arr[3][2][3]=2;
	arr[3][2][4]=1;

	arr[3][3][1]=-1;
	arr[3][3][2]=-2;
	arr[3][3][3]=-3;
	arr[3][3][4]=-4;

	arr[3][4][1]=2;
	arr[3][4][2]=-1;
	arr[3][4][3]=4;
	arr[3][4][4]=-2;
/**********************/

	arr[4][1][1]=4;
	arr[4][1][2]=3;
	arr[4][1][3]=-2;
	arr[4][1][4]=-1;

	arr[4][2][1]=3;
	arr[4][2][2]=-4;
	arr[4][2][3]=-1;
	arr[4][2][4]=2;

	arr[4][3][1]=-2;
	arr[4][3][2]=1;
	arr[4][3][3]=-4;
	arr[4][3][4]=3;

	arr[4][4][1]=-1;
	arr[4][4][2]=-2;
	arr[4][4][3]=-3;
	arr[4][4][4]=-4;

}
void set_mat_2()
{
}
int find_int(char c)
{
	int p;
	switch(c)
	{
		case '1':p=1;
		break;
		case 'i':p=2;
		break;
		case 'j':p=3;
		break;
		case 'k':p=4;
		break;
	}
	return p;
}
char to_char(int x)
{
	char p;
	switch(x)
	{
		case 1:p='1';
		break;
		case 2:p='i';
		break;
		case 3:p='j';
		break;
		case 4:p='k';
		break;
	}
	return p;

}
int multiply(char x,char y)
{
	int minus=0;
	if(x<0)
	{x*=-1;minus++;}

	int sol=a[x][y];
	if(sol<0)
	minus++;
	
	if(minus==2)
	return -1*sol;
	else
	return sol;
}
struct storage
{
	int i;
	int j;
	int k;
};
int main()
{
	int t,t1=1;
	char str[2000050],str1[2000050];
	setup_matrix();
	fstream f,f1;
	f.open("in1");
	f1.open("out1");
	f>>t;
	while(t--)
	{
		
		int l,x;
		//have to be optimized
		//storage m[1000][1000];
	
		f>>l;
		f>>x;
		f>>str;
		
		strcpy(str1,"");
		//construct l*x length string
		for(int i=0;i<x;i++)
		strcat(str1,str);
		
		//now construct the matrix i->place where second substring starts,j->the place where third 			//substring starts
		if(strlen(str1)<3)
		{
			cout<<"Case #"<<t1<<": "<<"NO"<<endl;

		}
		else if(l*x==3)
		{
			if(str1[0]=='i'&&str1[1]=='j'&&str1[2]=='k')
				cout<<"Case #"<<t1<<": "<<"YES"<<endl;
			else
				cout<<"Case #"<<t1<<": "<<"NO"<<endl;


		}
		//the string is completely i's or j's or k's
		else if(strlen(str)==1)
		{
			cout<<"Case #"<<t1<<": "<<"NO"<<endl;

		}
		//check sequentially
		else
		{
			char res=find_int(str1[0]);
			int minus=0;
			int flag=0;
			 for(int i=1;i<l*x-1;i++) //+1 used below
			 {
				flag=0;
				res=(multiply(res,find_int(str1[i])));
				if(res<0)
				{
					res*=-1;
					minus++;
				}
				if(minus%2==0&&res==2&&strlen(str1)-(i+1)>=2) //we have an i and two or more elements after
				{
					//cout<<i;
					int res1=find_int(str1[i+1]);
					int minus1=0;
					//faster computation->multiply in 3's
					
					for(int j=i+2;j<l*x;j++)
					{
						res1=(multiply(res1,find_int(str1[j])));
						if(res1<0)
						{
							res1*=-1;
							minus1++;

						}	
							if(minus1%2==0&&res1==3&&strlen(str1)-(j+1)>=1) //we have an i and two or more elements after
							{
								//cout<<j;
								int res2=find_int(str1[j+1]),minus2=0;
								for(int k=j+2;k<l*x;k++)
								{	
									res2=multiply(res2,find_int(str1[k]));
									if(res2<0)
									{
										res2*=-1;
										minus2++;
									}
								//	cout<<res2<<"kk"<<minus2<<"[]";
									
								}
								if(res2==4&&minus2%2==0)
								//found a case!!!
								{
									flag=1;
									break;	
								}
							}
					}
					if(flag==1)
					break;

				
				}
			 }
			if(flag==1)
			cout<<"Case #"<<t1<<": "<<"YES"<<endl;

			else
			cout<<"Case #"<<t1<<": "<<"NO"<<endl;

		}
		t1++;

		//deallocate

	}
	return 0;
}
