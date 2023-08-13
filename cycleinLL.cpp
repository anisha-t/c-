/* Detect and remove cycle in LL based no floyd's , hare and 
tortoise algo.
Time Complexity:
O(n)  
 */
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
// TO FORM A CYCLE IN LL

void makecycle(node* &head, int pos){

    node* temp= head;
    node* startNode; //variable to store a start of forming of
    //cycle

    int count = 1; // running count till it becomes = to pos
    while ( temp->next != NULL ){// run till last node

          if(count==pos){
               startNode = temp;   
          }
          temp=temp->next;// last node 
          count++;
    }       
    temp->next = startNode;//join last node to that node to make
    //a cycle .
}
// to detect the cycle in LL
bool detectcycle(node* &head ){
// intalize 2 pointers slow = tortoise and fast = hare
     node* slow = head;
     node* fast = head;

     while(fast!= NULL && fast->next!=NULL){
// slow will run 1 step and fast will run 2 step 
          slow = slow->next;
          fast = fast->next->next;

          if(fast==slow){ // if both the pointers come on same
          //node then that means that cycle is present in LL
                    return true;
          }
     }    return false;  
}
// to remove the cycle from LL

void removeCycle(node* &head){

 // intalize 2 pointers slow = tortoise and fast = hare
     node* slow = head;
     node* fast = head;
do {
     slow = slow->next;
    fast = fast->next->next;      
}     
while(slow!= fast);// to detect the cycle till here

fast  = head; // move fast to to the head node and keep slow 
//to that node only
while(slow->next != fast->next){// move both the nodes by 1 step only

slow = slow->next;
fast = fast->next;
}
slow->next = NULL; //remove the cycle   
}
int main(){

   node* head = NULL;// compulsory to assign val to the head 
   //pointer as it heads to the starting of LL

   insertAtTail(head, 1);    // inserting actual val in data 
   insertAtTail(head, 2); // field by calling function
   insertAtTail(head, 3); // insertAtTail()
   insertAtTail(head, 4);
   insertAtTail(head, 5);
   insertAtTail(head, 6);
   display(head);// call printing function()

makecycle(head, 3);

cout<<detectcycle(head)<<endl;
removeCycle(head);
display(head);
 
 return 0;
}


/*The output of the code will be:

1->2->3->4->5->6->3->NULL
1

1->2->3->4->5->6->NULL*/