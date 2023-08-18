//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
   vector<int> findleader(int a[],int n)
    {
        stack<int> s;
        vector<int> ans;
        for(int i = n-1;i>=0;i--)
        {
            if(s.size()==0)
            {
                s.push(a[i]);
                ans.push_back(a[i]);
            }
            else if(s.size()>0 && a[i]>= s.top())
            {
                while(s.size()>0 && s.top()<=a[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    ans.push_back(a[i]);
                    s.push(a[i]);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> leaders(int a[], int n){
        // Code here
        return findleader(a,n);
        
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends