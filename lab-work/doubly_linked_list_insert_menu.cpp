/**
 * @file doubly_linked_list_insert_menu.cpp
 * @brief Implementation of a doubly linked list with insertion and display operations
 *
 * This program demonstrates the implementation of a doubly linked list data structure
 * with operations to insert nodes at the beginning and end of the list, display the list,
 * and a menu-driven interface for user interaction.
 */

#include <iostream>
using namespace std;

/**
 * @struct Node
 * @brief Represents a node in the doubly linked list
 *
 * Each node contains an integer data value and pointers to the previous and next nodes.
 */
struct Node
{
    int data;   ///< The data stored in the node
    Node *prev; ///< Pointer to the previous node
    Node *next; ///< Pointer to the next node
};

/**
 * @brief Creates a new node with the given value
 * @param value The integer value to be stored in the new node
 * @return Pointer to the newly created node
 */
Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

/**
 * @brief Inserts a new node at the beginning of the doubly linked list
 * @param head Reference to the pointer to the head of the list
 * @param value The value to be inserted
 */
void insertFirst(Node *&head, int value)
{
    Node *newNode = createNode(value);

    if (head == nullptr)
    { // If the list is empty
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    cout << "Inserted " << value << " at the beginning." << endl;
}

/**
 * @brief Inserts a new node at the end of the doubly linked list
 * @param head Reference to the pointer to the head of the list
 * @param value The value to be inserted
 */
void insertLast(Node *&head, int value)
{
    Node *newNode = createNode(value);

    if (head == nullptr)
    { // If the list is empty
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        { // Traverse to the end
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Inserted " << value << " at the end." << endl;
}

/**
 * @brief Displays the contents of the doubly linked list
 * @param head Pointer to the head of the list
 */
void displayList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

/**
 * @brief Displays the menu options for the user
 */
void menu()
{
    cout << "Menu: " << endl;
    cout << "1. Insert at the beginning" << endl;
    cout << "2. Insert at the end" << endl;
    cout << "3. Display the list" << endl;
    cout << "4. Exit" << endl;
}

/**
 * @brief Main function to demonstrate the doubly linked list operations
 * @return 0 on successful execution
 */
int main()
{
    Node *head = nullptr;
    int choice, value;

    while (true)
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            insertFirst(head, value);
            break;
        case 2:
            cout << "Enter value to insert at the end: ";
            cin >> value;
            insertLast(head, value);
            break;
        case 3:
            cout << "Doubly Linked List: ";
            displayList(head);
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        cout << endl;
    }

    return 0;
}
