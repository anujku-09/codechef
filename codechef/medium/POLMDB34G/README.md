# POLMDB34G

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Task - Advanced Book Querying

Perform queries on the  **books**  collection using specific MongoDB operators and display the results.

 **Step 1: Query – High Availability Books ($gt)** 

- Use db.books.find() to retrieve books. Find all books where copies is greater than 4

 **Step 2: Filter – Multiple Genres ($in)** 

- Find books where genre is either: "Self-help" OR "Programming" Use $in operator with an array of values

 **Step 3: Search – Pattern Matching ($regex)** 

- Find books where the title starts with "The"
- Use $regex with pattern: "^The"

 **Step 4: Project – Limit Fields (Projection)** 

- Display only: title author Exclude _id field

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T15:01:53.446Z  

```cpp
);


// --- STEP 3: SEARCH ($regex) ---
print("Regex Search Result:");
printjson(
  db.books.find({ 
    title: {$regex: "^The"}
   }).toArray()
);


// --- STEP 4: PROJECTION ---
print("Projection Result:");
printjson(
    genre: { $in: ["Self-help", "Programming"]}
   }).toArray()
  db.books.find(
    {}, 
    {
      title: 1,
    }
  ).toArray()
      author: 1,
      _id : 0
);
```

---

[View on CodeChef](https://www.codechef.com/problems/POLMDB34G)