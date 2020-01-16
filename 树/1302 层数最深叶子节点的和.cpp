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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL) return 0;

        queue<TreeNode*> q;
        int rear=-1, front=-1;
        int last=0;
        int sum_leaf;

        vector<int> temp;
        q.push(root);rear++;
        while(!q.empty()){
            temp.push_back(q.front()->val);
            if(q.front()->left){
                q.push(q.front()->left);
                rear++;
            }
            if(q.front()->right){
                q.push(q.front()->right);
                rear++;
            }
            q.pop();front++;

            if(last==front){
                last=rear;
                if(q.empty())
                    sum_leaf=accumulate(temp.begin(),temp.end(),0);
                temp.clear();                
            }
        }

        return sum_leaf;
    }
};//48 ms	41.6 MB
