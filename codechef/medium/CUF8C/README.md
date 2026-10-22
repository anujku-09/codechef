# CUF8C

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### References, Populate and Advanced Queries
### Goal
- Build a Node.js application using Mongoose that links students to courses through an ObjectId reference.
- Use.populate() to fetch related course data, then filter, search, sort and paginate the student collection.
### By the end, you'll have
- Two related models connected by an ObjectId reference
- Six students, each pointing at one of four courses
- A populated query returning student and course data together
- Filter, regex search, sort and pagination queries over the same collection
### Task 1 — Connect to MongoDB
- Connect to the database using the MONGO_URI constant already defined in index.js.
### Task 2 — Define the Course Schema
- Create courseSchema with the following fields:
Field	Type	Validation
`name`	String	Required
`code`	String	Required, unique
- Create a Course model mapping to the courses collection.
### Task 3 — Define the Student Schema
- Create studentSchema with the following fields:
Field	Type	Validation
`name`	String	Required
`age`	Number	Required
`email`	String	Required, unique
`course`	ObjectId	Reference to the `Course` model
- The course field must store an ObjectId reference, not the course name.
- Create a Student model mapping to the students collection. Note: Do not disable Mongoose's default version key (__v) on either schema.
### Task 4 — Create Courses and Students
- Create these four courses:

```
{ name: "Computer Science", code: "CS" }
{ name: "Data Science",     code: "DS" }
{ name: "Electronics",      code: "EC" }
{ name: "Mechanical",       code: "ME" }

```

- Create these six students, storing the _id of the matching course in each student's course field:

```
Anita Rao     — 20 — anita.rao@example.com     — Computer Science
Rahul Mehta   — 21 — rahul.mehta@example.com   — Data Science
Priya Sharma  — 22 — priya.sharma@example.com  — Electronics
Aman Verma    — 19 — aman.verma@example.com    — Computer Science
Neha Singh    — 23 — neha.singh@example.com    — Data Science
Arjun Kumar   — 24 — arjun.kumar@example.com   — Mechanical

```

### Task 5 — Populate Course Information
- Retrieve all students with their related course data using.populate().
- Print each student's name along with the course name and code.
### Task 6 — Filter Students by Course
- Retrieve only the students enrolled in Computer Science.
- The query must match on the course reference, not on a name string stored in the student document.
- Print the matching student names.
### Task 7 — Search Students by Name
- Find students whose name contains the text ar.
- The search must use a case-insensitive regular expression.
- Print the matching student names.
### Task 8 — Sort Students by Age
- Retrieve all students sorted by age in ascending order.
- Print each student's name and age.
### Task 9 — Paginate the Students
- Return page 2 with a page size of 2, applied to the same ascending age order.
- Use.skip() and.limit().
- Print each student's name and age.
### Task 10 — Close the Connection
- Close the MongoDB connection inside the finally block.
### Expected Output

```
Connected to MongoDB

Students with course details:
Priya Sharma - Electronics (EC)
Anita Rao - Computer Science (CS)
Rahul Mehta - Data Science (DS)
Arjun Kumar - Mechanical (ME)
Neha Singh - Data Science (DS)
Aman Verma - Computer Science (CS)

Computer Science students:
Anita Rao
Aman Verma

Students matching search:
Priya Sharma
Arjun Kumar

Students sorted by age:
Aman Verma - 19
Anita Rao - 20
Rahul Mehta - 21
Priya Sharma - 22
Neha Singh - 23
Arjun Kumar - 24

Paginated students:
Rahul Mehta - 21
Priya Sharma - 22

MongoDB connection closed

```

- The _id values differ on every execution.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T15:14:08.757Z  

```cpp
    ]);

    // Task 5: Populate course information
    console.log("\nStudents with course details:");
    const populatedStudents = await Student.find().populate("course");
    populatedStudents.forEach((s) => {
      console.log(`${s.name} - ${s.course.name} (${s.course.code})`);
    });

    // Task 6: Filter students by course
    console.log("\nComputer Science students:");
    const csCourse = await Course.findOne({ code: "CS" });
    const csStudents = await Student.find({ course: csCourse._id });
    csStudents.forEach((s) => {
      console.log(s.name);
    });

    // Task 7: Search students by name
    console.log("\nStudents matching search:");
    const matchingStudents = await Student.find({
      name: { $regex: "ar", $options: "i" }
    });
    matchingStudents.forEach((s) => {
      console.log(s.name);
    });

    // Task 8: Sort students by age
    console.log("\nStudents sorted by age:");
    const sortedStudents = await Student.find().sort({ age: 1 });
    sortedStudents.forEach((s) => {
      console.log(`${s.name} - ${s.age}`);
    });

    // Task 9: Paginate the students
    console.log("\nPaginated students:");
    const paginatedStudents = await Student.find()
      .sort({ age: 1 })
      .skip(2)
      .limit(2);
    paginatedStudents.forEach((s) => {
      console.log(`${s.name} - ${s.age}`);
    });
  } catch (error) {
    console.error("Error:", error.message);
  } finally {
    // Task 10: Close the connection
    await mongoose.connection.close();
    console.log("\nMongoDB connection closed");
  }
}

main();
```

---

[View on CodeChef](https://www.codechef.com/problems/CUF8C)