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
    int most_left,max_depth=1;
    int findBottomLeftValue(TreeNode* root) {
        most_left=root->val;
        inorder(root,1);
        
        return most_left;
    }
    
    void inorder(TreeNode* root, int depth){
        if(root==nullptr) return;
        
        inorder(root->left,depth+1);
        if(depth>max_depth){
            most_left=root->val;
            max_depth=depth;
        }
        inorder(root->right,depth+1);
        return;
    }
};
//24 ms	20.5 MB
