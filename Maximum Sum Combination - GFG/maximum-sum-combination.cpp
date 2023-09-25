//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> s;
        
        pq.push({a[n-1]+b[n-1],{n-1,n-1}});
        s.insert({n-1,n-1});
        vector<int> ans;
        for(int c = 0;c<k;c++)
        {
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.first);
            int i = it.second.first;
            int j = it.second.second;
            
            int sum = a[i-1]+b[j];
            if(s.find({i-1,j})==s.end())
            {
                s.insert({i-1,j});
                pq.push({sum,{i-1,j}});
            }
            
            sum = a[i]+ b[j-1];
            
            if(s.find({i,j-1})==s.end())
            {
                s.insert({i,j-1});
                pq.push({sum,{i,j-1}});
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
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends