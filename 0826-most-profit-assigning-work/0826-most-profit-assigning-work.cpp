class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
     
        int maxProfit = 0;
        vector<pair<int, int>>diff;
        
        for(int i = 0; i < difficulty.size(); i++)
            diff.push_back({difficulty[i], profit[i]});
        
        sort(diff.begin(), diff.end());
        
        int maxDiffPro = diff[0].second;
        for(int i = 0; i<diff.size(); i++)
        {
            maxDiffPro = max(maxDiffPro, diff[i].second);
            diff[i].second = maxDiffPro;
            
        }
        
        
        for(auto &wor : worker)
        {
            int start = 0, end = diff.size()-1, mid, ans = -1;
            
            while(start <= end)
            {
                mid = start + (end - start)/2;
                if(diff[mid].first <= wor)
                {
                    ans = mid;
                    start = mid + 1;
                }
                
                else
                    end = mid - 1;
            }
            
            
            if(ans != -1)
                maxProfit += diff[ans].second;
        }
        
        return maxProfit;
    }
};