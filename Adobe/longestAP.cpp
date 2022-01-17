int lengthOfLongestAP(int A[], int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        vector<unordered_map<int,int>>dp(n);
        int sol = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                int diff = A[i] - A[j];
                if(dp[j].find(diff)==dp[j].end()){
                    dp[i][diff]=2;
                }
                else{
                    dp[i][diff] = dp[j][diff]+1;
                }
                sol = max(sol,dp[i][diff]);
            }
        }
        return sol;
    }