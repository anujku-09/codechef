# POLMDB28D

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Task - Library Inventory Lifecycle

 **Your Goal** : Manage a collection named  **books**  by performing a full  **"Round-Trip"**  of data—from the moment a new book arrives at the library to the moment it is removed.

 **Step 1: [C]reate - The New Arrival** 

- Use db.books.insertOne() to add a new book.
- Fields: title, author, copies (Number), and is_available (Boolean).

 **Step 2: [R]ead - Find the Book** 

- Use db.books.findOne() to display the book details on the screen.
- Target: Search for the book using its title.

 **Step 3: [U]pdate - Borrowing the Book** 

- Use db.books.updateOne() to reflect a student borrowing a copy.
- Operation: Find the book by title. Use $inc to decrease copies by -1 and $set to change is_available to false.

 **Step 4: [D]elete - Removing the Record** 

- Use db.books.deleteOne() to remove the book from the system.
- Target: Delete the document where the title matches.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T14:57:36.582Z  

```cpp
const book = db.books.findOne({
  title: "The Great Gatsby"
});
// --- STEP 2: READ ---
// Find the book using its title


db.books.insertOne({
  title: "The Great Gatsby",
  author: "F. Scott Fitzgerald",
  copies: 5,
  is_available: true
});

db = connect('mongodb://localhost:27017/library_db');

db.books.deleteMany({});

// --- STEP 1: CREATE ---
// Insert a new book document
```

---

[View on CodeChef](https://www.codechef.com/problems/POLMDB28D)