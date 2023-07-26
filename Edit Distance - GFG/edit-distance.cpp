//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  int Distance(int m , int n , string s, string t , vector<vector<int>> &dp)
  {
      if(m==0)
      {
          return n;
      }
      if(n==0)
      {
          return m;
      }
      if(dp[m][n]!=-1)
      {
          return dp[m][n];
      }
      if(s[m-1]==t[n-1])
      {
          return dp[m][n] = 0 + Distance(m-1,n-1,s,t,dp);
      }
      return dp[m][n] = 1 + min(Distance(m-1,n-1,s,t,dp),min(Distance(m-1,n,s,t,dp),Distance(m,n-1,s,t,dp)));
  }
  public:
    int editDistance(string s, string t) 
    {
        // Code here
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return Distance(m,n,s,t,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends