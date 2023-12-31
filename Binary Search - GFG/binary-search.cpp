//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  private:
  int search(int arr[], int low, int high , int target)
  {
      if(low>high)
      {
          return -1;
      }
      int mid =  low + (high-low)/2;
      if(arr[mid]==target)
      {
          return mid;
      }
      else if(arr[mid]>target)
      {
          return search(arr,low , mid-1,target);
      }
      return search(arr,mid+1,high,target);
  }
  public:
    int binarysearch(int arr[], int n, int target)
    {
        // code here
        
        return search(arr,0,n-1,target);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends