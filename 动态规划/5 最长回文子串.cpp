class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        
        if(n==0){
            string nullstring="";
            return nullstring;
        }
        if(n==1){
            string onestring=s.substr(0,1);
            return onestring;
        }
        
        int dp[n+1][n+1]={0};
        int min=1,max=1;
        
        for(int i=1;i<=n;i++){
            dp[i][i]=1;
            if(i!=n && s[i-1]==s[i])
                dp[i][i+1]=1;
        }

        for(int L=3;L<=n;L++)
            for(int i=1;i+L-1<=n;i++){
                int j=i+L-1;
                if(s[i-1]==s[j-1] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    min=i;max=j;
                }
            }
        
        if(min==1 && max==1){
            for(int i=1;i<n;i++)
                //printf("%d ",i);
                if(dp[i][i+1]==1){
                    min=i;
                    max=i+1;
                    break;
                }
        }
        return s.substr(min-1,max-min+1);
    }
};
//184 ms	13.3 MB
