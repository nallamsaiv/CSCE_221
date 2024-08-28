#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

#ifndef ASCENDING_PATHS

// You can create helper functions for count ascending paths if required here

// returns a pointer to the left child of the node n
Node* left_child_ascending(Node* n){
    return n->left;
}

// returns a pointer to the right child of the node n
Node* right_child_ascending(Node* n){
    return n->right;
}

// returns true if the node n is a leaf
bool is_leaf_ascending(Node* n){
    if(left_child_ascending(n) == nullptr && right_child_ascending(n) == nullptr){
        return true;
    }
    return false;
}


int countAscendingPaths(Node* root){
    int count = 0;

    // checks if the root is nullpointer which means a path was not reached
    if(root == nullptr){
        return 0;
    }

    // checks if root is a leaf which means the end of the path is reached successfully which would mean that a path can be added
    if(is_leaf_ascending(root)){
        return 1;
    }

    // checks if the path should continue if the path were to go to the left child
    if(left_child_ascending(root) != nullptr){
        if(left_child_ascending(root)->data > root->data){
            count += countAscendingPaths(left_child_ascending(root));
        }
    }

    // checks if the path should continue if the path were to go to the right child
    if(right_child_ascending(root) != nullptr){
        if(right_child_ascending(root)->data > root->data){
            count += countAscendingPaths(right_child_ascending(root));
        }
    }

    // returns count at the end based on the above conditions
    return count;
}

#endif

#ifndef LEFT_LEAVES

// You can create helper functions for sum of left leaves if required here

// returns a pointer to the left child of the node n
Node* left_child_sum(Node* n){
    return n->left;
}

// returns a pointer to the right child of the node n
Node* right_child_sum(Node* n){
    return n->right;
}

// returns true if the node n is a leaf
bool is_leaf_sum(Node* n){
    if(left_child_sum(n) == nullptr && right_child_sum(n) == nullptr){
        return true;
    }
    return false;
}


int sumOfLeftLeaves(Node* root) {
    int sum = 0;

    // checks if the root is nullpointer which means there is no left child in this path
    if(root == nullptr){
        return 0;
    }

    // checks if the left child is a leaf, if yes then sum gets incremented by that number
    if(left_child_sum(root) != nullptr){
        if(is_leaf_sum(left_child_sum(root))){
            sum += left_child_sum(root)->data;
        }
    }

    // performs recursion
    sum += sumOfLeftLeaves(left_child_sum(root));
    sum += sumOfLeftLeaves(right_child_sum(root));

    // returns sum based on the conditions above
    return sum;
}

#endif

#ifndef TEST_MODE
int main() {
    cout << "Sample Test case 1" << endl;
    {
        Node root(3);
        Node left(4), right(5);
        Node leftLeft(7), leftRight(8), rightLeft(9), rightRight(10);
        Node leftRightLeft(3), rightLeftRight(12);

        root.left = &left, root.right = &right;
        left.left = &leftLeft, left.right = &leftRight, right.left = &rightLeft, right.right = &rightRight;
        leftRight.left = &leftRightLeft, rightLeft.right = &rightLeftRight;

        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 10" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 3" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }
    cout << endl;
    cout << endl;

    cout << "Sample Test case 2" << endl;
    {
        Node root(3);
        Node right(4);
        Node rightLeft(5), rightRight(16);
        Node rightRightLeft(14);

        root.right = &right;
        right.left = &rightLeft, right.right = &rightRight;
        rightRight.left = &rightRightLeft;

        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 19" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 1" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }

    cout << endl;
    cout << endl;

    cout << "Sample Test case 3" << endl;
    {
        Node root(3);
        Node right(8);
        Node rightLeft(7), rightRight(16);
        Node rightRightRight(14);

        root.right = &right;
        right.left = &rightLeft, right.right = &rightRight;
        rightRight.right = &rightRightRight;

        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 7" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 0" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }

    cout << endl;
    cout << endl;

    cout << "Sample Test case 4" << endl;
    {
        Node root(3);
        Node right(8);
        Node left(4);
        Node rightLeft(7), rightRight(16);
        Node rightRightRight(17);

        root.right = &right;
        root.left = &left;
        right.left = &rightLeft, right.right = &rightRight;
        rightRight.right = &rightRightRight;

        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 11" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 2" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }

    cout << endl;
    cout << endl;

    cout << "Sample Test case 5" << endl;
    {
        Node root(3);
        Node right(3);
        Node left(4);

        root.right = &right;
        root.left = &left;

        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 4" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 1" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }

    cout << endl;
    cout << endl;

    cout << "Sample Test case 6" << endl;
    {
        Node root(3);

        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 0" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 1" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }


    cout << endl;
    cout << endl;

    cout << "Sample Test case 7" << endl;
    {
        Node root(3);
        Node right(2);

        root.right = &right;

        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 0" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 0" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }
}
#endif