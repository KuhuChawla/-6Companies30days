Node* newConstruct(vector<vector<int>> &grid, int rowStart,int rowEnd,int colStart,int colEnd, int factor){
        int sum = 0;
        for(int i=rowStart;i<rowEnd;i++){
            for(int j=colStart;j<colEnd;j++){
                sum+=grid[i][j];
            }
        }
        Node* ans;
        if(sum==0){
            ans = new Node(false,true);
        }
        else if (sum == (factor*factor)){
            ans = new Node(true,true);
        }
        else{
            ans = new Node(false,false);
            factor = factor/2;
            ans->topLeft = newConstruct(grid,rowStart,rowStart+factor,colStart,colStart+factor,factor);
            ans->topRight = newConstruct(grid,rowStart,rowStart+factor,colStart+factor,colEnd,factor);
            ans->bottomLeft= newConstruct(grid,rowStart+factor,rowEnd,colStart,colStart+factor,factor);
            ans->bottomRight = newConstruct(grid,rowStart+factor,rowEnd,colStart+factor,colEnd,factor);
        }
        return ans;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Node* ans = newConstruct(grid,0,n,0,n,n);
        return ans;
    }