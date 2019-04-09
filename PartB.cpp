#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "BinarySearchTree.h"
#include <algorithm>

using namespace std;

/*
 * outputs the word and the number it occurred in the given file
 */
void output(Node *node) {
    if (!node) {
        return;
    }
    output(node->left);
    cout << node->word << ": " << node->count << endl;

    output(node->right);
}

int main(int argc, char **argv) {
    if (!argv[1]) {
        cerr << "error";
        return -1;
    }

    string new_word;
    BinarySearchTree tree;
    //input file stream
    ifstream file(argv[1]);

    if (!file) {
        cerr << "Can't open " << endl;

    }

    //reads a word from a file
    while (file >> new_word) {
        // https://www.geeksforgeeks.org/removing-punctuations-given-string
        // removing punctuations
        for (unsigned int i = 0, len = new_word.size(); i < len; i++) {
            if (ispunct(new_word[i])) {
                new_word.erase(i--, 1);
                len = new_word.size();
            }
        }

        if (new_word.empty()) {
            continue;
        }

        tree.insert(new_word);
    }

    output(tree.getRoot());

    file.close();

    return 0;
}