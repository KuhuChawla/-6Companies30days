vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int>res;
        vector<int> seen(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<graph.size();i++){
            if(!checkCourse(i,graph,seen,res)){
                return res;
            }
        }
        return res;
        
    }
    bool checkCourse(int i,vector<vector<int>> &graph,vector<int> &seen,vector<int>&res){
        if(seen[i]==-1){
            res.clear();
            return false;
        }
        if(seen[i]==1){
            return true;
        }
        seen[i]=-1;
        for(int j=0;j<graph[i].size();j++){
            if(!checkCourse(graph[i][j],graph,seen,res)){
                return false;
            }
        }
        seen[i]=1;
        res.push_back(i);
        return true;
        
    }