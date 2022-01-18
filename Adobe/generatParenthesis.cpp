vector<string> v;
    void generateP(string&s,int start, int end){
        if(start == 0 && end==0){
            v.push_back(s);
            return;
        }
        if(start>0){
            s.push_back('(');
            generateP(s,start-1,end);
            s.pop_back();
        }
        if(end>0){
            if(start<end){
                s.push_back(')');
                generateP(s,start,end-1);
                s.pop_back();
            }
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        string s = "";
        generateP(s,n,n);
        return v;
    }