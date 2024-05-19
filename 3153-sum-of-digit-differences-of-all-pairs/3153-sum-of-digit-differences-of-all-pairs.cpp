class Solution {
    
private:
    int countDigits(int num)
    {
        int count = 0;
        while(num){
            num /= 10;
            count++;
        }
        
        return count;
    }
    
public:
    long long sumDigitDifferences(vector<int>& nums) {
     
        int n = nums.size(), digits = countDigits(nums[0]);
        long long res = 0LL;
        
        vector<vector<int>>count(10, vector<int>(10, 0));
        
        for(int num : nums){
            int pos = 0;
            while(num)
            {
                int digit = num % 10;
                count[pos][digit]++;
                num /= 10;
                pos++;
            }
        }
        
        for(int num : nums){
            int pos = 0;
            while(num){
                int digit = num % 10;
                res += n - count[pos][digit];
                num /= 10;
                pos++;
            }
        }
        
        return res / 2;
    }
};