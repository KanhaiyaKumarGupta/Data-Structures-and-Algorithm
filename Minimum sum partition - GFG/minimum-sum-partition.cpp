//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  private:
  void possible(int arr[], int n , int sum ,vector<vector<int>>&dp)
 {
    for(int i = 0;i<n+1;i++)
    {
        dp[i][0] = true;
    }
    for(int i = 1;i<sum+1;i++)
    {
        dp[0][i] = false;
    }
    for(int i = 1;i<n+1;i++)
    {
        for(int j = 1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}
  public:
	int minDifference(int arr[], int n)  { 
	    
	    // Your code goes here
	    int sum = 0;
	    for(int i= 0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
	    possible(arr,n,sum,dp);
	    int res = INT_MAX;
	    vector<int> ans;
	    for(int i = n;i<=n;i++)
	    {
	        for(int j = 0;j<=sum/2;j++)
	        {
	            if(dp[i][j]==true)
	            {
	                res = min(res,sum-2*j);
	            }
	        }
	    }
	    return res;
	    
	   
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends