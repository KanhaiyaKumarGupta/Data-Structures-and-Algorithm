//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger( long long int nums[],long long int n,  long long int k) 
{
     vector<long long > ans;
     int i = 0;
     int j = 0;
     list<int> li;
     while(j<n)
     {
         if(nums[j]<0)
         li.push_back(nums[j]);
         if(j-i+1<k)
         {
             j++;
         }
         else if(j-i+1==k)
         {
             while(li.size()>0 && li.back()>=0)
             {
                li.pop_back();
             }
             if(li.size()==0)
             {
                 ans.push_back(0);
             }
             else
             {
                 ans.push_back(li.front());
             }
             if(li.front()==nums[i])
             {
                 li.pop_front();
             }
             i++;
             j++;
         }
     }
     return ans;
     
}