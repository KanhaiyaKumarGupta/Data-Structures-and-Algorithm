//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string &st)
    {
        // Your code here
        stack<char> s;
        int n = st.size();
        for(int i = 0;i<n;i++)
        {
            char ch = st[i];
            if(s.size()==0 )
            {
                s.push(ch);
            }
            else if(ch=='(' || ch=='{' || ch =='[')
            {
                s.push(ch);
            }
            else if(ch==')' && s.top()=='(')
            {
                s.pop();
            }
            else if(ch=='}' && s.top()=='{')
            {
                s.pop();
            }
            else if(ch==']' && s.top()=='[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        return s.empty();
        
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends