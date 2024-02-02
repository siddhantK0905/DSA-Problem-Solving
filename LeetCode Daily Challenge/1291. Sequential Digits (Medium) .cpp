class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int num = 0;
        int nextDigit=1;
        vector<int> ans;

        for(int i=1; i< 10; i++){

            num = i;
            nextDigit = i+1;
          //getting all values of i number
            while( num <= high && nextDigit <= 9){
                num = num *10 + nextDigit;
                if(low <= num && num <= high){
                    ans.push_back(num);
                } 

                nextDigit++;

            } 
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

//TC - O(N log N)
//SC - O(N)
