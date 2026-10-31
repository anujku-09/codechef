# CUCPHUBFIND

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Skyline Air Hub

 **Skyline Air**  runs its whole timetable out of a single hub. The airline serves $N$ airports, numbered from $1$ to $N$, and operates exactly $N - 1$ two-way routes. Every one of those routes starts or ends at the hub airport, and no two airports other than the hub are ever joined directly — the route map is a star centred on the hub.

The route list has come back from the planning office shuffled: the routes are in no particular order, and the two airports of a route may be written either way round. The hub is not marked anywhere.

### Task

Read the route list and print the hub airport — the one airport that appears on  **every**  route.

### Important Requirements
- The map is guaranteed to be a valid star, so exactly one such airport exists.
- The routes may be listed in any order, and each route's two airports may appear in either order.
- The route list can be long, so read it efficiently.
### Input Format

The first line contains a single integer $N$, the number of airports.

Each of the next $N - 1$ lines contains two space-separated integers $u$ and $v$, a two-way route between airport $u$ and airport $v$.

### Output Format

Print a single integer: the hub airport.

### Constraints
- $3 \le N \le 10^5$
- $1 \le u, v \le N$ and $u \ne v$
- The routes always form a star graph.
### Sample 1:
Input
Output

```
4
1 2
2 3
4 2

```

```
2

```

### Sample 2:
Input
Output

```
3
1 2
2 3

```

```
2

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T09:54:33.692Z  

```c_cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int u1, v1, u2, v2;
    cin >> u1 >> v1 >> u2 >> v2;

    if (u1 == u2 || u1 == v2) {
        cout << u1 << "\n";
    } else {
        cout << v1 << "\n";
    }

    for (int i = 0; i < n - 3; i++) {
        int u, v;
        cin >> u >> v;
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPHUBFIND)