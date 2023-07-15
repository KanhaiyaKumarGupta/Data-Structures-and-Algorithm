//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int size)
    {
        // code here.. 
       stack<int> p = s;
       while(!s.empty()) // clear the stack
       {
          s.pop();
       }
       int cnt =0 ;
       int mid = ceil((size)/2);
       stack<int> ans;
        while(!p.empty())
        {
            if(cnt!=mid)
            {
              ans.push(p.top());
            }
            cnt++;
           p.pop();
        }
        while(!ans.empty())
        {
            s.push(ans.top());
            ans.pop();
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends