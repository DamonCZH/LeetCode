class Solution {
public:
    int count=0;
    int P[10];
    bool hashTable[10]={false};
    
    int totalNQueens(int n) {
        generateP(0,n);
        int x=count;
        return x;
    }
    
    void generateP(int index, int n){
        if(index==n){
            bool flag=true;
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                    if(abs(i-j)==abs(P[i]-P[j])){
                        flag=false;
                        break;
                    }
            if(flag) count++;
            return;
        }
        
        for(int x=0;x<n;x++)
            if(!hashTable[x]){
                P[index]=x;
                hashTable[x]=true;
                generateP(index+1,n);
                hashTable[x]=false;
            }
    }
};

//88 ms	8.1 MB
