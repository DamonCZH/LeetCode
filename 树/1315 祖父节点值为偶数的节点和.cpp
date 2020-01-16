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
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        dfs(root,false,false,sum);
        return sum;
    }

    void dfs(TreeNode* root, bool grandpa, bool father, int& sum){
        if(root==NULL) return;

        bool flag=(root->val%2==0)?true:false;
        dfs(root->left,father,flag,sum);
        if(grandpa)  sum+=root->val;
        dfs(root->right,father,flag,sum);

        return;
    }
};//44 ms	41.1 MB
