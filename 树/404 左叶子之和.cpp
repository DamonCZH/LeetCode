class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        inorder(root, sum);

        return sum;
    }
    void inorder(TreeNode* root, int& sum){
        if(root==NULL) return;

        inorder(root->left,sum);
        if(root->left!=NULL)
            if(root->left->left==NULL && root->left->right==NULL)
                sum+=root->left->val;
        inorder(root->right,sum);
        return;
    }
};
//	12 ms	13.7 MB
