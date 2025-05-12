class Solution {
    public:
      int nCr(int n, int r) {
          if (r > n) return 0; // If r > n, return 0 as per definition
          if (r == 0 || r == n) return 1; // Base case
  
          long long res = 1; // Use long long to avoid overflow in intermediate steps
          r = min(r, n - r); // Optimization: reduce the number of multiplications
          for (int i = 0; i < r; ++i) {
              res *= (n - i);
              res /= (i + 1);
          }
  
          return static_cast<int>(res); // Convert to 32-bit integer
      }
  };