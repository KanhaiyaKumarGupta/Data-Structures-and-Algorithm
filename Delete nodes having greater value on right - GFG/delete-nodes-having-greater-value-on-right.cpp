//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    void  solve(Node *head , stack<int> &s)
    {
        while(head!=NULL)
        {
            if(head->data > s.top())
            {
               while( s.size()>0 && s.top()<head->data)
               {
                   s.pop();
               }
                s.push(head->data);
            }
            else
            {
                s.push(head->data);
            }
            head =head->next;
        }
    }
    Node *compute(Node *head)
    {
        // your code goes here
        stack<int> s;
        s.push(head->data);
        solve(head->next,s);
        vector<int> ans;
        while(s.size()!=0)
        {
            ans.push_back(s.top());
            s.pop();
        }
        int i = 0;
        int n = ans.size();
        reverse(ans.begin(),ans.end());
        Node*dummyNode  = new Node(0);
        Node *curr = dummyNode;
        while(i!=n)
        {
            curr->next = new Node(ans[i++]);
            curr = curr->next;
        }
        return dummyNode->next;
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends