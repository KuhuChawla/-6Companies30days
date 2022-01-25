int sol(int i,int j,int req, const string &str){
    if(j == req+1){
        int y = sol(i,j,j,str);
            if(y == -1){
                return req;
            }
            return -1;
    }
    if(i == str.size()){
        return -1;
    }
    if(j==req){
        int x = 0;
        req++;
        for(int n = i; n<str.size();n++){
            x = x*10 + (str[n]-'0');
            if(x>req+1){
                return -1;
            }
            int y = sol(n+1,x,req,str);
            if(y!=-1){
                return y;
            }
        }
        return -1;
    }
    else if(j<req){
        j = j*10 + (str[i]-'0');
        return sol(i+1,j,req,str);
    }
    return -1;
}
int missingNumber(const string& str)
{
    int x=0;
    for(int i=0;i<str.size();i++){
        x=x*10+(str[i]-'0');
        int y = sol(i+1,0,x+1,str);
        if(y!=-1){
            return y;
        }
    }
    return -1;
      
}