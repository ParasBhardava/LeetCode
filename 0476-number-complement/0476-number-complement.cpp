class Solution {
public:
    int findComplement(int num) {
        
        bool flag = false;
        for(int i = 31; i >= 0; i--)
        {
            if((num & (1 << i)) == 0 && !flag)
               continue;
            
            else
            {
                flag = true;
                num = num ^ (1 << i);
            }
        }
        
        return num;
               
    }
};