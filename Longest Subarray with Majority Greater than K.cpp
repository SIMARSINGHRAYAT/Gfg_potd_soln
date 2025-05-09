class Solution {
    public:
        int longestSubarray(vector<int> &arr, int k) {
            int n = arr.size();
            vector<int> transformedArr(n);
            for (int i = 0; i < n; i++) {
                transformedArr[i] = (arr[i] > k) ? 1 : -1;
            }
    
            int maxLength = 0;
            int prefixSum = 0;
            unordered_map<int, int> prefixSumIndex;
            prefixSumIndex[0] = -1;
    
            for (int i = 0; i < n; i++) {
                prefixSum += transformedArr[i];
    
                if (prefixSum > 0) {
                    maxLength = max(maxLength, i + 1);
                }
    
                if (prefixSumIndex.find(prefixSum) == prefixSumIndex.end()) {
                    prefixSumIndex[prefixSum] = i;
                }
    
                if (prefixSumIndex.find(prefixSum - 1) != prefixSumIndex.end()) {
                    maxLength = max(maxLength, i - prefixSumIndex[prefixSum - 1]);
                }
            }
    
            return maxLength;
        }
    };
    