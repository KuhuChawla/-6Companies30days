bool dfs(vector<vector<char>> & board, string word,int i,int j ,int pos){
        int n = board.size();
        int m = board[0].size();
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        if(pos==word.size()){
            return true;
        }
        if(word[pos]==board[i][j]){
            char temp = board[i][j];
            board[i][j]= '#';
            bool a = dfs(board,word,i,j+1,pos+1);//right
            bool b = dfs(board,word,i+1,j,pos+1);//down
            bool c = dfs(board,word,i,j-1,pos+1);//left
            bool d = dfs(board,word,i-1,j,pos+1);//up
            board[i][j] = temp;
            return a||b||c||d;
        }
        else{
            return false;
        }
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if (board[i][j] == word[0]){
                    if(dfs(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }