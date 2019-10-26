/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        preorder(root,order);
        return order;
    }
    void preorder(TreeNode* root, vector<int>& order){
        if(root==NULL) return;
        
        order.push_back(root->val);
        preorder(root->left,order);
        preorder(root->right,order);
    }
};
//4 ms	9.2 MB
