class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        vector<int> bina;
        inorder(root, sum, bina);
        return sum%(1000000007);
    }
    void inorder(TreeNode* root, int& sum, vector<int>& bina){
        if(root==NULL) return;
        bina.push_back(root->val);

        inorder(root->left,sum,bina);
        if(root->left==NULL && root->right==NULL)
            sum+=vec2num(bina);
        inorder(root->right,sum,bina);

        bina.pop_back();
    }
    int vec2num(vector<int> bina){
        int temp=0;
        int n=bina.size();
        for(int i=n-1;i>=0;i--)
            temp += pow(2.0,i)*bina[n-1-i];

        return temp;
    }
};//	24 ms	18.8 MB
