class Solution {
public:
    bool halvesAreAlike(string s) {
        int j=(s.length()/2);
        int i =0,half1=0, half2=0;

        while(i< s.length()/2){
            if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'||
               s[i]=='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U'){
                half1++;
            }
            if(s[j]=='a'|| s[j]=='e'|| s[j]=='i'|| s[j]=='o'|| s[j]=='u'||
               s[j]=='A'|| s[j]=='E'|| s[j]=='I'|| s[j]=='O'|| s[j]=='U'){
                half2++;
            }

            i++;
            j++;

        }

        if(half1== half2) return true;
        return false;

    }
};

//TC - O(N/2)
//SC - O(1)
