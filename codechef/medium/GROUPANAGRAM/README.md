# GROUPANAGRAM

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Group Anagrams

Listen

You are given $N$ strings. Your task is to group the strings that are anagrams of each other. Complete the given function.

 **Note** : An anagram is a string formed by rearranging the letters of a another string, using all the original letters exactly once.
For example,  **"listen"**  and  **"silent"**  are anagrams of each other because they contain the same letters.

### Input Format
- The first line of input contains an integer $N$ — the number of strings.
- The next $N$ lines contain strings.
### Output Format
- Complete the function which return the vector of string vectors. each string vector are group of anagram strings.
- You can return the groups of anagrams in any order.
### Constraints
- $1 \leq N \leq 100000$
- All strings are of lowercase latin letters.
- Size of each string is at most 10.
### Sample 1:
Input
Output

```
5
abc
dba
acb
bda
cba
```

```
abc acb cba 
dba bda
```

### Explanation:

There could be multiple grouping, for eg, 1 valid grouping is: {abc, acb, cba}, {dba, bda}

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T18:25:21.321Z  

```c_cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/GROUPANAGRAM)