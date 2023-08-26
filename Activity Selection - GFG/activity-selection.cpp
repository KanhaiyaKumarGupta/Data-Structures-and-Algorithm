//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool compare(vector<int> &a , vector<int> &b)
{
    return a[1]<b[1];
}
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<vector<int>> v(n,vector<int>(2,0));
        for(int i = 0;i<n;i++)
        {
            v[i][0] = start[i];
            v[i][1] = end[i];
        }
        sort(v.begin(),v.end(),compare);
        int curr = INT_MIN;
        int ans  = 0;
        for(auto it : v)
        {
            if(it[0]>curr)
            {
                curr = it[1];
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends