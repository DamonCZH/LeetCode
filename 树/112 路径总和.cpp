class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int tempsum=0;
        bool flag=false;
        inorder(root, tempsum, sum, flag);
        return flag;
    }
    void inorder(TreeNode* root, int tempsum, int sum, bool& flag){
        if(root==NULL) return;
        tempsum+=root->val;

        inorder(root->left,tempsum,sum,flag);
        if(root->left==NULL && root->right==NULL && tempsum==sum)
            flag=true;
        inorder(root->right,tempsum,sum,flag);

        tempsum-=root->val;
    }
};//	8 ms	20 MB
