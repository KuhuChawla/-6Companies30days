vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int top = 0;
        int right = c-1;
        int bottom = r-1;
        int left = 0;
        int direction =1 ;
        vector<int> v;
        while(left<=right && top<=bottom){
            if(direction==1){
                for(int i=left;i<=right;i++){
                    v.push_back(matrix[top][i]);
                }
                top++;
                direction = 2;
            }
            else if (direction==2){
                for(int i = top;i<=bottom;i++){
                    v.push_back(matrix[i][right]);
                }
                right--;
                direction = 3;
                
            }
            else if(direction ==3){
                for(int i=right;i>=left;i--){
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
                direction = 4;
                
            }
            else if(direction == 4){
                for(int i=bottom;i>=top;i--){
                    v.push_back(matrix[i][left]);
                }
                left++;
                direction =1;
            }
        }
         return v;
       
    }