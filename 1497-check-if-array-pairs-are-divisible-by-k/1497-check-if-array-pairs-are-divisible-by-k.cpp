class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        vector<int>freq(k, 0);
        for(int it : arr)
            freq[((it % k) + k) % k]++;
       
        for(int it :arr)
        {
            int rem=((it % k) + k) % k;
            if(rem == 0)                         
            { 
                if(freq[rem] % 2 == 1) 
                    return false;            
            }   
        
            else if(freq[rem] != freq[k - rem]) 
                return false;    
        }
        
        return true;
    }
};