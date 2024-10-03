/**
 * @file bst_search_algorithm.cpp
 * @brief Implementation of a Binary Search Tree (BST) with search functionality
 *
 * This file contains the implementation of a Binary Search Tree data structure
 * with methods for insertion and searching. It demonstrates the basic operations
 * of a BST and provides a simple interface for users to interact with the tree.
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
 * @brief Represents a Binary Search Tree
 *
 * This class provides methods to insert values into the tree and search for specific values.
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
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }
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
        // Base case: node is null or value is present at node
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == value)
        {
            return true;
        }

        // If value is greater than node's data, search in the right subtree
        if (value > node->data)
        {
            return search(node->right, value);
        }

        // If value is less than node's data, search in the left subtree
        return search(node->left, value);
    }

public:
    /**
     * @brief Construct a new BST object
     */
    BST()
    {
        root = nullptr;
    }

    /**
     * @brief Insert a new value into the BST
     * @param value The value to be inserted
     */
    void insert(int value)
    {
        root = insert(root, value);
    }

    /**
     * @brief Search for a value in the BST
     * @param value The value to search for
     * @return true if the value is found, false otherwise
     */
    bool search(int value)
    {
        return search(root, value);
    }
};

/**
 * @brief Main function to demonstrate searching in the binary search tree
 * @return int Returns 0 upon successful execution
 */
int main()
{
    // Create a new BST object
    BST tree;

    // Insert values into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Demonstrate searching for a value that exists in the tree
    int valueToSearch = 40;
    if (tree.search(valueToSearch))
    {
        cout << valueToSearch << " found in the BST." << endl;
    }
    else
    {
        cout << valueToSearch << " not found in the BST." << endl;
    }

    // Demonstrate searching for a value that does not exist in the tree
    valueToSearch = 90;
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
