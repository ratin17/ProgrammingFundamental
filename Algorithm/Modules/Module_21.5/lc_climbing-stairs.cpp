
class Solution {
public:
    int climbStairs(int n) {
        int d[100];
        d[1]=1;
        d[2]=2;
        for(int i=3;i<=n;i++){
            d[i]=d[i-2]+d[i-1];
        }
        return d[n];
    }
};
