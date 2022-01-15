void letterRecursive(int a[],int N,int index,string s,vector<string>&v,unordered_map<int,string>&mp){
        if(index>=N){
            v.push_back(s);
            return;
        }
        string temp = mp[a[index]];
        for(int i=0;i<temp.size();i++){
            letterRecursive(a,N,index+1,s+temp[i],v,mp);
        }
        return;
        
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string>v;
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        letterRecursive(a,N,0,"",v,mp);
        return v;
    }