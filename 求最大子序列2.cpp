//����������������еĺ�  ����ǿ 2016/3/22 
#include<iostream>
using namespace std;
int main()
{
	int Array[100],i=1,dp[100][2],j,S;
	cout<<"������һ�����飺";
	cin>>Array[0];
	while(getchar()!='\n')
	{
		cin>>Array[i++];
	}
	dp[0][0]=Array[0];
	dp[0][1]=Array[0];
	for(j=1;j<i;j++)
	{
		dp[j][0]=max(dp[j-1][0],dp[j-1][1]);
		dp[j][1]=max(Array[j],(dp[j-1][1]+Array[j]));
	}
	S=max(dp[i-1][0],dp[i-1][1]);
	cout<<"��������еĺ�Ϊ��"<<S;
	return 0;
 } 
