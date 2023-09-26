//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<int> minAnd2ndMin(int arr[], int n) {
    int fs = INT_MAX;
    int ans1 = -1;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]<fs)
        {
            fs  = arr[i];
        }
    }
    ans1  = fs;

    // find second smallest
    int ss = INT_MAX;
    int ans = -1;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]<ss &&  arr[i]!=fs && ss>fs)
        {
            ss = arr[i];
            ans  = ss;
        }
    }
    if (ans1 !=-1 && ans !=-1 )
    return {ans1,ans};
    
    return {-1};
}