class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> order;
        inorder(root, order);
        int flag=false;
        for(int i=0;i<order.size();i++)
            for(int j=i+1;j<order.size();j++)
                if(order[i]+order[j]==k)
                    flag=true;
        return flag;
    }
    void inorder(TreeNode* root, vector<int>& order){
        if(root==NULL) return;
        inorder(root->left, order);
        order.push_back(root->val);
        inorder(root->right, order);
    }
};//348 ms	25.1 MB
