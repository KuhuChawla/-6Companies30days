int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i =0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2 != 0){
            return 0;
        }
        else{
            int h = sum/2;
            bool dp[N+1][h+1];
            for(int i =0;i<=h;i++){
                dp[0][i] = false;
            }
            for(int j =0;j<=N;j++){
                dp[j][0] = true;
            }
            for(int i =1;i<=N;i++){
                for(int j =1;j<=h;j++){
                    if(arr[i-1]<=j){
                        dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[N][h];
        }
        
    }