//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int n) {
        
        vector<int> ans;
        int carry = 0;
        int cnt = 0;
        for(int i = n-1;i>=0;i--)
        {
            int p;
            if(cnt!=1)
            {
                p = carry + arr[i]+1;
                cnt++;
            }
            else
            {
                p = carry+arr[i];
            }
            
            
            
            carry = p/10;
            
            ans.push_back(p%10);
        }
        
        if(carry!=0)
        {
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends