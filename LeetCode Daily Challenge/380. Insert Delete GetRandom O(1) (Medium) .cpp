class RandomizedSet {
    private:
        vector<int>nums;
        unordered_map<int,int>mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()){ // if find fun find the value then it will return index of val
            return false;             //otherwise it will always return index of last element
        }
        else{

            nums.push_back(val);        // inserting val at the end of the vector
            mp[val] = nums.size()-1;    // making entry in the map
            return true;
        }
    }
    
    bool remove(int val) {
        
        if(mp.find(val) == mp.end()){   
            return false;
        }
        else{
            //update current val with the last element of vector and remove the last value
            // Then update the entry in the map

            int last = nums.back();     
            int index = mp[val];        
            nums[index] = nums.back();
            nums.pop_back();

            mp[last] = index;
            mp.erase(val);
            return true;


        }
    }
    
    int getRandom() {
        
        // rand() fun always return the value in the range od 0 to 32767 
        // %nums.size() is used to get the random value within the vector size
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

//TC - O(1)
//SC - O(N)
