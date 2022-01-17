#include <bits/stdc++.h> 
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

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 


class Solution
{
    public:
    Node* addOne(Node *h) 
    {   if(! h->next){
        h->data = h->data + 1;
        return h;
    }
        
       int j = h->data +add(h->next) ;
       if(j<10) {
           h->data = j;
           return h;
       }
       
           h->data = j%10;
           Node * t = new Node(j/10);
           t->next = h;
           return t;
       
       
    }
    int add(Node *h){
        int j = 0;
        if(! h->next)
             j = h->data+1;
        else 
        j = add(h->next) +  h->data ;
        h->data = j%10;
            return j/10;
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  
