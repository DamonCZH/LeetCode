class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> order;
        inorder(root, order);
        int n=order.size();
        int dif=1000000000;
        for(int i=0;i<n-1;i++)
            if(order[i+1]-order[i]<dif)
                dif=order[i+1]-order[i];
        return dif;
    }
    void inorder(TreeNode* root, vector<int>& order){
        if(root==NULL) return;

        inorder(root->left, order);
        order.push_back(root->val);
        inorder(root->right, order);
    }
};//	24 ms	22.5 MB
