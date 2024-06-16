class SGTree
{
 
private:
    vector<int> seg;

public:
    SGTree(int n)
    {
        int h = ceil(log2(n));
        int size = 2 * (int)pow(2, h);
        seg.resize(size + 1);
    }
    
    void build(int idx, int low, int high, vector<int> &arr)
    {
        // leaf nodes
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r)
    {
        // no overlap
        // [l, r] [low, high] or [low, high] [l, r]
        if (r < low || high < l)
            return 0;

        // complete overlap
        // [l, low, high, r]
        if (l <= low && high <= r)
            return seg[idx];

        // partially overlap
        // [l, low, r, high] or [low, l, high, r]
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }

    void update(int idx, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);

        else
            update(2 * idx + 2, mid + 1, high, i, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
};


class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> peak(n, 0);
        
        for(int i = 1; i < n - 1; i++)
        {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                peak[i] = 1;
        }
        
        vector<int>res;
        SGTree *st = new SGTree(n);
        st->build(0, 0, n - 1, peak);
        for(auto query: queries){
            int type = query[0];
            if(type == 1)
            {
                int l = query[1];
                int r = query[2];
                
                if(l == r)
                {
                    res.push_back(0);
                    continue;
                }
                
                int count = 0;
                if(peak[l] == 1) count++;
                if(peak[r] == 1) count++;
            
                int ans = st->query(0, 0, n - 1, l, r);
                cout<<count<<" "<<ans<<"\n";
                res.push_back(ans - count);
            }
            
            else
            {
                int idx = query[1];
                int val = query[2];
                nums[idx] = val;
                
                // Checking for index idx
                if(idx - 1 >= 0 && idx + 1 < n)
                {
                    if(nums[idx] > nums[idx - 1] && nums[idx] > nums[idx + 1])
                    {
                        st->update(0, 0, n - 1, idx, 1);
                        peak[idx] = 1;
                    }
                    
                    else
                    {
                        st->update(0, 0, n - 1, idx, 0);
                        peak[idx] = 0;
                    }
                    
                }
                
                // Checking for index idx - 1
                if(idx - 2 >= 0 && idx < n)
                {
                    if(nums[idx - 1] > nums[idx - 2] && nums[idx - 1] > nums[idx])
                    {
                        st->update(0, 0, n - 1, idx - 1, 1); 
                        peak[idx - 1] = 1;
                    }
                    
                    else
                    {
                        st->update(0, 0, n - 1, idx - 1, 0);
                        peak[idx - 1] = 0;
                    }
                }
                
                // Checking index idx + 1
                if(idx >= 0 && idx + 2 < n)
                {
                    if(nums[idx + 1] > nums[idx] && nums[idx + 1] > nums[idx + 2])
                    {
                        st->update(0, 0, n - 1, idx + 1, 1); 
                        peak[idx + 1] = 1;
                    }
                    
                    else
                    {
                        st->update(0, 0, n - 1, idx + 1, 0);
                        peak[idx + 1] = 0;
                    }
                } 
            }
        }
        
        return res;
    }
};