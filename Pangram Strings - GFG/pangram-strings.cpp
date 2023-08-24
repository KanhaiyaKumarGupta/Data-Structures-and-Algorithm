//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int isPanagram(string s)
	{
	    // Your code goes here 
	   vector<int> freq(26,0);
	   for(int i = 0;i<s.size();i++)
	   {
	       if(s[i]>='A' && s[i]<='Z')
	       {
	           freq[tolower(s[i])-'a']++;
	       }
	       else if(s[i]>='a' && s[i]<='z')
	       {
	           freq[tolower(s[i])-'a']++;
	       }
	       
	   }
	   for(auto it :freq)
	   {
	       if(it==0)
	       {
	           return false;
	       }
	   }
	   return true;
	}

};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		cout << ob.isPanagram(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends