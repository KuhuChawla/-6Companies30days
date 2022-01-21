
// time complexity O(n^2) passes 112 test cases out of 123

int helper(int A[],int B[], int n,int m){
      int dp[n+1][m+1];
      for(int i =0;i<=n;i++){
          for(int j=0;j<=m;j++){
              if(i==0 || j==0){
                  dp[i][j]=0;
              }
              else{
                  if(A[i-1]==B[j-1]){
                      dp[i][j] = 1+ dp[i-1][j-1];
                  }
                  else{
                      dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                  }
              }
          }
      }
      return dp[n][m];
  }
    int minInsAndDel(int A[], int B[], int N, int M) {
        return N+M - 2*helper(A,B,N,M);
    }

//optimised solution with O(NlogN)

int helper(vector<int>vec){
      vector<int> res;
      for(int i=0;i<vec.size();i++){
          auto it = lower_bound(res.begin(),res.end(),vec[i]);
          if(it == res.end()){
              res.push_back(vec[i]);
          }
          else{
              *it = vec[i];
          }
      }
      return res.size();
  }
    int minInsAndDel(int A[], int B[], int N, int M) {
        unordered_map<int,int>mp;
        for(int i=0; i<M; i++){
            mp[B[i]]++;
        }
        vector<int>vec;
        for(int i=0; i<N; i++){
            if(mp.find(A[i]) != mp.end()){
                vec.push_back(A[i]);
            }
        }
        return N+M - 2*helper(vec);
    }