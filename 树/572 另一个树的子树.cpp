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
    vector<TreeNode*> target;
    bool isSubtree(TreeNode* s, TreeNode* t) {
        search(s,t->val);
        if(target.empty()) return false;
        bool flag=false;
        for(int i=0;i<target.size();i++)
            flag=flag||isSametree(target[i],t);
        return flag;
    }
    bool isSametree(TreeNode* a, TreeNode* b){
        if(a==nullptr && b==nullptr) return true;
        if(a==nullptr || b==nullptr) return false;
        if(a->val != b->val) return false;
        return isSametree(a->left,b->left) && isSametree(a->right,b->right);
    }
    void search(TreeNode* root,int val){
        if(root==nullptr) return;
        if(root->val==val) target.push_back(root);
        search(root->left,val);
        search(root->right,val);
    }
};
//32 ms	20.9 MB
