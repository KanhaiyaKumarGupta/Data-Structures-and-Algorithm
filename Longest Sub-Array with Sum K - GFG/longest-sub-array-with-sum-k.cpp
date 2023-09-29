//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        unordered_map<int,int> m;
        int ans = 0;
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum+=a[i];
            if(sum==k)
            {
                ans = max(ans,i+1);
            }
            int target  = sum-k;
             if(m.find(sum)==m.end())
            {
                m[sum] =i;
            }
            if(m.find(target)!=m.end())
            {
                ans = max(ans,i-m[target]);
            }
            
            
        }
        return ans;
        
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends