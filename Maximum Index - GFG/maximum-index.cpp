//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) 
    {
        // code here
        int index = 0;
        int s = 0;
        int e = n-1;
        while(s<e)
        {
            if(arr[s]<=arr[e])
            {
                index = max(index,e-s);
                s++;
                e = n-1;
            }
            else
            {
                e--;
            }
        }
        return index;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends