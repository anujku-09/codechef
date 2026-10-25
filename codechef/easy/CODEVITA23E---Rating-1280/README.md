# CODEVITA23E - Rating 1280

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Sorting Boxes

Little Jill jumbled up the order of the letters in our dictionary. Now, Jack uses this list to find the smallest lexicographical string that can be made out of this new order. Can you help him?

You are given a string $P$ that denotes the new order of letters in the English dictionary.

You need to print the smallest lexicographic string made from the given string $S$.

### Input Format
- The first line contains an integer $T$, representing the number of test cases.
- For each test case: The first line contains the string $P$ (the custom alphabet order). The second line contains the string $S$ (the string to be reordered).
### Output Format

Print a single string in a new line for every test case giving the result

### Constraints
- $1 \leq T \leq 1000$
- Length $(P) = 26$
- $1 \leq$ length $(S) \leq 100$
### Sample 1:
Input
Output

```
2
polikujmnhytgbvfredcxswqaz
abcd
qwryupcsfoghjkldezxvbintma
ativedoc
```

```
bdca
codevita
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T17:48:53.916Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

string smallest_lexicographical_string(const string& p, const string& s) {
    unordered_map<char, int> order_map;
    for(int i = 0; i < p.size(); i++) {
        order_map[p[i]] = i;
    }
    vector<char> sorted_s(s.begin(), s.end());
    sort(sorted_s.begin(), sorted_s.end(), [&](char a, char b) {
        return order_map[a] < order_map[b];
    });
    return string(sorted_s.begin(), sorted_s.end());
}
int main() {
	int t;
	cin >> t;
	cin.ignore();
	for(int i = 0; i < t; i++) {
	    string p, s;
	    getline(cin, p);
	    getline(cin, s);
	    
	    string res = smallest_lexicographical_string(p, s);
	        cout << res << endl;
	}
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CODEVITA23E)