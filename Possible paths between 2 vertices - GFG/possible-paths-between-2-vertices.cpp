//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void possiblepath(int src,int dest,vector<int> &path , vector<vector<int>> &ans , vector<int> adj[] )
    {
        path.push_back(src);
        if(src==dest)
        {
            ans.push_back(path);
        }
        else 
        {
            for(auto it : adj[src])
            {
                possiblepath(it,dest,path,ans,adj);
            }
        }
        path.pop_back();
    }
    
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        vector<vector<int>> ans;
        vector<int>path;
        possiblepath(source,destination,path,ans,adj);
        return ans.size();
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends