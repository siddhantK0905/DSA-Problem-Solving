class Solution {
public:
std::set<int> checked_number;
    bool isHappy(int n) 
    {

        // TC - O(log N)   
        // SC - O(1);
       if(n == 1 || n== 7) return true;
       else if( checked_number.find(n) != checked_number.end()) return true;

       else if( n < 10) return false;

       else 
       {
        int sum =0;
        while (n > 0)
        {
            auto temp = n%10;
            sum += (temp*temp);

            n = n/10;
        }
        return isHappy(sum);
       }   
    }
};
