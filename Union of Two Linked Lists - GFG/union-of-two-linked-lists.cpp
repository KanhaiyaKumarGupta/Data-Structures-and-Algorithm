//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    private:
    void insertnodeintoset(Node * head , set<int> &s)
    {
        Node * temp = head;
        while(temp!=NULL)
        {
            s.insert(temp->data);
            temp = temp->next;
        }
    }
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        Node * dummy = new Node(0);
        Node * curr ;
        curr = dummy;
        set<int> s;
        insertnodeintoset(head1,s);
        insertnodeintoset(head2,s);
       for(auto it : s)
       {
           curr->next = new Node(it);
           curr = curr->next;
       }
       return dummy->next;
        
        
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends