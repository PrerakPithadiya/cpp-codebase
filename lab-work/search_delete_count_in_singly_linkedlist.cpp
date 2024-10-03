/**
 * @file search_delete_count_in_singly_linkedlist.cpp
 * @brief Implementation of various operations on a singly linked list
 *
 * This file contains functions to perform search, deletion, and counting operations
 * on a singly linked list. It includes functions to search for a value, delete nodes
 * from different positions, and count the total number of nodes in the list.
 */

/**
 * @struct Node
 * @brief Represents a node in the singly linked list
 *
 * This structure defines a node in the linked list, containing an integer data value
 * and a pointer to the next node in the list.
 */
struct Node
{
    int data;
    Node *next;
};

/**
 * @brief Searches for a value in the linked list
 *
 * @param head Pointer to the head of the linked list
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
 * @brief Deletes the first node of the linked list
 *
 * @param head Reference to the pointer to the head of the linked list
 */
void deleteFirst(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;

    cout << "Deleted the first node." << endl;
}

/**
 * @brief Deletes the last node of the linked list
 *
 * @param head Reference to the pointer to the head of the linked list
 */
void deleteLast(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == nullptr)
    { // If there's only one node
        delete head;
        head = nullptr;
        cout << "Deleted the last node." << endl;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    cout << "Deleted the last node." << endl;
}

/**
 * @brief Deletes a specific node with the given value from the linked list
 *
 * @param head Reference to the pointer to the head of the linked list
 * @param value The value of the node to be deleted
 */
void deleteSpecific(Node *&head, int value)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    // If the node to be deleted is the head node
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node with value " << value << "." << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    cout << "Deleted node with value " << value << "." << endl;
}

/**
 * @brief Counts the total number of nodes in the linked list
 *
 * @param head Pointer to the head of the linked list
 * @return The number of nodes in the linked list
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
 * @brief Main function to demonstrate the usage of the linked list operations
 *
 * This function should be implemented to create a linked list and showcase the
 * functionality of the above operations. It should include examples of:
 * 1. Creating a linked list
 * 2. Searching for values
 * 3. Deleting nodes (first, last, and specific)
 * 4. Counting nodes
 *
 * @return 0 on successful execution
 */
int main()
{
    // Implementation of main function to demonstrate the usage
    // of the linked list operations goes here
    return 0;
}
