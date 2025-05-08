//{ Driver Code Starts
#include <string>
#include <iostream>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    string findMaximumNum(string& s, int k) {
        if (k == 0 || s.empty())
            return s;
        
        int n = s.length();
        string result = s;
        
        findMaximumNumUtil(s, k, 0, result);
        
        return result;
    }
    
  private:
    void findMaximumNumUtil(string& str, int k, int pos, string& result) {
        if (k == 0 || pos == str.length())
            return;
        
        char maxChar = str[pos];
        for (int i = pos + 1; i < str.length(); i++) {
            if (maxChar < str[i]) {
                maxChar = str[i];
            }
        }
        
        if (maxChar == str[pos]) {
            findMaximumNumUtil(str, k, pos + 1, result);
            return;
        }
        
        for (int i = str.length() - 1; i > pos; i--) {
            if (str[i] == maxChar) {
                swap(str[pos], str[i]);
                
                if (str.compare(result) > 0)
                    result = str;
                
                findMaximumNumUtil(str, k - 1, pos + 1, result);
                
                swap(str[pos], str[i]);
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends