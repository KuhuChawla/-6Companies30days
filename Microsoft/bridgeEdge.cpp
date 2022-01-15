int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int *arr = new int[V];
        for(int i=0;i<V;i++){
            arr[i]=0;
        }
        queue<int>q;
        q.push(c);
        arr[c]=1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i = 0;i<adj[temp].size();i++){
                if(arr[adj[temp][i]]==0 || adj[temp][i]==d){
                    if(temp == c && adj[temp][i]==d){
                        continue;
                    }
                    else if(adj[temp][i]==d){
                        return 0;
                    }
                    q.push(adj[temp][i]);
                    arr[adj[temp][i]]=1;
                }
            }
        }
        return 1;
    }