//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int countsubsets(int n , int sum , int arr[], vector<vector<int>> &dp)
    {
        int mod = 1e9+7;
        if(n==0 && sum==0)
        {
            return 1;
        }
        if(n==0 && sum!=0)
        {
            return 0;
        }
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        if(arr[n-1]<=sum)
        {
            return dp[n][sum] = (countsubsets(n-1,sum-arr[n-1],arr,dp)%mod +countsubsets(n-1,sum,arr,dp)%mod)%mod;
        }
        else if(arr[n-1]>sum)
        {
            return dp[n][sum] = countsubsets(n-1,sum,arr,dp);
        }
        return dp[n][sum]%mod;
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return countsubsets(n,sum,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends