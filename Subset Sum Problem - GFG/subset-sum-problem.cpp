//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   bool possible(int n, int sum , vector<int> &arr, vector<vector<int>>&dp)
   {
       if(sum==0)
       {
           return true;
       }
       if(n==0)
       {
           return false;
       }
       if(dp[n-1][sum]!=-1)
       {
           return dp[n-1][sum];
       }
       if(arr[n-1]<=sum)
       {
          return dp[n-1][sum] =  possible(n-1,sum-arr[n-1],arr,dp) or possible(n-1,sum,arr,dp);
       }
       else if(arr[n-1]>sum)
        return dp[n-1][sum] = possible(n-1,sum,arr,dp);
   }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1, -1));
        return possible(n,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends