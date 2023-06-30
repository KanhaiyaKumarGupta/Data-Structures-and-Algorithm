//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    private:
    int LCS(int n, int m , string s1, string s2, vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(s1[n-1]==s2[m-1])
        {
            return dp[n][m] =  1 + LCS(n-1,m-1,s1,s2,dp);
        }
        else
        return dp[n][m] =  max(LCS(n,m-1,s1,s2,dp),LCS(n-1,m,s1,s2,dp));
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
          vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
          return LCS(n,m,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends