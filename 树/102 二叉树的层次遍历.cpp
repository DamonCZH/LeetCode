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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        int rear=-1,front=-1;
        int last=0;
        
        q.push(root);rear++;
        
        vector<int> temp;
        while(!q.empty()){
            //取队首元素 压入子节点 弹出队首元素
            temp.push_back(q.front()->val);
            if(q.front()->left)  {
                q.push(q.front()->left);
                rear++;
            }
            if(q.front()->right) {
                q.push(q.front()->right);
                rear++;
            }
            q.pop();front++;
            
            if(front==last){
                result.push_back(temp);
                temp.clear();
                last=rear;
            }
        }
        return result;
    }
};
//8 ms	13.8 MB
