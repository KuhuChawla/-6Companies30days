int dp[201][201];
    int solve(int index, int n){
        if(index>=n){
            return 0;
        }
        else if(dp[index][n]!=-1){
            return dp[index][n];
        }
        int sol = INT_MAX;
        for(int i = index;i<=n;i++){
            sol = min(sol, i + max(solve(i+1,n),solve(index,i-1)));
        }
        return dp[index][n]= sol;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof dp);
        int ans = solve(1,n);
        return ans;
    }