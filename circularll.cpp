//How to make circular link ,inset and delete the link and display them
//The time complexity of the display function is :
//O(n)z
#include<iostream>
using namespace std;
//node has two part data and next
class node
{
public:
    int data;
    node* next;
//constructor is used for assigining the inital value
    node(int val)
{
    data = val;  // Assign the value val to the data member variable of the node
    next = NULL; // Set the next pointer to NULL initially
}

};

void insertAtHead(node*& head, int val)
{
    node* n = new node(val);  // Create a new node with the provided value
    if (head == NULL) {       // If the list is empty
        n->next = n;         // Set the next pointer of the new node to itself
        head = n;            // Update the head pointer to point to the new node
        return;              // Exit the function
    }
    node* temp = head;        // Create a temporary pointer to traverse the list
    while (temp->next != head) // Traverse to the last node
    {
        temp = temp->next;
    }
    temp->next = n;           // Connect the last node to the new node
    n->next = head;           // Connect the new node to the head node
    head = n;                 // Update the head pointer to point to the new node
}

void insertAtTail(node*& head, int val)
{
    if (head == NULL) {
        insertAtHead(head, val); // If the list is empty, insert at head
        return;
    }

    node* n = new node(val);  // Create a new node with the provided value
    node* temp = head;        // Create a temporary pointer to traverse the list
    while (temp->next != head) // Traverse to the last node
    {
        temp = temp->next;
    }
    temp->next = n;           // Connect the last node to the new node
    n->next = head;           // Connect the new node to the head node
}


void deleteAtHead(node*& head)
{
    node* temp = head;        // Create a temporary pointer and initialize it with the head pointer
    while (temp->next != head) // Traverse to the last node
    {
        temp = temp->next;
    }

    node* toDelete = head;    // Create a pointer to the node to be deleted (head node)
    temp->next = head->next;  // Update the next pointer of the last node to skip the head node
    head = head->next;        // Update the head pointer to the next node

    delete toDelete;          // Delete the node at the head
}


void deletion(node*& head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head); // If position is 1, delete the head node
        return;
    }
    node* temp = head;
    int count = 1;
    while (count != pos - 1) // Traverse to the node before the position
    {
        temp = temp->next;
        count++;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void display(node* head)
{
    node* temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head); // Traverse the circular list until we reach the head again
    cout << "NULL" << endl;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    display(head);
    insertAtHead(head, 5);
    display(head);
    deletion(head, 4);
    display(head);
    return 0;
}
/*OUTPUT:
5->4->1->2->3->NULL
5->4->1->2->3->NULL
5->4->1->3->NULL*/