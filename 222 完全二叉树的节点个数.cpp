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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        if(root==NULL) return 0;
        while(!q.empty()){
            if(q.front()->left)  q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();sum++;
        }
        return sum;
    }
};
//48 ms	29.1 MB
