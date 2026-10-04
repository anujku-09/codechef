# CUCPOVENJOB

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Bakery Oven Schedule

The  **Crustline Bakery**  runs on a single industrial oven, and the whole morning is planned around it. Every tray waiting in the queue carries a recipe label, written as one uppercase letter from `A` to `Z`; two trays with the same letter hold the same recipe.

The oven works in fixed  **intervals**. In each interval it does exactly one of two things:

- it bakes one tray from the queue, or
- it sits idle, because nothing may go in yet.

Trays may be baked in any order you like — the queue is not a line, it is just a pile of work. There is only one rule. After the oven bakes a tray of some recipe, that recipe's residue has to burn off, so at least $n$ intervals must pass before another tray of  **that same recipe**  goes in. In other words, two bakes of the same recipe must be separated by at least $n$ intervals, which the oven may spend baking other recipes or standing idle. Different recipes never wait for each other.

### Task

Given the trays in the queue and the cooldown $n$, find the  **minimum number of intervals**  the oven needs to bake every tray in the queue.

### Important Requirements
- The trays may be baked in any order, so choose the order that finishes soonest.
- Idle intervals still count towards the total.
- A cooldown of $n = 0$ means trays of the same recipe may be baked one after another.
### Input Format

The first line contains two space-separated integers $M$ and $n$ — the number of trays in the queue and the cooldown the oven needs between two bakes of the same recipe.

The second line contains $M$ space-separated uppercase letters, the recipe label of each tray.

### Output Format

Print a single integer: the minimum number of intervals needed to bake all $M$ trays.

### Constraints
- $1 \le M \le 10^4$
- $0 \le n \le 100$
- Every recipe label is an uppercase English letter from A to Z.
### Sample 1:
Input
Output

```
6 2
A A A B B B

```

```
8

```

### Sample 2:
Input
Output

```
6 0
A A A B B B

```

```
6

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T12:55:05.445Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<int> freq(26, 0);
	for(int i = 0; i < m; i++){
	    char ch;
	    cin >> ch;
	    freq[ch - 'A']++;
	}
	int max_freq = 0;
	for(int cnt : freq){
	    max_freq = max(max_freq, cnt);
	}
	int max_freq_cnt = 0;
	for(int cnt : freq){
	    if(cnt == max_freq){
	        max_freq_cnt++;
	    }
	}
	int ans = (max_freq - 1) * (n + 1) + max_freq_cnt;
	ans = max(ans, m);
	cout << ans << "\n";
	return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPOVENJOB)