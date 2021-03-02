#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) 
{ 
   vector<vector<int>> dp(n , vector<int>(W+1,0));
   
   //base case
   for(int i = wt[0] ; i <= W ; i++)
        dp[0][i] = val[0];
        
    for(int i = 1 ; i < n;i++)
    {
        for(int j = 1 ; j <= W;j++)
        {
            if(j < wt[i])
                dp[i][j] = dp[i-1][j];
            
            else
            {
                dp[i][j] = max(dp[i-1][j] , val[i] + dp[i-1][j-wt[i]]);                
            }
        }
        
        
    }
    
    return dp[n-1][W];
   
}


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
} 