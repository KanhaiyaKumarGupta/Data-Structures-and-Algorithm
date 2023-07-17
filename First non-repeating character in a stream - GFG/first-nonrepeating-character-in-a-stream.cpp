//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A)
		{
		    // Code here
		    vector<int> freq(26,0);
		    int n = A.size();
		    queue<char> q;
		    string ans ="" ;
		    for(int i = 0;i<n;i++)
		    {
		        freq[A[i]-'a']++;
		        if(freq[A[i]-'a']<=1)
		        {
		            q.push(A[i]);
		        }
		        bool flag = true;
		        while(!q.empty())
		        {
		            char ch = q.front();
		            if(freq[ch-'a']==1)
		            {
		                ans+=ch;
		                flag = false;
		                break;
		            }
		            else
		            {
		                q.pop();
		            }
		        }
		        if( (q.empty()) && (flag == true))
		        {
		            ans +='#';
		        }
		    }
		    return ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends