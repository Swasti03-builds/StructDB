#ifndef MUKUL_H
#define MUKUL_H

#include "projectclasses.h"

class TreeHandler{
public:
    TreeNode* FormTree(vector<int>& inorder, vector<int>& preorder){
        if(inorder.size() == 0 || preorder.size() == 0) return NULL;
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = -1;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == rootVal){
                rootIndex = i;
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());
        root->left = FormTree(leftInorder, leftPreorder);
        root->right = FormTree(rightInorder, rightPreorder);
        return root;
    }

    int TreeDepth(TreeNode* root){
        if(root == NULL) return 0;
        int leftDepth = TreeDepth(root->left);
        int rightDepth = TreeDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
    int TreeDiameter(TreeNode* root){
        if(root == NULL) return 0;
        int leftDepth = TreeDepth(root->left);
        int rightDepth = TreeDepth(root->right);
        int leftDiameter = TreeDiameter(root->left);
        int rightDiameter = TreeDiameter(root->right);
        return max(leftDepth + rightDepth, max(leftDiameter, rightDiameter));
    }
    int TreeLeftRadius(TreeNode* root){
        if(root == NULL) return 0;
        int leftRadius = TreeLeftRadius(root->left);
        return leftRadius + 1;
    }
    int TreeRightRadius(TreeNode* root){
        if(root == NULL) return 0;
        int rightRadius = TreeRightRadius(root->right);
        return rightRadius + 1;
    }

    void ExportToGraphviz(TreeNode* root, const string& filename = "tree.dot") {
        ofstream fout(filename);
        fout << "digraph BinaryTree {\n";
        fout << "    node [shape=circle, style=filled, fillcolor=lightblue, fontname=\"Arial\"];\n";
        fout << "    edge [color=gray50];\n";

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            fout << "    \"" << node << "\" [label=\"" << node->val << "\"];\n";
            if (node->left) {
                fout << "    \"" << node << "\" -> \"" << node->left << "\";\n";
                dfs(node->left);
            }
            if (node->right) {
                fout << "    \"" << node << "\" -> \"" << node->right << "\";\n";
                dfs(node->right);
            }
        };

        dfs(root);
        fout << "}\n";
        fout.close();
        cout << "DOT file generated: " << filename << endl;
    }
    
    void PrintTree(TreeNode* root) {
        ExportToGraphviz(root);
        system("dot -Tpng tree.dot -o tree.png");
        system("xdg-open tree.png");
    }
};




#endif
