 void dfsOcean( int i,int j,int prev, vector<vector<int>> &heights, vector<vector<bool>>&ocean){
        int n = heights.size();
        int m = heights[0].size();
        if(i<0 || i>=n || j<0 || j>=m || prev>heights[i][j]){
            return;
        }
        if(ocean[i][j]==true){
            return;
        }
        ocean[i][j]= true;
        dfsOcean(i+1,j,heights[i][j],heights,ocean);
        dfsOcean(i-1,j,heights[i][j],heights,ocean);
        dfsOcean(i,j+1,heights[i][j],heights,ocean);
        dfsOcean(i,j-1,heights[i][j],heights,ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n, vector<bool>(m,false));
        
        for(int i =0 ;i<n;i++){
            dfsOcean(i,0,heights[i][0],heights,pacific);
            dfsOcean(i,m-1,heights[i][m-1],heights,atlantic);
        }
        for(int i =0;i<m;i++){
            dfsOcean(0,i,heights[0][i],heights,pacific);
            dfsOcean(n-1,i,heights[n-1][i],heights,atlantic);
        }
        for(int i =0 ;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
        
    }