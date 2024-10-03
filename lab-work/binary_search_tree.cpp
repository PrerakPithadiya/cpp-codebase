/**
 * @file binary_search_tree.cpp
 * @brief Implementation of a Binary Search Tree (BST) data structure
 *
 * This file contains the implementation of a Binary Search Tree, including
 * node structure, tree operations, and a demonstration in the main function.
 */

#include <iostream>
using namespace std;

/**
 * @struct Node
 * @brief Represents a node in the Binary Search Tree
 *
 * Each node contains an integer value and pointers to its left and right child nodes.
 */
struct Node
{
    int data;    ///< The value stored in the node
    Node *left;  ///< Pointer to the left child node
    Node *right; ///< Pointer to the right child node

    /**
     * @brief Construct a new Node object
     * @param value The integer value to be stored in the node
     */
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

/**
 * @class BST
 * @brief Implements the Binary Search Tree data structure
 *
 * This class provides methods for inserting nodes, searching for values,
 * and performing an in-order traversal of the tree.
 */
class BST
{
private:
    Node *root; ///< Pointer to the root node of the tree

    /**
     * @brief Helper function to insert a new node recursively
     * @param node The current node being examined
     * @param value The value to be inserted
     * @return Node* Pointer to the current node after insertion
     */
    Node *insert(Node *node, int value)
    {
        // If the tree is empty, return a new node
        if (node == nullptr)
        {
            return new Node(value);
        }

        // Otherwise, recur down the tree
        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }

        // Return the unchanged node pointer
        return node;
    }

    /**
     * @brief Helper function to search for a value recursively
     * @param node The current node being examined
     * @param value The value to search for
     * @return true if the value is found, false otherwise
     */
    bool search(Node *node, int value)
    {
        // Base case: root is null or value is present at root
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == value)
        {
            return true;
        }

        // Value is greater than root's value
        if (value > node->data)
        {
            return search(node->right, value);
        }

        // Value is less than root's value
        return search(node->left, value);
    }

    /**
     * @brief Helper function for in-order traversal
     * @param node The current node being visited
     */
    void inOrder(Node *node)
    {
        if (node != nullptr)
        {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

public:
    /**
     * @brief Construct a new BST object
     *
     * Initializes an empty Binary Search Tree
     */
    BST()
    {
        root = nullptr;
    }

    /**
     * @brief Insert a new value into the Binary Search Tree
     * @param value The value to be inserted
     */
    void insert(int value)
    {
        root = insert(root, value);
    }

    /**
     * @brief Search for a value in the Binary Search Tree
     * @param value The value to search for
     * @return true if the value is found, false otherwise
     */
    bool search(int value)
    {
        return search(root, value);
    }

    /**
     * @brief Perform an in-order traversal of the Binary Search Tree
     *
     * Prints the values of the tree in ascending order
     */
    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }
};

/**
 * @brief Main function to demonstrate the Binary Search Tree
 * @return int Exit status of the program
 */
int main()
{
    // Create a new Binary Search Tree
    BST tree;

    // Insert values into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Perform in-order traversal
    cout << "In-order traversal of the BST: ";
    tree.inOrder();

    // Demonstrate search functionality
    int valueToSearch = 40;
    if (tree.search(valueToSearch))
    {
        cout << valueToSearch << " found in the BST." << endl;
    }
    else
    {
        cout << valueToSearch << " not found in the BST." << endl;
    }

    return 0;
}
