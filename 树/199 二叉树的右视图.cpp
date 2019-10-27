class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        int front=-1,rear=-1,last=0;
        
        q.push(root);rear++;
        result.push_back(q.front()->val);
        while(!q.empty()){
            
            if(q.front()->left)  {q.push(q.front()->left);rear++;}
            if(q.front()->right) {q.push(q.front()->right);rear++;}
            q.pop();front++;
            if(front==last && last!=rear){
                result.push_back(q.back()->val);
                last=rear;
            }
        }
        return result;
    }
};
//8 ms	9.6 MB
