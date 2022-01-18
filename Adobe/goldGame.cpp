int solve(vector<int> num, vector<vector<int>> &dp, int start, int end){
        if(start>end){
            return dp[start][end] = 0;
        }
        if(start==end){
            return dp[start][end] = num[start];
        }
        if(dp[start][end]!= -1){
            return dp[start][end];
        }
        int left = num[start] + min(solve(num,dp,start+1,end-1), solve(num,dp,start+2,end));
        int right = num[end]+ min(solve(num,dp,start+1,end-1),solve(num,dp,start,end-2));
        return dp[start][end]= max(left,right);
    }
    int maxCoins(vector<int>&A,int n)
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return solve(A,dp,0,n-1);
    }