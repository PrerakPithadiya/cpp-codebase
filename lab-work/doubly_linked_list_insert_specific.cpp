/**
 * @file doubly_linked_list_insert_specific.cpp
 * @brief Implementation of insertion operations for a doubly linked list
 *
 * This file contains functions to insert nodes before and after specific values
 * in a doubly linked list. It provides detailed implementations for insertBefore
 * and insertAfter operations.
 */

/**
 * @brief Insert a new node before a node with a specific value
 *
 * This function inserts a new node with the given value before the first occurrence
 * of a node with the specified value in the doubly linked list.
 *
 * @param head Reference to the head pointer of the doubly linked list
 * @param specificValue The value to search for in the list
 * @param newValue The value to be inserted in the new node
 *
 * @note If the list is empty or the specific value is not found, appropriate
 *       messages are displayed and no insertion takes place.
 * @note If the insertion happens at the beginning of the list, the head pointer
 *       is updated accordingly.
 */
void insertBefore(Node *&head, int specificValue, int newValue)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;

    // Traverse to find the node with the specific value
    while (temp != nullptr && temp->data != specificValue)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Node with value " << specificValue << " not found." << endl;
        return;
    }

    // Create new node
    Node *newNode = createNode(newValue);

    // Insert before the found node
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != nullptr)
    {
        temp->prev->next = newNode;
    }
    else
    {
        head = newNode; // Update head if inserted at the beginning
    }

    temp->prev = newNode;
    cout << "Inserted " << newValue << " before " << specificValue << "." << endl;
}

/**
 * @brief Insert a new node after a node with a specific value
 *
 * This function inserts a new node with the given value after the first occurrence
 * of a node with the specified value in the doubly linked list.
 *
 * @param head Pointer to the head of the doubly linked list
 * @param specificValue The value to search for in the list
 * @param newValue The value to be inserted in the new node
 *
 * @note If the list is empty or the specific value is not found, appropriate
 *       messages are displayed and no insertion takes place.
 * @note This function does not modify the head pointer, as insertion always
 *       happens after an existing node.
 */
void insertAfter(Node *head, int specificValue, int newValue)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;

    // Traverse to find the node with the specific value
    while (temp != nullptr && temp->data != specificValue)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Node with value " << specificValue << " not found." << endl;
        return;
    }

    // Create new node
    Node *newNode = createNode(newValue);

    // Insert after the found node
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    cout << "Inserted " << newValue << " after " << specificValue << "." << endl;
}

/**
 * @brief Usage Instructions
 *
 * To use these functions:
 * 1. Ensure you have a Node structure defined with 'data', 'next', and 'prev' members.
 * 2. Implement a createNode function that allocates and initializes a new Node.
 * 3. Maintain a head pointer to your doubly linked list.
 * 4. Call insertBefore or insertAfter as needed, providing the necessary parameters.
 *
 * Example:
 *     Node* head = nullptr;
 *     // ... populate the list ...
 *     insertBefore(head, 5, 10);  // Insert 10 before the first occurrence of 5
 *     insertAfter(head, 7, 15);   // Insert 15 after the first occurrence of 7
 */
