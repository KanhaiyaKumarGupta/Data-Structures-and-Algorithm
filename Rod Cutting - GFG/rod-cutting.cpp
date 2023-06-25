//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  int maxrodcut(int n , int price[] , int length[])
  {
      vector<vector<int>> dp(n+1,vector<int>(n+1,0));
      for(int i = 1;i<n+1;i++)
      {
          for(int j = 1;j<n+1;j++)
          {
              if(length[i-1]<=j)
              {
                  dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
              }
              else
              {
                  dp[i][j] = dp[i-1][j];
              }
          }
      }
      return dp[n][n];
  }
  public:
    int cutRod(int price[], int n) {
        //code here
        int length[n];
        for(int i = 0;i<n;i++)
        {
            length[i] = i+1;
        }
        return maxrodcut(n,price,length);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends