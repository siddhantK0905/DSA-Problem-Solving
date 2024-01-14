class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>mp1;
        unordered_map<char, int> mp2;

        for(int i=0; i<word1.length(); i++){
            mp1[word1[i]]++;
        }
        
        for(int i=0; i<word2.length(); i++){
            mp2[word2[i]]++;
        }

        string s1,s2,sc1,sc2;

        for(auto it:mp1){
            s1.push_back(it.first);
            sc1.push_back(it.second);
        }

        for(auto it:mp2){
            s2.push_back(it.first);
            sc2.push_back(it.second);
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        sort(sc1.begin(), sc1.end());
        sort(sc2.begin(), sc2.end());

        if(s1==s2 && sc1==sc2) return true;

        return false;
    }
};

//Time Complexity - O(N)
//Space Complexity -O(N)
