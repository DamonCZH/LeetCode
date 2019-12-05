class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m=s.length();
        int dp[m+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=m;i++){
            dp[i][i]=1;
            if(i!=m){
                if(s[i-1]==s[i])
                    dp[i][i+1]=2;
                else
                    dp[i][i+1]=1;
            }
        }
        
        for(int L=3;L<=m;L++)
            for(int i=1;i+L-1<=m;i++){
                int j=i+L-1;
                if(s[i-1]==s[j-1])
                    dp[i][j]=dp[i+1][j-1]+2;
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        
        return dp[1][m];
    }
};
//76 ms	12.7 MB
