//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]!=1 || A[X][Y]!=1)
        {
            return -1;
        }
        vector<vector<int>> vis(N,vector<int>(M,0));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};
        while(!q.empty())
        {
            auto it = q.front();
            int steps = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            if(row==X && col == Y)
            {
                return steps;
            }
            for(int i = 0;i<4;i++)
            {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && A[nrow][ncol]==1 && vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({steps+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends