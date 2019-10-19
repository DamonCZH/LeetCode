class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> order;
        for(int i=0;i<=num;i++){
            int count=0;
            numOfOne(i,count);
            order.push_back(count);
        }
        return order;
    }
    
    void numOfOne(int x, int &count){
        if(x==0) return;
        if(x==1) {count++; return;}
        
        if(x%2==1) count++;
        numOfOne(x/2,count);
    }
};

//80 ms	10 MB
