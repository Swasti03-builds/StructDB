#include "mukul.h"

int main(){

    vector<int> preorder = {42, 15, 8, 4, 12, 29, 23, 67, 53, 74};

    vector<int> inorder = {12, 4, 8, 15, 23, 29, 42, 53, 67, 74};


    TreeHandler th;
    TreeNode *root = th.FormTree(inorder, preorder);
    cout << "Tree Structure:" << endl;
    th.PrintTree(root);
}

