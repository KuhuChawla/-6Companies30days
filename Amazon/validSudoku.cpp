
int isValid(vector<vector<int>> mat){
        unordered_set<string> set1;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]!=0){
                    string r = "row" + to_string(i) + to_string(mat[i][j]);
                    string c = "col" + to_string(j) + to_string(mat[i][j]);
                    string box = "box" + to_string((i/3)*3 + (j/3)) + to_string(mat[i][j]);
                    
                    if(set1.find(r)!=set1.end() || set1.find(c)!=set1.end() || set1.find(box)!=set1.end()){
                        return false;
                    }
                    else{
                        set1.insert(r);
                        set1.insert(c);
                        set1.insert(box);
                    }
                }
                
            }
        }
        return true;
    }