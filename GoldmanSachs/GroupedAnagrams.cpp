/// Given an array of strings, return all groups of strings that are anagrams.

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string,vector<string>>AnagMap;
        string temp;
        for(int i = 0 ; i<string_list.size();i++){
            temp= string_list[i];
            sort(string_list[i].begin(),string_list[i].end());
            AnagMap[string_list[i]].push_back(temp);
        }
        vector<vector<string>> sol;
        for(auto i=AnagMap.begin();i!=AnagMap.end();i++){
            sol.push_back(i->second);
        }
        return sol;
        
    }
};
