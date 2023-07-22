//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
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

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    void storenode(Node *head , vector<int> &v)
    {
        Node *temp = head;
        set<int> s;
        while(temp!=NULL)
        {
            if(s.find(temp->data)==s.end())
            {
                s.insert(temp->data);
                v.push_back(temp->data);
            }
            temp =  temp->next;
        }
    }
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
          vector<int> v;
          storenode(head, v);
          Node *dummynode = new Node(0);
          Node * curr  = dummynode;
          int  n = v.size();
          int i = 0;
          while(i!=n)
          {
              curr ->next =  new Node(v[i++]);
              curr = curr->next;
          }
          return dummynode->next;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
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
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends