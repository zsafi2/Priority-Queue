// Name: Zaheer Safi
// Date: 11/06/2023
// CS_251 Project_4 : Priority qeueue implmentation using Binary search tree

#pragma once

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

template<typename T>
class prqueue 
{
private:
    struct NODE 
    {
        int priority;  // used to build BST
        T value;       // stored data for the p-queue
        bool dup;      // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;    // links to linked list of NODES with duplicate priorities
        NODE* left;    // links to left child
        NODE* right;   // links to right child
    };
    NODE* root; // pointer to root node of the BST
    int sz;     // # of elements in the prqueue
    NODE* curr; // pointer to next item in prqueue (see begin and next)
    
public:
   
    // defualt constructor
    prqueue() 
    {
        // set the root, current to nullptr and size equal to zero
        root = nullptr;
        sz = 0;
        curr = nullptr;    
    }

    // this function takes a node as a parameter and deletes all the memeory allocated for it
    void clearTree(NODE* node) 
    {
        // base case until nod is not pointing to null
        if (node != nullptr) 
        {
            // visit and right, left nodes and also visit the links which hold the duplicate priority values
            clearTree(node->left);
            clearTree(node->right);
            clearTree(node->link);
            delete node;
        }
    }
    
    // clear function that calls the clear tree function and sets the root to nullptr
    void clear() 
    {
        // call the clear tree function and delete all the data and memory associated with it
        clearTree(root);
        root = nullptr;  
        sz = 0;      
    }

    // destructor that calls the clearTree function
    ~prqueue() 
    {
        clearTree(root);
    }

