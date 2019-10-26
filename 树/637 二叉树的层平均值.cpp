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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root==NULL) return result;
        
        int front=-1,rear=-1,last=0;
        queue<TreeNode*> q;
        q.push(root);rear++;
        
        vector<int> temp;
        while(!q.empty()){
            temp.push_back(q.front()->val);
            if(q.front()->left)  {q.push(q.front()->left);rear++;}
            if(q.front()->right) {q.push(q.front()->right);rear++;}
            q.pop();front++;
            
            if(front==last){
                result.push_back(averageOfLevel(temp));
                last=rear;
                temp.clear();
            }
        }
        
        return result;
    }
    double averageOfLevel(vector<int> x){
        double sum=0.0;
        for(int i=0;i<x.size();i++)
            sum+=x[i];
        return sum/x.size();
    }
};
//28 ms	22 MB
