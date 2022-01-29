int x[]={-1,0,1,0};
int y[]={0,1,0,-1};
class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> pq;
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    pq.push({i,j});
                }
            }
        }
        if(pq.size()==n*m){
            return -1;
        }
        int dist = 0;
        while(pq.size()){
            int size = pq.size();
            dist++;
            while(size--){
                auto [si,sj] = pq.front();pq.pop();
                for(int i=0;i<4;i++){
                    int newi = si + x[i];
                    int newj = sj + y[i];
                    if(newi>=0 && newi<n && newj>=0 && newj<m && grid[newi][newj]==0){
                        pq.push({newi,newj});
                        grid[newi][newj] = 1;
                    }
                }
            }
        }
        return dist - 1;
    }
};