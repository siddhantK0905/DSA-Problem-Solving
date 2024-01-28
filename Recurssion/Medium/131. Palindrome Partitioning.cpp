class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parti;

        getPartition(0, s, parti, ans);

        return ans;
    }

    void getPartition(int index, string s, vector<string>& parti, vector<vector<string>>& ans){

        if(index == s.length()){
            ans.push_back(parti);
            return;
        }

        for(int i=index; i<s.length(); i++){

            if(isPalindrome(index, i, s) == true){

                parti.push_back(s.substr(index, i - index + 1));
                getPartition(i+1, s, parti, ans);

                parti.pop_back();
            }
        }
    }

    bool isPalindrome(int start , int end, string s){
        while(start <= end){
            if(s[start] != s[end]) return false;

            start++;
            end--; 
        }

        return true;
    }
};
