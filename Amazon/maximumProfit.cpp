
class Solution {
  public:
    int maxProfit(int k, int n, int A[]) {
        int arr[k+1][n+1];
        for(int i =0;i<=k;i++){
            arr[i][0]= 0;
        }
        for(int i =0;i<=n;i++){
            arr[0][i]=0;
        }
        for(int i=1;i<=k;i++){
            for(int j = 1;j<n;j++){
                int max_profit = INT_MIN;
                for(int m =0;m<j;m++){
                    max_profit = max(max_profit,A[j]-A[m]+arr[i-1][m]);
                }
                arr[i][j]= max(arr[i][j-1],max_profit);
            }
        }
        return arr[k][n-1];

    }
};