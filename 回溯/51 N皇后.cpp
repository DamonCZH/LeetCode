class Solution {
public:
    static const int maxn=11;
    bool hashTable[maxn]={false};
    int P[maxn];
    vector<vector<string>> result;
    
    void DFS(int index, int n, vector<string> Strings){
        if(index==n){
            bool flag=true;
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                    if(abs(i-j)==abs(P[i]-P[j])){
                        flag=false;
                        break;
                    }
            if(flag){
                result.push_back(arrToVec(P,n,Strings));
            }
            return;
        }
        for(int i=0;i<n;i++){
            stack<int> q;
            vector<int> m;
            q.push(i);
            m.push_back(i);
            while(!q.empty()){
                temp=q.top();
                m.push_back(temp);
                
                if(m.size()==n)
                m.pop_back();
                q.pop();
                for(int j=0;j<n;j++){
                    q.push(j);
                }
                
            }
        }
        for(int x=0;x<n;x++)
            if(!hashTable[x]){
                P[index]=x;
                hashTable[x]=true;
                DFS(index+1,n,Strings);
                hashTable[x]=false;
            }
    }
    
    vector<string> arrToVec(int* array, int n, vector<string> Strings){
        vector<string> temp;
        for(int i=0;i<n;i++){
            temp.push_back(Strings[array[i]]);
        }
        return temp;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> Strings=generateString(n);        
        //利用DFS生成全排列，判断是否属于解决方案,并累加到permutation
        DFS(0,n,Strings);
        return result;
    }

    vector<string> generateString(int n){
        vector<string> result;
        for(int i=0;i<n;i++){
            string temp;
            for(int j=0;j<n;j++){
                if(j==i)
                    temp.append("Q");
                else 
                    temp.append(".");
            }
            result.push_back(temp);
        }
        return result;
    }
};

//976 ms	444.5 MB