    // this function takes a value and a priority from the parameter values creates a node and places the node in the binary search tree
    void enqueue(T value, int priority) 
    {
        // create a new node and set all the defualt values
        NODE* newNode = new NODE;
        // set the priority of new node to the priroity of new node
        newNode->priority = priority;
        // set the value of the new node to the value of new node
        // set the default vlues for the given node
        newNode->value = value;
        newNode->dup = false;
        newNode->parent = nullptr;
        newNode->link = nullptr;
        newNode->left = nullptr;
        newNode->right = nullptr;

        // if root is pointing to null which means that it is the first node
        if (root == NULL)
        {
            // set the root node to the new node and its parent to null and update the size and return
            root = newNode;
            root->parent = nullptr;
            sz++;
            return;
        }
        
        // if it is not the first node
        else
        {
            // set the root to a temperary veriable
            NODE* temp = root;
            
            // continue until the temp veriable is not pointing to null
            while (temp != NULL)
            {
                // if the new nodes priority is the same as the temrary priority
                if (newNode->priority == temp->priority)
                {
                    // update the duplicate values for the node
                    newNode->dup = true;

                    // becuase it is the same priority we make a linked list to the node
                    NODE* current = temp;
                    
                    // get to the end of the linked list 
                    while (current->link != nullptr) 
                    {
                        current = current->link;
                    }

                    // add the new node to the linked list, update the size and return from the funciton
                    current->link = newNode; 
                    newNode->parent = current;
                    newNode->link = nullptr;          
                    sz++;
                    return;
                }

                // else if the new node priroity is less then the temp priority and it has no left node left
                else if((newNode->priority < temp->priority) && (temp->left == NULL))
                {
                    // put the value to the left of the temp veriable, update the parent node and also update the size and return
                    temp->left = newNode;
                    temp->left->parent = temp;
                    sz++;
                    break;
                }

                // if there is a left node to the tempereray veriable
                else if(newNode->priority < temp->priority)
                {
                    // move temperary to the left node
                    temp = temp->left;
                }
                
                // otherwise if the new node prioirty is bigger than the temperary priority
                else if((newNode->priority > temp->priority) && (temp->right == NULL))
                {
                    // put the new node in the right side node of the temprary veriable, update the parent, update the size and return from the function
                    temp->right = newNode;
                    temp->right->parent = temp;
                    sz++;
                    break;
                }

                // else move to the right node
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    // This function finds the node with the minimum (leftmost) priority
    // in a Binary Search Tree (BST).
    NODE* findMin(NODE* node) 
    {
        if (node == nullptr) 
        {
            // If the input node is null, there are no nodes to search.
            // Return null to indicate that no minimum node exists.
            return nullptr;
        }

        NODE* temp = node; // Initialize a temporary pointer to the input node.
        
        // Traverse the left subtree of the BST to find the minimum node.
        while (temp->left != NULL) 
        {
            temp = temp->left;
        }
        
        // Return the leftmost node, which has the smallest priority.
        return temp;
    }

    // This function dequeues (removes and returns) the element with the minimum priority from the priority queue.
    T dequeue() 
    {
        if (root == nullptr) 
        {
            // If the priority queue is empty, return a default-constructed T.
            return T();
        }

        // Find the node with the minimum priority in the priority queue.
        NODE* minNode = findMin(root);
        T data = minNode->value; // Store the data from the minimum node.

        if (minNode->link != nullptr) 
        {
            // If the minimum node has linked nodes with the same priority.
            if (minNode == root) 
            {
                // If the minimum node is the root of the tree.
                NODE* temp = minNode;
                root = minNode->link;
                minNode->link->right = minNode->right;
                minNode->link->left = minNode->left;
                minNode->link->parent = nullptr;
                minNode->link->dup = false;
                sz--;
                delete temp;
                return data;
            } 
            else 
            {
                // If the minimum node is not the root.
                NODE* temp = minNode;
                if (minNode->parent->left == minNode) {
                    minNode->parent->left = minNode->link;
                } else {
                    minNode->parent->right = minNode->link;
                }
                minNode->link->parent = minNode->parent;
                minNode->link->dup = false;
                minNode->link->right = minNode->right;
                minNode->link->left = minNode->left;
                sz--;
                delete temp;
                return data;
            }
        } 
        
        else 
        {
            // If there are no linked nodes with the same priority.
            if (minNode == root) 
            {
                // If the minimum node is the root.
                NODE* temp = root;
                if (minNode->right != nullptr) 
                {
                    root = root->right;
                    delete temp;
                    sz--;
                    return data;
                } 
                else 
                {
                    root = nullptr;
                    delete temp;
                    sz--;
                    return data;
                }
            } 
            else 
            {
                // If the minimum node is not the root.
                if (minNode->right != nullptr) 
                {
                    NODE* temp = minNode;
                    minNode->parent->left = minNode->right;
                    minNode->right->parent = minNode->parent;
                    delete temp;
                    sz--;
                    return data;
                } 
                
                else 
                {
                    NODE* temp = minNode;
                    minNode->parent->left = nullptr;
                    delete temp;
                    sz--;
                    return data;
                }
            }
        }
    }

    // function returns the private veriable size for the class
    int size() 
    { 
        return sz;   
    }
    
    // This recursive function performs an inorder traversal of the BST,
    // writing the priorities and values of each node to the output stream.
    void _recursiveFunction(NODE* node, ostream& output) 
    {
        if (node != nullptr) 
        {
            _recursiveFunction(node->left, output); // Recursively traverse the left subtree.

            // If it's a duplicate node, traverse its linked list
            NODE* current = node;
            while (current != nullptr) 
            {
                output << current->priority << " value: " << current->value << "\n"; // Write priority and value to the output.
                current = current->link; // Move to the next node in the linked list (if it exists).
            }

            _recursiveFunction(node->right, output); // Recursively traverse the right subtree.
        }
    }

    // This function returns a string representation of the BST
    // by invoking the recursive function to perform the traversal.
    string toString() 
    {
        stringstream ss;
        _recursiveFunction(root, ss); // Start the traversal from the root and write results to the stringstream.
        return ss.str(); // Convert the stringstream to a string and return it.
    }

    // This function initializes the internal state for an inorder traversal
    // of the BST. It sets the 'curr' pointer to the leftmost (minimum priority) node.
    void begin() 
    {
        curr = findMin(root); // Start from the leftmost (minimum priority) node in the BST
    }

    // This function retrieves the next inorder node's value and priority and
    // advances the internal state for the next call.
    bool next(T& value, int& priority) 
    {
        if (curr != nullptr) 
        {
            // Retrieve the current node's value and priority
            value = curr->value;
            priority = curr->priority;

            // Move to the next inorder node
            if (curr->link != nullptr) 
            {
                // If the current node has duplicate priorities, move to the next node with the same priority
                curr = curr->link;
            } 
            else 
            {
                // If there are no duplicate priorities, find the next inorder node in the BST
                if (curr->right != nullptr && curr->dup == false) 
                {
                    // If the current node has a right subtree, the next inorder node is the minimum node in the right subtree
                    curr = findMin(curr->right);
                } 
                else if (curr->right == nullptr && curr->dup == false) 
                {
                    // Otherwise, move up the tree until you find an ancestor with a higher priority
                    while (curr->parent != nullptr && curr->parent->right == curr) 
                    {
                        curr = curr->parent;
                    }
                    curr = curr->parent;
                } 
                else if (curr->dup == true) 
                {
                    // If the current node has duplicate priorities and 'dup' is true
                    while (curr->dup == true) 
                    {
                        curr = curr->parent;
                    }
                    
                    if (curr->right != nullptr && curr->dup == false) 
                    {
                        // If the current node has a right subtree, the next inorder node is the minimum node in the right subtree
                        curr = findMin(curr->right);
                    } 
                    else 
                    {
                        while (curr->parent != nullptr && curr->parent->right == curr) 
                        {
                            curr = curr->parent;
                        }
                        curr = curr->parent;
                    }
                }
            }
        }

        if (curr == nullptr) 
        {
            // No more values to return, indicating the end of the inorder traversal
            return false;
        }

        return true; // Indicates there are more values to return
    }

    // This function returns the value of the element with the minimum priority in the priority queue.
    // If the priority queue is empty, it returns a default-constructed T.
    T peek() 
    {
        if (root == nullptr) 
        {
            return T();
        }

        // Find the node with the minimum priority in the priority queue and return its value.
        NODE* minNode = findMin(root);
        T data = minNode->value;
        return data;
    }

    // This function checks if the current priority queue is equal to another priority queue (other).
    // It does so by invoking the 'isEqual' function to compare their contents recursively.
    bool operator==(const prqueue& other) const 
    {
        return isEqual(root, other.root);
    }

    // This function recursively compares two priority queues (node1 and node2) for equality.
    // It checks the priorities, values, and duplicates of nodes, as well as the linked lists, left, and right subtrees.
    bool isEqual(NODE* node1, NODE* node2) const 
    {
        if (node1 == nullptr && node2 == nullptr) 
        {
            return true;
        }
        
        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }

        // Compare the current nodes' priorities, values, and duplicate flags.
        if (node1->priority != node2->priority || node1->value != node2->value || node1->dup != node2->dup) 
        {
            return false;
        }

        // Compare the linked lists if they exist.
        NODE* link1 = node1->link;
        NODE* link2 = node2->link;
        while (link1 && link2) 
        {
            if (link1->priority != link2->priority || link1->value != link2->value || link1->dup != link2->dup) 
            {
                return false;
            }
            link1 = link1->link;
            link2 = link2->link;
        }
        
        if (link1 || link2) 
        {
            return false;
        }

        // Recursively check the left and right subtrees for equality.
        return isEqual(node1->left, node2->left) && isEqual(node1->right, node2->right);
    }

    // This function is used for assignment operator overloading.
    // It clears the current tree and makes a copy of another tree (other),
    // setting all member variables appropriately.
    void preorder(NODE* other) 
    {
        if (other != nullptr) 
        {
            NODE* current = other;
            enqueue(current->value, current->priority);
            if (current->link != nullptr) 
            {
                NODE* temp = current;
                while (temp->link != nullptr) 
                {
                    temp = temp->link;
                    enqueue(temp->value, temp->priority);
                }
            }
            preorder(other->left);
            preorder(other->right);
        }
    }

    // The assignment operator clears the current tree and then copies the content of 'other'.
    prqueue& operator=(const prqueue& other) {
        if (this == &other) 
        {
            // Self-assignment, nothing to do
            return *this;
        }
        clear();
        preorder(other.root);
        sz = other.sz;
        return *this;
    }

    // This function is used for testing the BST. It returns the root node of the tree for testing purposes.
    void* getRoot() 
    {
        return root;
    }

};
