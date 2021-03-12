#include<iostream>
#include<algorithm>
using namespace std;

int cmp(const void *a,const void *b)// this is for quick sort
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int left,right;
	int i,j,k,n,sum=0,temp;
	
	while(cin>>n)
	{
		sum=0;
		int flag[n][2];
		for(i=0;i<n;i++)
		{
		
			cin>>flag[i][0]>>flag[i][1];
		}
		
		qsort(flag,n,sizeof(flag[0]),cmp); // quick sort algorithm
		
		for(i=0; i<n; i++)
		{
			if(i==0) // set initial value
			{
				sum = flag[0][1] - flag[0][0];// sum = 2
				left = flag[0][0]; //left = 1
				right = flag[0][1]; //right = 3
				continue;
			}
			if(flag[i][0] > right) // if the new line completely out of the range of the previous one
			{
				left = flag[i][0];
				right = flag[i][1];
				sum += right - left;
				continue;
			}
			if(flag[i][1] > right) // if the new line's right-end-value out of range of the previous one, but left-end-value not
			{
				sum += flag[i][1] - right;
				left = flag[i][0];
				right = flag[i][1];
				continue;
			}
		}
		
		cout << sum << endl;
	}
	return 0;
}
