//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        // code here
         int ans = -1;
        while(n%2==0)
        {
            ans = max(ans,2);
            n = n/2;
        }
        for(int i = 3;i<=sqrt(n);i=i+2)
        {
            while(n%i==0)
            {
                ans = max(ans,i);
                n = n/i;
            }
        }
        if (n > 2)
       {
           ans = max(ans,n);
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends