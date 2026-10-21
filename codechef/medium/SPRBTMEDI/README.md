# SPRBTMEDI

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Student JPA CRUD Application
## Instructions
- Complete your code first.
- Click on "Run" to start the server and make sure it runs correctly.
- If you make any changes to the code after running, you must run the server again.
- Only after running the server with the latest changes, your submission will reflect the updated solution.
- Do not submit if the server is not running; otherwise, your solution will fail.
## Goal

Create a  **Spring Boot application**  that maps a `Student` class to a database table using  **JPA annotations**.

On startup, save  **5 students**  with their marks to an  **H2 in-memory database**, then:

- Fetch and print all students
- Find a student by ID
- Delete one student

— demonstrating all  **four CRUD operations**  using `JpaRepository`.

## Your Task

Complete the code, given in IDE by following the below Requirements:

### 1. Create Entity

Create a class `Student.java` inside the  **model**  package.

 **Fields:** 

- id (Auto-generated Primary Key)
- name
- marks

 **Use the following annotations:** 

- @Entity
- @Id
- @GeneratedValue
### 2. Create Repository

Create `StudentRepository.java` inside the  **repository**  package.

 **Extend:** 

```
JpaRepository<Student, Long>

```

Do not write any implementation.

### 3. Seed Data on Startup

On application startup, save  **5 students**  with their marks to the  **H2 in-memory database**.

Use a `CommandLineRunner` (or `@PostConstruct`) to insert the records.

### 4. Demonstrate CRUD Operations

Using  **built-in `JpaRepository` methods**, perform and print the following:

Operation	Method	Description
 **Create** 	`save(entity)`	Save 5 students on startup
 **Read (all)** 	`findAll()`	Fetch and print all students
 **Read (one)** 	`findById(id)`	Find a student by ID
 **Update** 	`save(entity)`	Update a student's marks
 **Delete** 	`deleteById(id)`	Delete one student
## Expected Console Output (Example)

```
>>> Saved 5 students
>>> All students:
Student{id=1, name='Alice', marks=88.5}
Student{id=2, name='Bob', marks=72.0}
Student{id=3, name='Charlie', marks=91.25}
Student{id=4, name='David', marks=65.75}
Student{id=5, name='Eva', marks=79.0}
>>> Found: Student{id=3, name='Charlie', marks=91.25}
>>> Updated: Student{id=2, name='Bob', marks=95.0}
>>> Deleted student ID 5
>>> Final list:
Student{id=1, name='Alice', marks=88.5}
Student{id=2, name='Bob', marks=95.0}
Student{id=3, name='Charlie', marks=91.25}
Student{id=4, name='David', marks=65.75}

```

## Note
- Test all CRUD operations properly.
- To see the database: Open H2 Console at: http://localhost:3000/h2-console Login using the below details: JDBC URL : jdbc:h2:mem:testdb Username : sa Password : (leave empty) Then run the query: SELECT * FROM STUDENT & observe the result in the table STUDENT.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-21T07:53:45.928Z  

```cpp
            studentRepository.save(new Student("David",   65.75));
            studentRepository.save(new Student("Eva",     79.0));
            System.out.println(">>> Saved 5 students");

            // READ ALL
            System.out.println(">>> All students:");
            studentRepository.findAll().forEach(System.out::println);

            // READ ONE
            Optional<Student> student = studentRepository.findById(3L);
            student.ifPresent(s -> System.out.println(">>> Found: " + s));

            // UPDATE
            studentRepository.findById(2L).ifPresent(s -> {
                s.setMarks(95.0);
                studentRepository.save(s);
                System.out.println(">>> Updated: " + s);
            });

            // DELETE
            studentRepository.deleteById(5L);
            System.out.println(">>> Deleted student ID 5");

            // FINAL LIST
            System.out.println(">>> Final list:");
```

---

[View on CodeChef](https://www.codechef.com/problems/SPRBTMEDI)