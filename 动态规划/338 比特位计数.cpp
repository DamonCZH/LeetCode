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

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);if(num==0) return result;
        result.push_back(1);if(num==1) return result;
        
        int power_now=(int)pow(2,1),power_last=(int)pow(2,0);
        for(int i=2;i<=num;i++){
            if(i==power_now){
                result.push_back(1);
                power_last=power_now;
                power_now*=2;
            }
            else
                result.push_back(1+result[i%power_last]);
        }
        return result;
    }
};
//72 ms	10.1 MB
