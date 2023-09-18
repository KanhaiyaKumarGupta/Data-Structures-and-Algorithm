//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) {
        // code here
        int ans = 0;
        int cnt = 0;
        for(int i = 0;i<31;i++)
        {
            if(n &(1<<i))
            {
                ans =  i+1;
                cnt++;
            }
        }
        if(cnt==1)
        {
            return ans;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends