/* Append last k nodes to the start of LL
if k = 3
find the length of LL
time comp - O(n)*/

#include<iostream>
using namespace std;
// creating a node 
class node{
  public:
    int data;
    node* next ; //pointer to point

    node(int val){ // constructor with 1 argument  
           data = val; // data field =some  val
           next = NULL; // next field = Null As only 1 node 
          // is present in LL
    }
};
//For inserting a new node at the head/begining of LL

void insertAtHead(node* &head, int val){

    node* n = new node(val); // create a new node 
    n->next = head; // assign n ka address i.e next to head 
    head=n;// moving new node n as a head       
}
// For inserting a new node at the end/tail of LL, follow above code

void insertAtTail(node* &head, int val){
// taking head by reference as we have to modify it 

node* n = new node(val);// creating new node, name n to insert 
// creating memory for a node by using new operator .

// if the LL is empty then chevk it first
if (head==NULL){
   head=n;
   return ; // insert newly created node n
}
// pointer temp to traverse the LL, intialize by head 
node* temp = head;
while (temp->next!=NULL){
          temp = temp->next;
}
temp->next = n;// insert new node n at the tail of LL
}
//For printing a LL do the following

void display(node* head)//head by value as we have to print it
{
node* temp = head;// again to travese the whole LL
while(temp!=NULL){

   cout<<temp->data<<"->";// print 1st node as temp = head
   temp = temp->next; //for moving to the next node
}
cout<<"NULL"<<endl;
}
// length of LL
int length(node* &head){         
 int l =0;
node* temp = head;

while(temp!=NULL){//traverse till end 
  l++;
 temp=temp->next;
    }
          return l;
}
// to add or append the k nodes 
node* kappend(node* &head, int k){

node* newHead;
node* newTail;
node* tail = head;// tail og original LL

int l = length(head); // taking length 
k=k%l;// if k > l then 

int count = 1;// counter to count were our pointer is in LL

while(tail->next!=NULL){  //till end 
// placing pointers to there place in LL
      if(count==l-k){ //ex- 6-3 = 3 at 3rd position place newTail
          newTail = tail;
      }    
      if(count==l-k+1){// 6-3+1=4 at 4th position place newaHead
          newHead=tail;
      }
      tail=tail->next;
      count++;
}
newTail->next = NULL;//changing links 
tail->next = head;

return newHead;
}
int main(){
    node* head = NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0; i<6; i++){
    insertAtTail(head, arr[i]); 
     }
    display(head);

    node* newHead = kappend(head, 3);
    display(newHead);
    return 0;    
}