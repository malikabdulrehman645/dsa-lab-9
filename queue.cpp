#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TNode {
public:
    char data;
    TNode* left;
    TNode* right;


 TNode(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/*Function to construct the expression tree from postfix expression*/
TNode* constructTree(const string& postfix) {
    stack<TNode*> s;

for (size_t i = 0; i < postfix.size(); ++i) {
    char ch = postfix[i];
    // Rest of your logic


        // If the symbol is an operand, create a node and push it onto the stack
        if (isalnum(ch)) {
            s.push(new TNode(ch));
        } else { // If the symbol is an operator
            TNode* curr = new TNode(ch);

            // Pop two nodes for the operator
            TNode* t2 = s.top(); s.pop();
            TNode* t1 = s.top(); s.pop();

            // Attach them to the current node
            curr->right = t2;
            curr->left = t1;

            // Push the current node back onto the stack
            s.push(curr);
        }
    }

    // The remaining node on the stack is the root of the tree
    return s.top();
}

// Function to perform postorder traversal
void postOrderTraversal(TNode* root) {
    if (root == nullptr) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data;
}

int main() {
    string postfix = "ab+ef*g*-";

    // Construct the expression tree
    TNode* root = constructTree(postfix);

    // Verify the correctness by traversing the tree in postorder
    cout << "Postorder Traversal of the Expression Tree: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
