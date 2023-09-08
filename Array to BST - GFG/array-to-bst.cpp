//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node (int data)
    {
        this->data = data;
        this->left =NULL;
        this->right =NULL;
    }
};

class Solution {
public:
    Node* createBST(int start,int end,vector<int>&nums)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid = (start + end)/2;
        
        Node * root = new Node(nums[mid]);
        root->left = createBST(start,mid-1,nums);
        root->right = createBST(mid+1,end,nums);
        return root;
    }
    
    void ans(Node *root , vector<int>& nums)
    {
        if(root==NULL)
        {
            return ;
        }
        nums.push_back(root->data);
        ans(root->left,nums);
        ans(root->right,nums);
        
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        Node *root = createBST(0,nums.size()-1,nums);
       vector<int> p;
        ans(root,p);
        return p;
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends