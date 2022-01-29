void dfs(vector<vector<int>> &isConnected, int i,int j){
        isConnected[i][j]=0;
        for(int x = 0;x<isConnected.size();x++){
            if(isConnected[j][x]==1){
                dfs(isConnected,j,x);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        
        for(int i=0;i<isConnected.size();i++){
            for(auto j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    ans++;
                    dfs(isConnected,i,j);
                }
            }
        }
        return ans;
    }