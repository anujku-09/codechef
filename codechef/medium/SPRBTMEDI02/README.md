# SPRBTMEDI02

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Course JPA CRUD Application
## Instructions
- Complete your code first.
- Click on "Run" to start the server and make sure it runs correctly.
- If you make any changes to the code after running, you must run the server again.
- Only after running the server with the latest changes, your submission will reflect the updated solution.
- Do not submit if the server is not running; otherwise, your solution will fail.
## Goal

Create a  **Spring Boot application**  that maps a `Course` class to a database table using  **JPA annotations**.

On startup, save  **5 courses**  with their credits to an  **H2 in-memory database**, then:

- Fetch and print all courses
- Find a course by ID
- Delete one course

— demonstrating all  **four CRUD operations**  using `JpaRepository`.

## Your Task

Complete the code, given in IDE by following the below Requirements:

### 1. Create Entity

Create a class `Course.java` inside the  **model**  package.

 **Fields:** 

- id (Auto-generated Primary Key)
- title
- credits

 **Use the following annotations:** 

- @Entity
- @Id
- @GeneratedValue
### 2. Create Repository

Create `CourseRepository.java` inside the  **repository**  package.

 **Extend:** 

```
JpaRepository<Course, Long>

```

Do not write any implementation.

### 3. Seed Data on Startup

On application startup, save  **5 courses**  with their credits to the  **H2 in-memory database**.

Use a `CommandLineRunner` (or `@PostConstruct`) to insert the records.

### 4. Demonstrate CRUD Operations

Using  **built-in `JpaRepository` methods**, perform and print the following:

Operation	Method	Description
 **Create** 	`save(entity)`	Save 5 courses on startup
 **Read (all)** 	`findAll()`	Fetch and print all courses
 **Read (one)** 	`findById(id)`	Find a course by ID
 **Update** 	`save(entity)`	Update a course's credits
 **Delete** 	`deleteById(id)`	Delete one course
## Expected Console Output (Example)

```
>>> Saved 5 courses
>>> All courses:
Course{id=1, title='Java Basics', credits=3.0}
Course{id=2, title='Spring Boot', credits=4.0}
Course{id=3, title='Data Structures', credits=3.5}
Course{id=4, title='Web Development', credits=2.5}
Course{id=5, title='Database Systems', credits=3.0}
>>> Found: Course{id=3, title='Data Structures', credits=3.5}
>>> Updated: Course{id=2, title='Spring Boot', credits=5.0}
>>> Deleted course ID 5
>>> Final list:
Course{id=1, title='Java Basics', credits=3.0}
Course{id=2, title='Spring Boot', credits=5.0}
Course{id=3, title='Data Structures', credits=3.5}
Course{id=4, title='Web Development', credits=2.5}

```

## Note
- Test all CRUD operations properly.
- To see the database: Open H2 Console at: http://localhost:3000/h2-console Login using the below details: JDBC URL : jdbc:h2:mem:testdb Username : sa Password : (leave empty) Then run the query: SELECT * FROM COURSE & observe the result in the table COURSE.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-21T10:50:22.934Z  

```cpp
    public Course updateCourse(@PathVariable Long id, @RequestBody Course updatedCourse) {

        Course course = courseRepository.findById(id).orElse(null);

        if (course != null) {
            course.setTitle(updatedCourse.getTitle());
            course.setCredits(updatedCourse.getCredits());
            return courseRepository.save(course);
    @PutMapping("/{id}")
    // Update Course

    }
        return courseRepository.findById(id).orElse(null);
    public Course getCourseById(@PathVariable Long id) {
    @GetMapping("/{id}")
    // Get Course By ID

    }
        return courseRepository.findAll();
        }
```

---

[View on CodeChef](https://www.codechef.com/problems/SPRBTMEDI02)