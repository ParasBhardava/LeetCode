class Solution {
public:
    int numSquares(int n) {
        
        int count = 1, square;
        vector<int>arr(n+1, INT_MAX);
        arr[0] = 0;
        
        while(count * count <= n)
        {
            square = count * count;
            
            for(int i = square; i<=n; i++)
            {
                arr[i] = min(arr[i-square]+1, arr[i]);
            }
            
            count++;
        }
        
        return arr[n];
    }
};