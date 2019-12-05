class Solution {
public:
    int countSubstrings(string s) {
        int m=s.length();
        int dp[m+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=m;i++){
            dp[i][i]=1;
            if(i!=m){
                if(s[i-1]==s[i])
                    dp[i][i+1]=1;
                else 
                    dp[i][i+1]=0;
            }
        }
            
        for(int L=3;L<=m;L++){
            for(int i=1;i+L-1<=m;i++){
                int j=i+L-1;
                if(s[i-1]==s[j-1] && dp[i+1][j-1]==1)
                    dp[i][j]=1;
            }
        }
        
        int sum=0;
        for(int i=0;i<=m;i++)
            for(int j=i;j<=m;j++)
                sum+=dp[i][j];
        
        return sum;
    }
};
//20 ms	12.8 MB
