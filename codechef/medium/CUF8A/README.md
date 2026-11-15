# CUF8A

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Connecting a Student Database
### Goal
- Connect a Node.js application to MongoDB using Mongoose, define a Student schema, and save one document to the database.
### By the end, you'll have
- A working Mongoose connection to a local MongoDB database
- A Student model with four defined fields
- One student document saved in the students collection
### Task 1 — Set Up the Connection
- Connect to the database studentdb using the connection string available i.e, mongodb://127.0.0.1:27017/studentdb.
- Print Connected to MongoDB to the console once the connection succeeds.
- Print the error message to the console if the connection fails.
### Task 2 — Define the Student Schema
- Create a schema named studentSchema with these fields: name — String, required age — Number, required email — String, required, unique course — String, required
### Task 3 — Create the Model
- Create a model named Student from studentSchema.
- The model must map to the students collection.
### Task 4 — Save One Document
- Create a single student document with these values: name: Anita Rao age: 20 email: anita.rao@example.com course: Computer Science
- Save the document to the database.
- Print Student saved: followed by the saved document to the console.
- Print the error message to the console if the save fails.
### Task 5 — Close the Connection
- Close the database connection after the save operation completes, whether it succeeded or failed.
### Expected Output

```
Connected to MongoDB
Student saved:
{
  name: 'Anita Rao',
  age: 20,
  email: 'anita.rao@example.com',
  course: 'Computer Science',
  _id: <generated ObjectId>,
  __v: 0
}

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-15T17:34:37.084Z  

```cpp
        });
            }
                required: true
                type: String,
            course: {
            },
                unique: true
                required: true,
                type: String,
            email: {
            },
                required: true
                type: Number,
            },
            age: {
                type: String,
                required: true
            name: {

        // Task 2: Define studentSchema
        const studentSchema = new mongoose.Schema({
        console.log("Connected to MongoDB");
        await mongoose.connect(MONGO_URI);
    try {
async function run() {
// Task 1: Connect to MongoDB

const MONGO_URI = "mongodb://127.0.0.1:27017/studentdb";
const mongoose = require('mongoose');

// Connection string for the lab environment

        // Task 3: Create the Student model
```

---

[View on CodeChef](https://www.codechef.com/problems/CUF8A)