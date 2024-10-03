/**
 * @file doubly_linked_list_operations.cpp
 * @brief Implementation of various operations on a doubly linked list
 *
 * This file contains functions to perform operations on a doubly linked list,
 * including searching, deleting nodes, and counting nodes.
 */

/**
 * @struct Node
 * @brief Represents a node in the doubly linked list
 *
 * This structure should be defined elsewhere in the code, containing:
 * - int data: The value stored in the node
 * @brief - Node* prev: Pointer to the previous node
 * @brief - Node* next: Pointer to the next node
 */

/**
 * @brief Searches for a value in the doubly linked list
 * @param head Pointer to the head of the list
 * @param value The value to search for
 * @return true if the value is found, false otherwise
 */
bool search(Node *head, int value)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return true; // Node found
        }
        temp = temp->next;
    }
    return false; // Node not found
}

/**
 * @brief Deletes the first node of the doubly linked list
 * @param head Reference to the pointer to the head of the list
 */
void deleteFirst(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != nullptr)
    {
        head->prev = nullptr;
    }

    delete temp;
    cout << "Deleted the first node." << endl;
}

/**
 * @brief Deletes the last node of the doubly linked list
 * @param head Reference to the pointer to the head of the list
 */
void deleteLast(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    Node *temp = head;

    // If there's only one node
    if (temp->next == nullptr)
    {
        delete head;
        head = nullptr;
        cout << "Deleted the last node." << endl;
        return;
    }

    // Traverse to the last node
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // Update the pointers
    temp->prev->next = nullptr;
    delete temp;

    cout << "Deleted the last node." << endl;
}

/**
 * @brief Deletes a specific node with the given value from the doubly linked list
 * @param head Reference to the pointer to the head of the list
 * @param value The value of the node to be deleted
 */
void deleteSpecific(Node *&head, int value)
{
    if (head == nullptr)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    Node *temp = head;

    // Traverse to find the node with the specific value
    while (temp != nullptr && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }

    // Adjust pointers for deletion
    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next; // Update head if deleting the first node
    }

    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Deleted node with value " << value << "." << endl;
}

/**
 * @brief Counts the number of nodes in the doubly linked list
 * @param head Pointer to the head of the list
 * @return The number of nodes in the list
 */
int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

/**
 * @brief Usage Instructions
 *
 * To use these functions:
 * 1. Ensure that the Node structure is properly defined.
 * 2. Create a doubly linked list by initializing a head pointer to nullptr.
 * 3. Use the provided functions as needed:
 *    - search(): To find a value in the list
 *    - deleteFirst(): To remove the first node
 *    - deleteLast(): To remove the last node
 *    - deleteSpecific(): To remove a node with a specific value
 *    - countNodes(): To count the number of nodes in the list
 *
 * Example:
 * @code
 * Node* head = nullptr;
 * // Add nodes to the list (implementation not provided in this file)
 * if (search(head, 5)) {
 *     cout << "Value 5 found in the list." << endl;
 * }
 * deleteFirst(head);
 * deleteLast(head);
 * deleteSpecific(head, 3);
 * cout << "Number of nodes: " << countNodes(head) << endl;
 * @endcode
 */
