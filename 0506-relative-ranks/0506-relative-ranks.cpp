class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        priority_queue<pair<int, int>>maxHeap;
        for(int i = 0; i<score.size(); i++)
            maxHeap.push({score[i], i});
        
        int count = 1;
        vector<string>ans(score.size(), "");
        while(!maxHeap.empty())
        {
            if(count == 1)
                ans[maxHeap.top().second] = "Gold Medal";
            
            else if(count == 2)
                ans[maxHeap.top().second] = "Silver Medal";
            
            else if(count == 3)
                ans[maxHeap.top().second] = "Bronze Medal";
            
            else
                ans[maxHeap.top().second] = to_string(count);
            
            
            count++;
            maxHeap.pop();
        }
        
        return ans;
    }
};