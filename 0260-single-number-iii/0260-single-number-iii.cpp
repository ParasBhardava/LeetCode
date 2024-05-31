class Solution { 
    public: 
    vector<int> singleNumber(vector<int>& nums) 
    { 
        vector<int>res;
        long long int XOR = 0, setBit, a = 0, b = 0; 
        
        for(auto x: nums) 
            XOR = XOR ^ x; 
        
        setBit=XOR & (-XOR);
        
        for(auto x: nums)
        { 
            if(setBit & x) 
                a = a ^ x; 
            else 
                b = b ^ x; 
        } 
        
        res.push_back(a);
        res.push_back (b);
        
        return res; 
    }
};