class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> order;
        inorder(root, order, result, sum);
        return result;
    }
    void inorder(TreeNode* root, vector<int>& order, vector<vector<int>>& result, int sum){
        if(root==NULL) return;
        order.push_back(root->val);

        inorder(root->left, order, result, sum);
        if(root->left==NULL && root->right==NULL){
            if(sum==accumulate(order.begin(),order.end(),0))
                result.push_back(order);
        }
        inorder(root->right, order, result, sum);
        order.pop_back();
    }
};//	8 ms	20.3 MB
