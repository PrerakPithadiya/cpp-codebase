/**
 * @file linked_list_insertion.cpp
 * @brief Implementation of a singly linked list with insertion operations
 *
 * This program demonstrates the implementation of a singly linked list in C++.
 * It includes functions for inserting nodes at the beginning and end of the list,
 * as well as displaying the contents of the list.
 */

#include <iostream>
using namespace std;

/**
 * @struct Node
 * @brief Represents a node in the linked list
 *
 * Each node contains an integer data value and a pointer to the next node.
 */
struct Node
{
    int data;   ///< The data stored in the node
    Node *next; ///< Pointer to the next node in the list
};

/**
 * @class LinkedList
 * @brief Implements a singly linked list
 *
 * This class provides methods for creating and manipulating a singly linked list.
 */
class LinkedList
{
private:
    Node *head; ///< Pointer to the first node in the list

public:
    /**
     * @brief Constructor for the LinkedList class
     *
     * Initializes an empty list with a null head pointer.
     */
    LinkedList()
    {
        head = nullptr;
    }

    /**
     * @brief Creates a new node with the given value
     * @param value The integer value to be stored in the new node
     * @return Pointer to the newly created node
     */
    Node *createNode(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    /**
     * @brief Inserts a new node at the beginning of the list
     * @param value The integer value to be inserted
     *
     * This function creates a new node with the given value and inserts it
     * at the beginning of the list, updating the head pointer accordingly.
     */
    void insertFirst(int value)
    {
        Node *newNode = createNode(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        cout << "Inserted " << value << " at the beginning." << endl;
    }

    /**
     * @brief Inserts a new node at the end of the list
     * @param value The integer value to be inserted
     *
     * This function creates a new node with the given value and inserts it
     * at the end of the list. If the list is empty, the new node becomes the head.
     */
    void insertLast(int value)
    {
        Node *newNode = createNode(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at the end." << endl;
    }

    /**
     * @brief Displays the contents of the linked list
     *
     * This function traverses the list and prints each node's data value,
     * followed by an arrow (->) to indicate the link to the next node.
     * If the list is empty, it prints a message indicating so.
     */
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        cout << "Linked List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

/**
 * @brief Main function implementing a menu-driven interface for the LinkedList
 * @return 0 on successful execution
 *
 * This function creates a LinkedList object and provides a menu-driven interface
 * for the user to perform operations on the list, such as inserting nodes at the
 * beginning or end, displaying the list, and exiting the program.
 */
int main()
{
    LinkedList list;
    int choice, value;

    do
    {
        cout << "\nMenu:\n1. Insert at beginning\n2. Insert at end\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.insertFirst(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertLast(value);
            break;
        case 3:
            list.display();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 4);

    return 0;
}