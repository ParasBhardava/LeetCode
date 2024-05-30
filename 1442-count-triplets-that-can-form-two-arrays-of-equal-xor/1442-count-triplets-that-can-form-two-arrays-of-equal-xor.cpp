class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int Xor = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                Xor ^= arr[j];
                if (Xor == 0) {
                    ans += (j - i);
                }
            }
        }
        
        return ans;
    }
};