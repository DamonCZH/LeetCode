class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        pair<int,int> dp[n+1][n+1];

        int i,j;
        pair<int,int> temp;
        for(i=0;i<n;i++){
            temp.first = piles[i];
            temp.second = 0;
            dp[i][i] = temp;
        }

        for(int l=2;l<=n;l++){
            for(i=0;i+l-1<n;i++){
                j = i+l-1;
                int left  = piles[i]+dp[i+1][j].second;
                int right = piles[j]+dp[i][j-1].second;
                temp.first = max(left, right);
                if(left>right)
                    temp.second = dp[i+1][j].first;
                else
                    temp.second = dp[i][j-1].first;
                dp[i][j] = temp;
            }
        }
        pair<int,int> result = dp[0][n-1];
        if(result.first > result.second)
            return true;
        else
            return false; 
    }
};//28 ms	10.6 MB
