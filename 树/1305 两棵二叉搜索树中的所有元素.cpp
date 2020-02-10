class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        inorder(root1, result);
        inorder(root2, result);
        sort(result.begin(),result.end());
        return result;
    }
    void inorder(TreeNode* root, vector<int>& result){
        if(root==NULL) return;
        result.push_back(root->val);
        inorder(root->left,result);
        inorder(root->right,result);
    }
};//	204 ms	60.8 MB
