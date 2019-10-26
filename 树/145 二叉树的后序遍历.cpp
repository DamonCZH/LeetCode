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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        postorder(root,order);
        return order;
    }
    void postorder(TreeNode* root, vector<int>& order){
        if(root==NULL) return;
        
        postorder(root->left,order);
        postorder(root->right,order);
        order.push_back(root->val);
    }
};
//4 ms	9.4 MB
