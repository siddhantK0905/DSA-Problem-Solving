class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int > mp;
        string res;

        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }

        vector<string>temp(s.size()+1, "");

        for(auto it:mp){
            temp[it.second].append(it.second, it.first);
        }

        for(int i= temp.size()-1; i>0; i--){
            if(!temp[i].empty())
            res.append(temp[i]);
        }
        return res;

    }

};

//TC - O(N)
//SC -O(N)
