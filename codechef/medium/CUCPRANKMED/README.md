# CUCPRANKMED

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Science Fair Certificates

The  **Zenith Science Fair**  has just closed its doors, and the judging panel has finished scoring every project on display. Project $i$ walked away with $points_i$ judging points, and because the panel scores on a very fine scale,  **no two projects ended up with the same number of points**.

The organisers now have to turn those raw points into the placements that go on the certificates. The project with the highest points takes 1st place, the next highest takes 2nd place, the one after that takes 3rd place, and so on down to the last project.

The placement decides what gets printed on a project's certificate:

- The 1st place project's certificate reads Gold Medal.
- The 2nd place project's certificate reads Silver Medal.
- The 3rd place project's certificate reads Bronze Medal.
- Every project from 4th place down to $N$-th place simply gets its placement number printed on it (the project in $x$-th place gets x).
### Task

Print what goes on each project's certificate,  **in the order the projects were listed**, not in the order they placed.

### Important Requirements
- The certificates must come out in the original project order, so the $i$-th line of your output belongs to the $i$-th project of the input.
- Higher points mean a better placement.
- All point totals are distinct, so the placements are uniquely determined.
### Input Format

The first line contains a single integer $N$, the number of projects at the fair.

The second line contains $N$ space-separated integers $points_1, points_2, \ldots, points_N$, where $points_i$ is the number of judging points awarded to the $i$-th project.

### Output Format

Print $N$ lines. The $i$-th line must contain the text printed on the $i$-th project's certificate: `Gold Medal`, `Silver Medal`, `Bronze Medal`, or the project's placement number.

### Constraints
- $1 \le N \le 10^4$
- $0 \le points_i \le 10^6$
- All $N$ values of $points_i$ are distinct.
### Sample 1:
Input
Output

```
5
5 4 3 2 1

```

```
Gold Medal
Silver Medal
Bronze Medal
4
5

```

### Sample 2:
Input
Output

```
5
10 3 8 9 4

```

```
Gold Medal
5
Bronze Medal
Silver Medal
4

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T12:35:10.983Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++){
        int pts;
        cin >> pts;
        pq.push({pts,i});
    }
    vector<string> res(n);
    int rank = 1;
    while(!pq.empty()){
        auto[pts, idx] = pq.top();
        pq.pop();
        if(rank == 1){
            res[idx] = "Gold Medal";
        } else if (rank == 2) {
            res[idx] = "Silver Medal";
        } else if (rank ==3) {
            res[idx] = "Bronze Medal"; 
        } else {
            res[idx] = to_string(rank);
        }
        rank++;
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << "\n";
    }
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPRANKMED)