//How to delet  an element  in the link list

#include <iostream>
using namespace std;

// node is a user-defined class
class node
{
public:
    int data;
    node *next;

    node(int val) // constructor
    {
        data = val;
        next = NULL;
    }
};

void insertAthead(node *&head, int val)
{
    node *n = new node(val);  // Create a new node with the provided value
    n->next = head;           // Set the next pointer of the new node to the current head node
    head = n;                 // Update the head pointer to the new node
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);  // Create a new node with the provided value
    if (head == NULL)
    {
        head = n;             // If the list is empty, make the new node the head
        return;
    }

    node *temp = head;
    while (temp->next != NULL) // Traverse to the last node
    {
        temp = temp->next;
    }
    temp->next = n;           // Connect the last node to the new node
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)      // Traverse the list until we reach the end
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteAthead(node *head)
{
    node *todelete = head;    // Create a pointer to the node to be deleted (head node)
    head = head->next;        // Update the head pointer to the next node
    delete todelete;          // Delete the node at the head
}

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;               // If the list is empty, return
    }
    if (head->next == NULL)
    {
        deleteAthead(head);   // If there is only one node (head node), delete it
        return;
    }

    node *temp = head;
    while (temp->next->data != val) // Traverse the list until we find the node with the given value
    {
        temp = temp->next;
    }
    node *todelete = temp->next;     // Create a pointer to the node to be deleted
    temp->next = temp->next->next;   // Update the next pointer of the previous node to skip the node to be deleted
    delete todelete;                 // Delete the node
}

int main()
{
    node *head = NULL;        // Initialize the head pointer to NULL
    insertAtTail(head, 1);    // Insert node with value 1 at the tail
    insertAtTail(head, 2);    // Insert node with value 2 at the tail
    insertAtTail(head, 3);    // Insert node with value 3 at the tail
    insertAthead(head, 4);    // Insert node with value 4 at the head
    display(head);            // Display the linked list
    deletion(head, 2);        // Delete the node with value 2
    display(head);            // Display the updated linked list
    deleteAthead(head);       // Delete the head node
    display(head);            // Display the updated linked list
    return 0;
}
