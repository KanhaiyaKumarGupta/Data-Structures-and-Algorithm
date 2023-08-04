//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   void fun(stack<int> &s , vector<int> &nums)
   {
       if(s.size()==0)
        {
            return ;
        }
        int num = s.top();
        s.pop();
        fun(s,nums);
        nums.push_back(num);
   }
    void Reverse(stack<int> &s){
        vector<int> nums;
        fun(s,nums);
        int n= nums.size();
        while(n>0)
        {
            s.push(nums[n-1]);
            n--;
        }
        
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends