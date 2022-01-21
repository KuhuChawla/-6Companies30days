 
 //one test case doesn't pass
 pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
         vector<pair<int, int>> arr;
    
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
         
         for(int i=0;i<k;i++){
             pq.push({KSortedArray[i][0], {i, 0}});
         }
         
         while(!pq.empty()){
             int x= pq.top().first;
             int y=pq.top().second.first;
             int m= pq.top().second.second;
             pq.pop();
             arr.push_back({x, y});
             while(m<n-1 && KSortedArray[y][m]==KSortedArray[y][m+1]){
                 m++;
             }
             if(m!=n-1){
                    pq.push({KSortedArray[y][m+1], {y, m+1}});
             }
         }
        
        unordered_map<int, int> mp; 
        int j=0;
        int mn=INT_MAX;
        int l=0;
        int r=0;
        for(int i=0;i<arr.size();i++){
            
            mp[arr[i].second]++;
            
            while(mp.size()>=k){
                if(mn>arr[i].first-arr[j].first){
                    mn=arr[i].first-arr[j].first;
                    l=arr[j].first;
                    r=arr[i].first;
                }
                mp[arr[j].second]--;
                if(mp[arr[j].second]==0)
                    mp.erase(arr[j].second);
                j++;
            }
        }
        
        return {l, r};
    }

    //all test cases passed

    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {  
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       int maxi=INT_MIN,minrange=INT_MAX,start;
       for(int i=0;i<k;i++) 
       {
          pq.push(make_pair(arr[i][0],i));
          maxi=max(maxi,arr[i][0]);
       }
       int a[k]={0};
       while(1)
       {
           pair<int,int> p=pq.top();
           pq.pop();
           int mini=p.first;
           int range=maxi-mini;
           if(range<minrange) 
           {
               start=mini;
               minrange=range;
           }
           a[p.second]++;
           if(a[p.second]==n)
           break;
           pq.push(make_pair(arr[p.second][a[p.second]],p.second));
           maxi=max(maxi,arr[p.second][a[p.second]]);
       }
       return make_pair(start,minrange+start);
   }