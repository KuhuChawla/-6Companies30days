string nextPalin(string N) { 
        if(N.size()<=3){
            return "-1";
        }
        string ans;
        int mid = N.size()/2 -1;
        string s = N.substr(0,mid+1);
        int q = s.length();
        int ind = q;
        for(int i = q-1;i>0;i--){
            if(s[i]>s[i-1]){
                ind = i-1;
                break;
            }
        }
        if(ind == q){
            return "-1";
        }
        for(int i = q-1;i>0;i--){
            if(s[i]>s[ind]){
                swap(s[i],s[ind]);
                break;
            }
        }
        reverse(s.begin()+ind+1,s.end());
        ans+=s;
        if(N.size()%2){
            ans += N[N.size()/2];
        }
        reverse(s.begin(),s.end());
        ans+=s;
        return ans;
    }