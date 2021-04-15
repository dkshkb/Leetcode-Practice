//Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
//Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

class Solution {
public:
    map<int,int> fre_of_arr (vector<int> array) {
        map<int,int> ele_fre;
        
        for (int &i : array) {
            if (ele_fre.find(i) == ele_fre.end()){
                ele_fre.insert( pair<int,int>(i,1) );
                continue;
            }
            
            ele_fre[i]++;
        }
        
        return ele_fre;
    }
    
    vector<int> keys_with_largest_value (map<int,int> map) {
        vector<int> keys;
        
        //find the largest value
        int curr_lar_v = map.begin()->second;
        for (auto i : map) {
            if (i.second > curr_lar_v) curr_lar_v = i.second;
        }
        
        for (auto i : map) {
            if (i.second == curr_lar_v) keys.push_back(i.first);
        }
        
        return keys;
    }
    
    //return the shortest length of the subarray containing all the occurances of the given element
    int length_sub_array(vector<int> arr, int element) {
        int len = -1;
        auto it = arr.begin();
        auto it_first = it;
        auto it_last = it;
        bool found = false;
        while (it != arr.end()) {
            if (!found){
                if (*it == element) {
                    it_first = it;
                    it_last = it;
                    found = true;
                }
                it++;
                continue;
            }
            if (*it == element) it_last = it;
            
            it++;
        }
        
        if (!found) return 0;
        else return it_last - it_first + 1;
    }
    
    int findShortestSubArray(vector<int>& nums) {
        
        map<int,int> m = fre_of_arr(nums);
        vector<int> keys = keys_with_largest_value(m);
        int shortest_length = nums.size();
        for (auto i : keys) {
            if (length_sub_array(nums, i) < shortest_length){
                shortest_length = length_sub_array(nums, i);
            }
        }
        
        return shortest_length;
    }
};