#include <utility>

#include "BinarySearchTree.h"


// **Constructors **
BinarySearchTree::BinarySearchTree()
= default;


BinarySearchTree::BinarySearchTree(std::string word) {
    root = new Node;
    root->word = std::move(word);
}


//https://stackoverflow.com/questions/10481982/deep-copy-constructor-for-binary-tree#
Node *copyHelper(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node *newNode = new Node;
    newNode->word = node->word; //copying the word from the current one to the new one
    newNode->left = copyHelper(node->left);
    newNode->right = copyHelper(node->right);

    return newNode;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs) {
    root = copyHelper(rhs.root);
}

BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words) {
    //for each element of the vector
    for (const std::string &x : words) {
        insert(x);
    }
}

//destructor
void destructorHelp(Node *node) {
    if (!node) {
        return;
    }
    destructorHelp(node->left);
    destructorHelp(node->right);
    delete (node);
}

BinarySearchTree::~BinarySearchTree() {
    destructorHelp(root); //use root because it's already in the class
}

// **Methods**
Node *insertHelp(Node *node, const std::string &word) {
    // checking if the node pointer is empty
    if (node == nullptr) {
        //create a new node and put a word in it
        node = new Node;
        // x->y if addressing by pointer
        // x.y if addressing by value
        node->word = word;
        return node;
    }

    if (word < node->word) {
        node->left = insertHelp(node->left, word);
    }

    if (word > node->word) {
        node->right = insertHelp(node->right, word);
    }

    if (word == node->word) {
        node->count++;
    }
    return node;
}

void BinarySearchTree::insert(std::string word) {
    root = insertHelp(root, word);
}

bool existsHelp(Node *node, const std::string &word) {
    if (node == nullptr) {
        return false;
    }
    if (node->word == word) {
        return true;
    }
    if (existsHelp(node->left, word)) {
        return true;
    }
    return existsHelp(node->right, word);
}

bool BinarySearchTree::exists(std::string word) const {
    return existsHelp(root, word); // change this to implement the method, returning true if word exists
    //return false;
}

std::string inorderHelp(Node *node) {
    if (node == nullptr) {
        return "";
    }

    std::string temp;

    temp += inorderHelp(node->left);
    temp += node->word + " ";
    temp += inorderHelp(node->right);


    return temp;
}

std::string BinarySearchTree::inorder() const {
    // back()
    std::string temp = inorderHelp(root);
    if (!temp.empty()) {
        temp.pop_back();
    }

    return temp;
    // change this to return a string representation of the words
    // in the tree inorder.
}

std::string preorderHelp(Node *node) {
    if (node == nullptr) {
        return "";
    }

    std::string temp;

    temp += node->word + " ";
    temp += preorderHelp(node->left);
    temp += preorderHelp(node->right);
    return temp;
}

std::string BinarySearchTree::preorder() const {
    std::string temp = preorderHelp(root);
    if (!temp.empty()) {
        temp.pop_back();
    }

    return temp; // change this to return a string representation of the words
    // in the tree preorder.
}

std::string postorderHelp(Node *node) {
    if (node == nullptr) {
        return "";
    }

    std::string temp;

    temp += postorderHelp(node->left);
    temp += postorderHelp(node->right);
    temp += node->word + " ";
    return temp;
}

std::string BinarySearchTree::postorder() const {
    std::string temp = postorderHelp(root);
    if (!temp.empty()) {
        temp.pop_back();
    }

    return temp; // change this to return a string representation of the words
    // in the tree postorder.
}

// **Operator overloads**


BinarySearchTree &BinarySearchTree::operator+(std::string word) {
    insert(std::move(word));
    return *this; // returns a reference to the modified tree
}

BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &rhs) {
    Node *temp = copyHelper(rhs.root);
    destructorHelp(root);
    root = temp;
    return *this;
}

//getter function for root
Node *BinarySearchTree::getRoot() const {
    return root;
}


