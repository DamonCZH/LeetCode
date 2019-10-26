/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        
        queue<Node*> q;
        int front=-1,rear=-1,last=0;
        
        q.push(root);rear++;
        vector<int> temp;
        while(!q.empty()){
            temp.push_back(q.front()->val);
            for(int i=0;i<q.front()->children.size();i++)
                if(q.front()->children[i]){
                    q.push(q.front()->children[i]);
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
//180 ms	33.5 MB
