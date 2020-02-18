class Solution {
public:
    vector<vector<int>> result;
    vector<int> order;
    vector<string> binaryTreePaths(TreeNode* root) {
        inorder(root);
        return int2str(result);
    }
    void inorder(TreeNode* root){
        if(root==NULL) return;

        order.push_back(root->val);
        inorder(root->left);
        if(root!=NULL && root->left==NULL && root->right==NULL) result.push_back(order);
        inorder(root->right);
        order.pop_back();
    }
    vector<string> int2str(vector<vector<int>> result){
        vector<string> result_string;
        string vec="->";
        int n=result.size();
        for(int i=0;i<n;i++){
            int m=result[i].size();
            string temp="";
            for(int j=0;j<m;j++){
                temp+=to_string(result[i][j]);
                if(j!=m-1) temp+=vec;
            }
            result_string.push_back(temp);
        }
        return result_string;
    }
};//8 ms	11.5 MB
