#include<iostream>
#include<algorithm>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int start,end,i,j,k,n,sum=0,temp;
	while(cin>>n)
	{
		sum=0;
		int flag[n][2];
		for(i=0;i<n;i++)
			cin>>flag[i][0]>>flag[i][1];
		qsort(flag,n,sizeof(flag[0]),cmp);
	/*	for(i=0;i<n;i++)		
		{
			for(j=0;j<n-1;j++)
			{
				if(flag[j][0]>=flag[j+1][0])
				{
					swap(flag[j][0],flag[j+1][0]);
					swap(flag[j][1],flag[j+1][1]);	
				}	
			} 
		}*/
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
				sum+=flag[0][1]-flag[0][0];// sum = 2
				start=flag[0][0];//start = 1
				end=flag[0][1];// end = 3
				continue;// just skip the statement below(do the next one for-loop)
			}
			if(flag[i][0]>end)
			{
				start=flag[i][0];
				end=flag[i][1];
				sum+=end-start;
				continue;
			}
			if(flag[i][1]>end)
			{
				sum+=flag[i][1]-end;
				end=flag[i][1];
				continue;
			}
		}
		cout<<sum<<endl;
		
	}
} 













