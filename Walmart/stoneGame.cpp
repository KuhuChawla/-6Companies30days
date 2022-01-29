int dp[501][501];
    int solve(int i, int j, vector<int>&piles,int sum){
        if(i>j){
            return 0;
        }
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int p1 = piles[i] + min(solve(i+1,j-1,piles,sum),solve(i+2,j,piles,sum));
        int p2 = piles[j] + min(solve(i,j-2,piles,sum),solve(i+1,j-1,piles,sum));
        int alice = max(p1,p2);
        return dp[i][j]=alice;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int start = 0;
        int end = n-1;
        memset(dp,-1,sizeof dp);
        int sum = accumulate(piles.begin(),piles.end(),0);
        int alice = solve(start,end,piles,sum);
        int bob = sum-alice;
        if(alice>bob){
            return true;
        }
        else{
            return false;
        }
    }