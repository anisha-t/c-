/* node - |previous|data|next| in doubly LL
Creating node for doubly LL
Time Complexity - o(n)*/
#include<iostream>
using namespace std;

class node{
   public:

int data;
node* next;
node* prev;

node(int val){//constructor
          data = val;
          next = NULL;
          prev=NULL;
}};
//insert node at head of dLL
void insertAtHead(node* &head, int val){

 node* n =new node(val);//create a new node to insert          
     
     n->next = head; 

     if(head!=NULL){// change links 
     head->prev = n;
     }
     head = n; //newhead node n 
}
//insert node at random node or tail
void insertAtTail(node* &head, int val){

if(head==NULL){
insertAtHead(head, val);
return ;
}       
node* n = new node(val);// new node n to insert
node* temp = head;// pointer to traverse

  while(temp->next!=NULL){ // run till last node
      temp=temp->next; // go ahead
}
temp->next= n;// temp = last node pointing to n new node
n->prev = temp;// node n ka previos points to temp 
}

// for deleting head node
void deleteAtHead(node* &head){

node* todelete = head;
head= head->next;// assign head to next node      
head->prev = NULL; //new head ka prev ko NULL karo 
delete todelete;   
}
//to delete random node
void deletion(node* &head, int pos){

    if(pos==1){
          deleteAtHead(head);
          return;
    }      

node* temp = head;
int count=1;

while(temp->next!= NULL && count!=pos){
          temp = temp->next;
          count++;
}
temp->prev->next= temp->next;

if (temp->next!= NULL){
   temp->next->prev= temp->prev;
}
delete temp;
}

void display(node* head)//head by value as we have to print it
{
node* temp = head;// again to travese the whole LL
while(temp!=NULL){

   cout<<temp->data<<"->";// print 1st node as temp = head
   temp = temp->next; //for moving to the next node
}
cout<<"NULL"<<endl;
}

int main(){

   node* head = NULL;// compulsory to assign val to the head 
   //pointer as it heads to the starting of LL
insertAtTail(head, 1);
insertAtTail(head, 2);
insertAtTail(head, 3);
insertAtTail(head, 4);
insertAtTail(head, 5);
display(head);

deletion(head,5);
display(head);

deleteAtHead(head);
display(head);
}
