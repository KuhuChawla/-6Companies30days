//Decode the string

string helperFunc(string &s,int &index){
    string ans = "";
    int n = 0;
    while(index<s.length()){
        if(s[index]>='0'&&s[index]<='9'){
            n = n*10+ s[index]-'0';
        }
        else if(s[index]=='['){
            string next = helperFunc(s,++index);
            while(n>0){
                ans+=next;
                n--;
            }
        }
        else if(s[index]==']'){
            return ans;
        }
        else{
           ans.push_back (s[index]);
        }
        index++;
    }
    return ans;
}
    
    
    string decodedString(string s){
        int index = 0;
        return helperFunc(s,index);
    }