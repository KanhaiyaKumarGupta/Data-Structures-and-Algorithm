//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long power(int i , int n)
	{
	    long long ans = 1;
	    int N = n;
	    while(N>0)
	    {
	        if(N%2==0)
	        {
	            i = i*i;
	            N = N/2;
	        }
	        else
	        {
	            ans = ans * i;
	            N--;
	        }
	    }
	    return ans;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    for(int i =1 ; i<=m;i++)
	    {
	        int val = power(i,n);
	        if(val == 1ll * m)
	        {
	            return i;
	        }
	        else if(val > 1ll * m)
	        {
	            break;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends