class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        int sum = (n + m) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        
        
        if(sum > n * 6 || sum < n)
            return {};
        
        cout<<sum<<" ";
        vector<int>ans(n, sum/n);
        int rem = sum % n;
        
        for(int i = 0 ; i < rem; i++)
            ans[i]++;
        
        return ans;
        
    }
};