//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
    
        int res = 0;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    int cnt = 0;
                    for(int k = -1;k<=1;k++)
                    {
                        for(int l = -1;l<=1;l++)
                        {
                            int nrow = i+k;
                            int ncol = j + l;
                            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && mat[nrow][ncol]==0)
                            {
                                cnt++;
                            }
                        }
                    }
                    if(cnt!=0 && cnt%2==0)
                    {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends