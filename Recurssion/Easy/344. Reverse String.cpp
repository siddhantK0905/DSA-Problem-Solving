class Solution {

public:
    void reverseString(vector<char>& s) {
        //Using Recurrsion
        int i=0, j=s.size()-1;
        reverse(i,j,s);
    }

    void reverse(int i, int j, vector<char>& s){
        if(i>=j){
            return;
        }
        swap(s[i], s[j]);
        reverse(++i,--j,s);
    }
};
