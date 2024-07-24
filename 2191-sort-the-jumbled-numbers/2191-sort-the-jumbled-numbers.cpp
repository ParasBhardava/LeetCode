class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<pair<int,int>>arr;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            string number = to_string(num); 
            
            string map = "";
            
            for(int j = 0; j < number.size(); j++)
                map += (to_string(mapping[number[j]-'0']));
          
            int val = stoi(map);
            arr.push_back({val, i});
        }
        
        vector<int>ans;
        sort(arr.begin(), arr.end());
        for(auto &it: arr)
            ans.push_back(nums[it.second]);
        
        return ans;
        
    }
};