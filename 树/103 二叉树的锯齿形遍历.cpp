class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        int last=0,front=-1,rear=-1;
        
        q.push(root);rear++;
        vector<int> temp;
        while(!q.empty()){
            temp.push_back(q.front()->val);
            if(q.front()->left)  {q.push(q.front()->left);rear++;}
            if(q.front()->right) {q.push(q.front()->right);rear++;}
            q.pop();front++;
            if(front==last){
                result.push_back(temp);
                temp.clear();
                last=rear;
            }
        }
        for(int i=1;i<result.size();i+=2)
            reverse(result[i].begin(),result[i].end());
        return result;
    }
};
//8 ms	13.3 MB
