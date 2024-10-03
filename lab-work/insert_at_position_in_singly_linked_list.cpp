/**
 * @file insert_at_position_in_singly_linked_list.cpp
 * @brief Implementation of functions to insert nodes in a singly linked list.
 */

/**
 * @struct Node
 * @brief Represents a node in a singly linked list.
 *
 * This structure defines a node that contains an integer data value and a pointer to the next node.
 */
struct Node
{
    int data;   /**< The data stored in the node */
    Node *next; /**< Pointer to the next node in the list */
};

/**
 * @brief Inserts a new node after a node with a specific value in the linked list.
 *
 * This function traverses the linked list to find a node with the target value.
 * If found, it inserts a new node with the given new value immediately after it.
 *
 * @param head Pointer to the head of the linked list.
 * @param targetValue The value to search for in the list.
 * @param newValue The value to be inserted in the new node.
 *
 * @note If the target value is not found, a message is printed to the console.
 * @note The function assumes that the Node structure is properly defined.
 */
void insertAfter(Node *head, int targetValue, int newValue)
{
    Node *temp = head;

    // Traverse the list to find the target value
    while (temp != nullptr && temp->data != targetValue)
    {
        temp = temp->next;
    }

    // If target value not found
    if (temp == nullptr)
    {
        cout << "Target value " << targetValue << " not found in the list." << endl;
        return;
    }

    // Create a new node and insert it after the found node
    Node *newNode = new Node();
    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Inserted " << newValue << " after " << targetValue << "." << endl;
}

/**
 * @brief Inserts a new node before a node with a specific value in the linked list.
 *
 * This function handles three cases:
 * 1. If the list is empty, it prints a message.
 * 2. If the target value is in the head node, it inserts the new node at the beginning.
 * 3. For other cases, it traverses the list to find the node before the target value and inserts the new node.
 *
 * @param head Reference to the pointer to the head of the linked list.
 * @param targetValue The value to search for in the list.
 * @param newValue The value to be inserted in the new node.
 *
 * @note If the target value is not found, a message is printed to the console.
 * @note The function assumes that the Node structure is properly defined.
 */
void insertBefore(Node *&head, int targetValue, int newValue)
{
    // Case 1: Empty list
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    // Case 2: Target value is in the head node
    if (head->data == targetValue)
    {
        Node *newNode = new Node();
        newNode->data = newValue;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << newValue << " before " << targetValue << " (head node)." << endl;
        return;
    }

    // Case 3: Target value is not in the head node
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != targetValue)
    {
        temp = temp->next;
    }

    // If target value not found
    if (temp->next == nullptr)
    {
        cout << "Target value " << targetValue << " not found in the list." << endl;
        return;
    }

    // Create a new node and insert it before the found node
    Node *newNode = new Node();
    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Inserted " << newValue << " before " << targetValue << "." << endl;
}

/**
 * @brief Main function to demonstrate the usage of insertAfter and insertBefore functions.
 *
 * This function should create a linked list, perform insertions using the above functions,
 * and display the results.
 *
 * @return 0 on successful execution.
 */
int main()
{
    // TODO: Implement main function to demonstrate the usage of insertAfter and insertBefore
    return 0;
}