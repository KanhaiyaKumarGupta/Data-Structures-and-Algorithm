//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
bool checkpalindrome(int i, int n, string &s)
{
    if (i > n / 2)
    {
        return true;
    }
    if (s[i] != s[n - i - 1])
    {
        return false;
    }
    return checkpalindrome(i + 1, n, s);
}
	int isPalindrome(string s)
	{
	   int n = s.size();
       return checkpalindrome(0,n,s);
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends