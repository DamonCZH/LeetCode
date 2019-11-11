class Solution {
public:
    static const int maxn=100;
    int dp[maxn][maxn]={0};
    int numTrees(int n) {
        return num(1,n);
    }
    int num(int m, int n){
        if(dp[m][n]) return dp[m][n];
        if(m==n){ dp[m][n]=1; return 1;}
        for(int i=m+1;i<n;i++)
            dp[m][n] += num(m,i-1)*num(i+1,n);
        dp[m][n] += (num(m+1,n)+num(m,n-1));
        return dp[m][n];
    }
};
//4 ms	8.7 MB
