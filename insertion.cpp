// Inserting an element at the last that points to next and an element at the head in the list
//time complexity:O(n).
#include <iostream>
using namespace std;

// Node is a user-defined class
class node {
public:
    int data;
    node* next; // Pointer to the next node

    node(int val) // Constructor
    {
        data = val;
        next = NULL;
    }
};

void insertAthead(node*& head, int val)
{
    node*n=new node(val);// Create a new node with the provided value
    n->next=head;// Set the next pointer of the new node to the current head node
    head=n; // Update the head pointer to the new node
}

void insertAtTail(node*& head, int val)
{
    node*n=new node(val);    // Create a new node with the provided value
    if(head==NULL)     // If the list is empty, make the new node the head
    {
        head=n;          // Make it as the only element and exit from this function.
        return;
    }

    node*temp=head;//temp is pointing at head initally
    while(temp->next!=NULL) // Traverse to the last node
    {
        temp=temp->next;    // Connect the last node to the new node
    }
    temp->next=n;
}

void display(node* head)
{
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->"; // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    cout << "NULL" << endl;
}

bool search(node* head, int key)
{
node*temp=head;
while(temp->next!=NULL)
{
    if(key == temp->data)
    {
        return true;//If key matches then return True
    }
    temp=temp->next;
} 
    return false// If key is not found in the list, return false
}

int main()
{
    node* head = NULL; // Initialize the head pointer to NULL
    insertAtTail(head, 1); // Insert node with value 1 at the tail
    insertAtTail(head, 2); // Insert node with value 2 at the tail
    insertAtTail(head, 3); // Insert node with value 3 at the tail
    insertAthead(head, 4); // Insert node with value 4 at the head
    display(head); // Display the linked list
    
    return 0;
}
/*OUTPUT:
4->1->2->3->NULL.
*/
