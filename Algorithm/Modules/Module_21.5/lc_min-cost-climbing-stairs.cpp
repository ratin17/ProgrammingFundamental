
//Accpted

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         int d[10000];
//         d[0]=cost[0];
//         d[1]=cost[1];

//         for(int i=2;i<n;i++){
//             d[i]=min(d[i-1]+cost[i],cost[i]+d[i-2]);
//         }
//         return min(d[n-1],d[n-2]);
//     }
// };

