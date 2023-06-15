//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int r = 0;
        int c = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    r = i;
                    c = j;
                    q.push({1,{i,j}});
                    break;
                }
            }
        }
        if(q.size()==0) // there is no source
        {
            return false;
        }
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[r][c] = 1;
        int deltarow[] = {-1,0,+1,0};
        int deltacol[] = {0,+1,0,-1};
        while(!q.empty())
        {
            int node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            if(node==2)
            {
                return true;
            }
            for(int i = 0;i<4;i++)
            {
                int nrow = row + deltarow[i];
                int ncol = col + deltacol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==3)
                {
                    vis[nrow][ncol] =1;
                    q.push({3,{nrow,ncol}});
                }
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==2)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends