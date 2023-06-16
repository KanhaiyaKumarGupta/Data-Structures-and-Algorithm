//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    int trow;
	    int tcol;
	    trow = KnightPos[0]-1;
	    tcol = KnightPos[1]-1;
	    queue<pair<int,pair<int,int>>> q; //{steps,{row||col}}
	    int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        int tr; //targetrow;
        int tc; // target column
        tr = TargetPos[0]-1;
        tc = TargetPos[1]-1;
        vector<vector<int>> vis(N,vector<int>(N,0));
        vis[trow][tcol] =1;
        q.push({0,{trow,tcol}});
        while(!q.empty())
        {
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            if(row==tr && col == tc)
            {
                return steps;
            }
            for(int i = 0;i<8;i++)
            {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<N && vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol] =1;
                    q.push({steps+1,{nrow,ncol}});
                }
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
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends