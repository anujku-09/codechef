# CUF8B

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Schema Validation and CRUD Operations with Mongoos
### Goal
- Build a Node.js application using Mongoose that defines a validated Student schema and performs all four CRUD operations using async/await.

 **By the end, you'll have** 

- A Student schema enforcing required, minlength and enum validations
- Three student documents saved in the students collection
- A complete read, update and delete cycle driven by document _id
### Task 1 — Connect to MongoDB
- Connect to the database using the MONGO_URI constant already defined in index.js.
### Task 2 — Define the Student Schema
- Create studentSchema with the following fields and validations:
Field	Type	Validation
`name`	String	Required, minimum length 3
`age`	Number	Required
`email`	String	Required, unique
`course`	String	Required, must be one of the allowed values
- Allowed course values:

```
Computer Science
Data Science
Electronics
Mechanical

```

### Task 3 — Create the Model
- Create a Student model from studentSchema, mapping to the students collection.
### Task 4 — Create Student Documents
- Create and save these three students:

```
{ name: "Anita Rao",    age: 20, email: "anita.rao@example.com",    course: "Computer Science" }
{ name: "Rahul Mehta",  age: 21, email: "rahul.mehta@example.com",  course: "Data Science" }
{ name: "Priya Sharma", age: 22, email: "priya.sharma@example.com", course: "Electronics" }

```

### Task 5 — Perform CRUD Operations
- Perform each operation using async/await, and print the result returned by each one.

 **a. Find All Students** 

- Retrieve all students using find().

 **b. Find a Student by ID** 

- Retrieve Rahul Mehta's document using findById() with the _id generated when he was saved.

 **c. Update a Student by ID** 

- Update Rahul Mehta's age to 23 using findByIdAndUpdate().
- The operation must return the document after the update, not before it.

 **d. Delete a Student by ID** 

- Delete Priya Sharma's document using findByIdAndDelete() with her _id.
### Task 6 — Close the Connection
- Close the MongoDB connection inside the finally block.
### Expected Output

```
Connected to MongoDB
Students created successfully

All students:
[ three student documents ]

Student found by ID:
{ Rahul Mehta's document, age: 21 }

Student updated:
{ Rahul Mehta's document, age: 23 }

Student deleted:
{ Priya Sharma's document }

MongoDB connection closed

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-21T11:54:48.739Z  

```cpp
    console.log();


  } catch (error) {
    console.error("Error:", error.message);
  } finally {
    // TODO: Delete a student using its ID.
    const deletedPriya = await Student.findByIdAndDelete(priyaId)
    console.log("Student deleted:");
    console.log(deletedPriya);
    // Delete a student by ID

    console.log();

    console.log(updatedRahul);
    console.log("Student updated:");
    );
      {new: true}
      {age : 23},
```

---

[View on CodeChef](https://www.codechef.com/problems/CUF8B)