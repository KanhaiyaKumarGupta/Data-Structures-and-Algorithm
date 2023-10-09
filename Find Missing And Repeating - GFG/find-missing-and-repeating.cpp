//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        map<int,int> m;
        vector<int> ans;
        for(auto it :arr)
        {
            m[it]++;
        }
        for(auto it : m)
        {
            if(it.second==2)
            {
                ans.push_back(it.first);
                break;
            }
        }
        for(int i = 1;i<=n;i++)
        {
            if(m.find(i)==m.end())
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends