/* Find Intersertion point of 2 LL
length of both LL
Time Complexity - O(n)   */

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

// intersecting 2 LL
void intersect(node* &head1, node* &head2, int pos){

     node* temp1 = head1;
     pos--;
     while(pos--){//treverse till position to intersect at that 
          temp1 = temp1->next;
     }     
     node* temp2= head2;
     while(temp2->next!=NULL){
          temp2= temp2->next; //traverse till end 
     }
     temp2->next = temp1; // link to intersect,ex- 10->5  
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

// for finding intersect point 
int intersection(node* &head1, node* &head2){

int l1 =length(head1);
int l2 = length(head2);

int d= 0;
node* ptr1;
node* ptr2;

if (l1>l2){ // finding the larger LL and assign it ptr 1 
     d = l1-l2;   // distance between lengthh of 2 LL  
     ptr1 = head1;// if LL1 > LL2
     ptr2 = head2;     
}
else{
     d= l2-l1;//if LL2>LL1
     ptr1= head2;
     ptr2= head1;     
}
while(d){
 ptr1 = ptr1->next;// traverse LL1 till end 

if(ptr1==NULL){
return -1; // no intersection
 }
 d--;
}
while (ptr1!= NULL && ptr2!= NULL){
if(ptr1==ptr2){
return ptr1->data;
}
ptr1= ptr1->next;
ptr2= ptr2->next;
}
return -1;
}

int main(){

   node* head1 = NULL;// compulsory to assign val to the head 
   //pointer as it heads to the starting of LL
 node* head2 = NULL;

   insertAtTail(head1, 1);    // inserting actual val in data 
   insertAtTail(head1, 2); // field by calling function
   insertAtTail(head1, 3); // insertAtTail()
   insertAtTail(head1, 4);
   insertAtTail(head1, 5);
   insertAtTail(head1, 6);
   display(head1);// call printing function()

insertAtTail(head2, 9);    // inserting actual val in data 
   insertAtTail(head2, 10); // field by calling function
   insertAtTail(head2, 5);
   insertAtTail(head2, 6);
   display(head2);

   intersect(head1, head2, 3);
   display(head1);
   display(head2);

   cout<<intersection(head1, head2)<<endl;
return 0;
}