#include<iostream>
using namespace std;
int bad[101][101][2];
int main()
{	int x,y;
	cin>>x>>y;
	int nb;
	int a,b,c,d;
	cout<<"enter number of bad edges "<<endl;
	cin>>nb;
	while(nb--)
		{	cin>>a>>b>>c>>d;
			if(a==c)
				if(b>d)
					bad[a][d][1]=1;
				else
					bad[a][b][1]=1;
			else if(b==d)
				if(a>c)
					bad[c][b][0]=1;
				else
					bad[a][b][0]=1;
		}
		
	
	int dp[x+2][y+2];
	for(int i=0;i<x+2;i++)
	for(int j=0;j<y+2;j++)
		dp[i][j]=0;
	dp[x][y]=1;
	
	for(int i=x;i>=0;i--)
	{	for(int j=y;j>=0;j--)
		{	if(bad[i][j][0]==1&&bad[i][j][1]==1)
				dp[i][j]=dp[i][j];
			else if(bad[i][j][1]==1)
				dp[i][j]=dp[i][j]+dp[i+1][j];
			else if(bad[i][j][0]==1)
				dp[i][j]=dp[i][j]+dp[i][j+1];
			else
				dp[i][j]=dp[i][j]+dp[i+1][j]+dp[i][j+1];
		}
	}
	cout<<dp[0][0];
	return 0;
}
