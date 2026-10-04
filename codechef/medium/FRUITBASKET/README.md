# FRUITBASKET

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T14:16:19.066Z  

```c_cpp
class Solution {
public:
    int longestUniqueSubstring(string s) {
        vector<int> last_pos(256, -1);
        int mx_len = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            char c = s[r];
            if(last_pos[c] >= l){
                l = last_pos[c] + 1;
            }
            last_pos[c] = r;
            mx_len = max(mx_len, r - l + 1);
        }
        return mx_len;
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/FRUITBASKET)