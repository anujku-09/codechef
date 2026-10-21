# SPRINGPREASY

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Student Service College App

You are building a Simple College Student Details application.
A student has a  **name**  and a  **branch**  (example: "Arjun - Computer Science").
Your goal is to implement the application using:

```
CollegeApp (Runner) → StudentService (@Service)

```

and use  **Spring Dependency Injection**  to connect them.

 **Instructions:** 

- Complete your code first.
- Click on "Run" to start the application and make sure it runs correctly.
- If you make any changes to the code after running, you must run the application again.
- Only after running the application with the latest changes, your submission will reflect the updated solution.
- Do not submit if the application is not running; otherwise, your solution will fail.

 **Goal :** 
Complete a working Spring Boot application using:

- @Service annotated StudentService bean
- Hard-coded in-memory student data (4 students)
- @Autowired injection into the CollegeApp runner
- Console output printed automatically on application startup

 **Application Requirements** 

 **1. StudentService (Bean)** 

```
@Service
public class StudentService

```

- Stores a list of 4 hard-coded student names and branches
- Provides a method to return the list of students

 **Sample Data:** 

```
Arjun   - Computer Science
Meera   - Electronics
Rahul   - Mechanical
Sneha   - Civil

```

 **2. CollegeApp (Runner)** 

```
@Component
public class CollegeApp implements CommandLineRunner

```

- Auto-wire StudentService using @Autowired
- Implement the run() method
- Print each student's details when the application starts

 **Expected Console Output:** 

```
Student Details:
Name: Arjun, Branch: Computer Science
Name: Meera, Branch: Electronics
Name: Rahul, Branch: Mechanical
Name: Sneha, Branch: Civil

```

 **Instructions :** 

- Complete the missing code marked with: // TODO
- Annotate StudentService with @Service
- Use @Autowired to inject StudentService into CollegeApp
- Do NOT create the service object using new
- Do NOT hard-code student data inside CollegeApp
- Service holds the data, Runner only prints it
- Do not change package names

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-21T10:42:43.424Z  

```cpp
package com.example.demo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

@Component
public class OfficeApp implements CommandLineRunner{
    @Autowired
    private EmployeeService employeeService;

    @Override
    public void run(String... args) throws Exception {
        System.out.println("Student Details:");
        for(Employee s : employeeService.getAllStudents()) {
            System.out.println("Name: " + s.getName() + ", Branch: " + s.getBranch());
        }
    }
}
```

---

[View on CodeChef](https://www.codechef.com/problems/SPRINGPREASY)