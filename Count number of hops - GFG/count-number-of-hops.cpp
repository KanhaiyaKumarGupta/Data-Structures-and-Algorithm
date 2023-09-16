//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<long long> dp(1000001,-1);
class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod  = 1e9+7;
    long long countWays(int n)
    {
        
        // your code here
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        if(n==2)
        {
            return n;
        }
        
        return dp[n] = (countWays(n-1) + countWays(n-2)+ countWays(n-3))%mod;
       


 
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends