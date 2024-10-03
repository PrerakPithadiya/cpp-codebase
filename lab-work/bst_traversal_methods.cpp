/**
 * @file bst_traversal_methods.cpp
 * @brief Implementation of a Binary Search Tree (BST) with traversal methods
 *
 * This file contains the implementation of a Binary Search Tree data structure
 * along with its traversal methods (in-order, pre-order, and post-order).
 * It demonstrates the creation, insertion, and traversal of a BST.
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
 * This class provides methods for inserting nodes and performing various traversals.
 */
class BST
{
private:
    Node *root; ///< Pointer to the root node of the BST

    /**
     * @brief Perform an in-order traversal of the BST
     * @param node Pointer to the current node being visited
     *
     * Traversal order: Left -> Root -> Right
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

    /**
     * @brief Perform a pre-order traversal of the BST
     * @param node Pointer to the current node being visited
     *
     * Traversal order: Root -> Left -> Right
     */
    void preOrder(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    /**
     * @brief Perform a post-order traversal of the BST
     * @param node Pointer to the current node being visited
     *
     * Traversal order: Left -> Right -> Root
     */
    void postOrder(Node *node)
    {
        if (node != nullptr)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

public:
    /**
     * @brief Construct a new BST object
     *
     * Initializes an empty BST with a null root.
     */
    BST()
    {
        root = nullptr;
    }

    /**
     * @brief Insert a new node into the BST
     * @param node Pointer to the current node being compared
     * @param value The value to be inserted
     * @return Node* Pointer to the newly inserted node or the existing node
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
     * @brief Public method to insert a value into the BST
     * @param value The value to be inserted
     */
    void insert(int value)
    {
        root = insert(root, value);
    }

    /**
     * @brief Public method to perform an in-order traversal of the BST
     *
     * Prints the values of the BST in ascending order.
     */
    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }

    /**
     * @brief Public method to perform a pre-order traversal of the BST
     *
     * Prints the values of the BST in pre-order sequence.
     */
    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }

    /**
     * @brief Public method to perform a post-order traversal of the BST
     *
     * Prints the values of the BST in post-order sequence.
     */
    void postOrder()
    {
        postOrder(root);
        cout << endl;
    }
};

/**
 * @brief Main function to demonstrate the BST traversal methods
 * @return int Returns 0 upon successful execution
 *
 * This function creates a BST, inserts values, and demonstrates
 * the three traversal methods: in-order, pre-order, and post-order.
 */
int main()
{
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal: ";
    tree.inOrder();

    cout << "Pre-order traversal: ";
    tree.preOrder();

    cout << "Post-order traversal: ";
    tree.postOrder();

    return 0;
}
