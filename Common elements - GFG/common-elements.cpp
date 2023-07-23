//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{   private:
    bool dobinarysearch(int A[],int n,int target)
    {
        int low = 0;
        int high= n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(A[mid]==target)
            {
                return true;
                
            }
            if(A[mid]>target)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return false;
        
    }
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
       {
            //code here.
            vector<int> ans;
            set<int> s;
            for(int i = 0; i< n1; i++)
            {
                int target = A[i];
                if(s.find(target)==s.end())
                {
                
                   bool ans1 = dobinarysearch(A,n1,target);
                   bool ans2 =  dobinarysearch(B,n2,target);
                   bool ans3 =  dobinarysearch(C,n3,target);
                   
                
                   if(ans1 & ans2 & ans3)
                   {
                    ans.push_back(A[i]);
                   }
                   s.insert(target);
                }
                
                
            }
            return ans;
       }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends