class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums){
            freq[n]+=1;
        }
        
        vector<vector<int>> bucket(nums.size()+1);
        for (const auto& [num, f] : freq) bucket[f].push_back(num);

        vector<int> result;
        result.reserve(k);
        for (int f = bucket.size()-1; f >= 1; --f){
            for (int num:bucket[f]){
                result.push_back(num);
                if (result.size() == k )break;
            }
            if (result.size() == k )break;
        }
        return result;
    }
};
