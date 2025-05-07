# 🔢 Missing Element in Arithmetic Progression (AP)

## 🧠 Problem Statement

Given a **sorted array** `arr[]` representing an Arithmetic Progression (AP) with **exactly one missing element**, the task is to find the **missing number**.

- If no number is missing (i.e., the array already forms a perfect AP), return the next (n+1)-th element in the sequence.
- The solution assumes **one missing value is always possible to determine** to form a perfect AP.

### ✅ Constraints:
- `2 <= arr.size() <= 10^5`
- `0 <= arr[i] <= 2*10^7`

---

## 📥 Input Examples

```cpp
Input: arr[] = [2, 4, 8, 10, 12, 14]
Output: 6
Explanation: The AP should be [2, 4, 6, 8, 10, 12, 14]
cpp
Copy
Edit
Input: arr[] = [1, 6, 11, 16, 21, 31]
Output: 26
Explanation: The AP should be [1, 6, 11, 16, 21, 26, 31]
cpp
Copy
Edit
Input: arr[] = [4, 7, 10, 13, 16]
Output: 19
Explanation: The AP is already complete. Next element is 19.
💡 Approach
Find the Common Difference:

Check differences between the first few elements.

Use the majority value among initial differences to determine the correct common difference.

Scan the Array:

Compare adjacent elements.

Return the first element where the difference does not match the common difference.

If No Gap Found:

Return the next AP element at the end of the array.

🧾 C++ Code
cpp
Copy
Edit
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        
        if (n == 2) {
            int diff = arr[1] - arr[0];
            return arr[1] + diff;
        }
        
        int diff1 = arr[1] - arr[0];
        int diff2 = arr[2] - arr[1];
        
        int commonDiff;
        if (diff1 == diff2) {
            commonDiff = diff1;
        } else if (n > 3) {
            int diff3 = arr[3] - arr[2];
            if (diff1 == diff3) {
                commonDiff = diff1;
            } else {
                commonDiff = diff2;
            }
        } else {
            commonDiff = min(diff1, diff2);
        }
        
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] != commonDiff) {
                return arr[i - 1] + commonDiff;
            }
        }
        
        return arr[n - 1] + commonDiff;
    }
};