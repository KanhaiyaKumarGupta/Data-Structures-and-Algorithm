//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        vector<pair<int,int>> v;
        for(int i = 0;i<N;i++)
        {
            v.push_back({start[i],end[i]});
        }
        unordered_set<int> s;
        sort(v.begin(),v.end()); 
        for(int i = v.size()-1;i>=0;i--)
        {
            if(s.find(v[i].second)==s.end())
            {
                s.insert(v[i].second);
            }
            else 
            {
                int end_date = v[i].second;
                int start_date = v[i].first;
                while(end_date>=start_date)
                {
                    if(s.find(end_date)==s.end())
                    {
                        s.insert(end_date);
                        break;
                    }
                    else
                    {
                        end_date--;
                    }
                }
            }
        }
        return s.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}
// } Driver Code Ends