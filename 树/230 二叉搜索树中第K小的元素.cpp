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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        inorder(root,order);
        return order[k-1];
    }
    void inorder(TreeNode* root, vector<int>& order){
        if(root==NULL) return;
        
        inorder(root->left,order);
        order.push_back(root->val);
        inorder(root->right,order);
    }
};
//24 ms	21.9 MB
