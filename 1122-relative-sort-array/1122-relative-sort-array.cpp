class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int>result;
        vector<int>freq(1001, 0);
        
        for(int i = 0; i<arr1.size(); i++)
            freq[arr1[i]]++;
        
        for(int i = 0; i<arr2.size(); i++)
        {
            while(freq[arr2[i]] > 0)
            {
                result.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }
        
        for(int i = 0; i<=1000; i++)
        {
            while(freq[i] > 0)
            {
                result.push_back(i);
                freq[i]--;
            }
        }
        
        return result;
    }
};