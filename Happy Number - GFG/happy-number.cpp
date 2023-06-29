//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool findnext(int n)
    {
        if(n==1 || n==7)
        {
            return true;
        }
        if(n<10)
        {
            return false;
        }
        int num = 0;
        while(n!=0)
        {
            int a = n%10;
            num+=a*a;
            n=n/10;
        }
        return findnext(num);
    }
    int isHappy(int n){
        // code here
        return findnext(n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends