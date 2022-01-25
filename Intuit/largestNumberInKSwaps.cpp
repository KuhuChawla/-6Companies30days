void findMaxStr(string &str, string &max,int k,int pos){
        if(k==0){
            return ;
        }
        char a = str[pos];
        for(int i = pos+1;i<str.length();i++){
            if(a<str[i]){
                a = str[i];
            }
        }
        if(a != str[pos]){
            k--;
        }
        for(int i = str.length()-1;i>=pos;i--){
            if(str[i] == a){
                swap(str[i],str[pos]);
                if(str>max){
                    max = str;
                }
                findMaxStr(str,max,k,pos+1);
                swap(str[i],str[pos]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       string max = str;
       findMaxStr(str,max,k,0);
       return max;
    }