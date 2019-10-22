class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int dp[100010]={0};int min_price=prices[0];
        for(int i=1;i<prices.size();i++)
            if(min_price<prices[i])
                dp[i]=prices[i]-min_price;
            else
                min_price=prices[i];
        return *max_element(dp,dp+prices.size());
    }
};
//20 ms	10 MB
