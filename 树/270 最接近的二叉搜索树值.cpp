class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        vector<int> order;
        inorder(root, order);
        int min_index=0;
        double dif=10000000000000000000000000.0;
        for(int i=0;i<order.size();i++){
            if(abs(order[i]-target)<dif){
                dif=abs(order[i]-target);
                min_index=i;
            }
        }
        return order[min_index];
    }
    void inorder(TreeNode* root, vector<int>& order){
        if(root==NULL) return;
        inorder(root->left, order);
        order.push_back(root->val);
        inorder(root->right,order);
    }
};//	20 ms	20.9 MB
