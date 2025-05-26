class Solution {
    bool isPow2(int n){
        if(n == 1) return false;

        while(n > 1){
            if(n & 1) return false;
            n >>= 1;
        }

        return true;
    }

    int calcMSB(int n){
        int msb = 1;
        
        n >>= 1;
        while(n){
            n >>= 1;
            msb <<= 1;
        }

        return msb;
    }
public:
    char findKthBit(int n, int k) {
        if(k == 1) return '0';
        if(isPow2(k)) return '1';

        int k1;
        k1 = 2 * calcMSB(k) - k;

        char ans = findKthBit(n, k1);
        if(ans == '1') return '0';
        else return '1';
    }
};