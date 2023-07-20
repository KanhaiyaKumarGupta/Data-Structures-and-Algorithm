//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids)
    {
        // code here
        stack<int> s;
        for(auto it : asteroids)
        {
            if(s.empty() || it> 0)
            {
                s.push(it);
            }
            else
            {
                while(!s.empty() && s.top()> 0 && s.top()<abs(it))
                {
                    s.pop();
                }
                if(s.empty()|| s.top()<0)
                {
                    s.push(it);
                }
                else if(s.top() == abs(it))
                {
                    s.pop();
                }
            }
        }
        vector<int> ans(s.size(), 0);
        int size = s.size();
        while(!s.empty()){
            ans[--size] = s.top();
            s.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends