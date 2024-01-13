class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }

        for(int i=0; i<t.length(); i++){
            if(mp[t[i]] > 0){
                mp[t[i]]--;
            }
        }
        int count =0;
        for(auto it:mp){
            count+=it.second;
        }
        return count;
    }
};

//TC- O(N)+ O(M) 
//SC- O(N)
