//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int count(int m , int n , string &s1 , string &s2)
    {
        if((m==0 && n==0)|| n==0)
        {
            return 1;
        }
        if(m==0)
        {
            return 0;
        }
        if(s1[m-1] == s2[n-1])
        {
            return count(m-1,n-1,s1,s2) + count(m-1,n,s1,s2);
        }
        return count(m-1,n,s1,s2);
    }
    int countWays(string S1, string S2)
    {
        // code here
        int m  = S1.size();
        int n =  S2.size();
        return count(m,n,S1,S2);
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends