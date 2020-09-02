PROBLEM:


You are a trader who wants to earn profit by selling stocks. Also, you are given an array 'a' which tells you about the stock price for a particular stock for upcoming n days.

In between these n days, you can make at most 'k' transactions of buying and selling , such that no transaction overlap each other.

Input Format
1st Line: t, number of test cases Next t lines will have, k, denoting the number of transactions n, denoting the length of array 'a' space separated values of array 'a'

Constraints
1<= t,k,n <=100 1<= Ai <= 1000

Output Format
Maximum profit earned by the trader

Sample Input
1 
1 5 23 4 5 9 20
Sample Output
16
Explanation
you will purchase at day 2(Rs 4) and sell at day 5(Rs.20)





SOLUTION:



#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 

int main()
{   
    ll t;
	cin>>t;

	while(t--)
	{
		ll n,i,j,k,ans;
		cin>>k>>n;

		ll a[n];

		for(i=0;i<n;i++)
		cin>>a[i];

		vector<vector<ll>> dp(k+1,vector<ll>(n+1));

		for(i=0;i<=n;i++)
		dp[0][i]=0;

		for(i=0;i<=k;i++)
		dp[i][0]=0;

		for(i=1;i<=k;i++)
		{
			ll ans=INT_MIN;
			for(j=1;j<n;j++)
			{
				ans=max(ans,dp[i-1][j-1]-a[j-1]);
				dp[i][j]=max(dp[i][j-1],a[j]+ans);
			}
		}

		ans=dp[k][n-1];

		cout<<ans<<endl;

	}
    return 0;
}
