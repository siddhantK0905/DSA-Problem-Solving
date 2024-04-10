class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        for(int i=0; i < tickets.size(); i++){

            if(tickets[i] < tickets[k]) time += tickets[i];
            else{
                time += tickets[k];
            }

            if(i > k && tickets[i] >= tickets[k]) time--;
        }

        return time;
    }
};

//TC - O(N)
//SC - O(1)
