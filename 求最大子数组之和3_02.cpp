//����������������еĺ�  ����ǿ 2016/3/24 
#include<iostream>
using namespace std;
int main()
{
	int Array[100],i=1,dp[100][2],j,MaxSum;
	int s0=-1,e0=-1,s1=0,e1=0;
	cout<<"������һ�����飺";
	cin>>Array[0];
	while(getchar()!='\n')   //�������鲿�֣��ո��ʾ������� 
	{
		cin>>Array[i++];
	}
	int S[i],start[i],end[i],n,finalStart,finalEnd;
	for(n=0;n<i;n++) 
	{
		dp[0][0]=Array[n];
		dp[0][1]=Array[n];
		for(j=1;j<i;j++)
		{
			if(dp[j-1][0]<dp[j-1][1])
			{
				dp[j][0]=dp[j-1][1];
				s0=s1,e0=e1;
			}
			else
			{
				dp[j][0]=dp[j-1][0];
			}
			if(Array[j]<(dp[j-1][1]+Array[(j+n)%i]))
			{
				dp[j][1]=dp[j-1][1]+Array[(j+n)%i];
				e1=j+n;
			}
			else
			{
				dp[j][1]=Array[(j+n)%i];
				s1=e1=j+n;
			}
		}
		if(dp[j-1][0]>dp[j-1][1])
		{
			S[n]=dp[j-1][0];
	      	start[n]=s0;
	 		end[n]=e0;
		}
		else
		{
	        S[n]=dp[j-1][1];
			start[n]=s1;
	 		end[n]=e1;
		}	
	}
	MaxSum=S[0];
	finalStart=start[0];
	finalEnd=end[0];
	for(n=0;n<i;n++)
	{
		if(MaxSum<S[n])
		{
			MaxSum=S[n];
			finalStart=start[n];
			finalEnd=end[n];
		}
	}
	cout<<"���������Ϊ�ͣ�"<<MaxSum<<"\n������������Ϊ��";
	for(int q=finalStart;q<=finalEnd;q++)
	{
		cout<<Array[q%i]<<" ";
	}
	return 0;
 } 
