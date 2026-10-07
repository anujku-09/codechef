# EXP24HARD

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Practice Problem - Product Management API
### Instructions:
- Complete your code first.
- Click on "Run" to compile and run the application.
- Use the menu displayed in the console to test the student operations.
- If you make any changes to the code after running, you must run the application again.
- At last, after running the code, click on "Submit".
### Goal :

Build a Java application that manages student records using JDBC and MVC architecture.

The application must store student data in an H2 database and provide CRUD operations through a simple menu-driven interface.

The application should use:

- Student as the model.
- StudentDAO for database operations.
- StudentController to handle student operations.
- StudentView for the menu-driven user interface.
- DBConnection to establish the database connection.
- DatabaseInitializer to create the database table.

All files are already provided. Complete the code marked `TODO`. Do not rename any class or method.

### Project Structure :

```
student-jdbc-mvc/
├── pom.xml    (H2 dependency already added)
└── src/main/
    └── java/com/example/
        ├── Main.java
        ├── model/
        │   └── Student.java
        ├── controller/
        │   └── StudentController.java
        ├── dao/
        │   └── StudentDAO.java
        ├── view/
        │   └── StudentView.java
        └── util/
            ├── DBConnection.java
            └── DatabaseInitializer.java

```

### Your Task :
### 1. model/Student.java

Create the `Student` model with the following fields:

Field	Type
`studentID`	`int`
`name`	`String`
`department`	`String`
`marks`	`double`

Implement:

- A default constructor.
- A parameterized constructor: Student(int studentID, String name, String department, double marks)
- Getters and setters for all four fields.
### 2. util/DBConnection.java

Complete `getConnection()` to return a database connection using `DriverManager`.

- URL: jdbc:h2:./studentdb
- Username: sa
- Password: ""
### 3. util/DatabaseInitializer.java

Complete `initialize()` to create the `Student` table if it does not already exist. The table should initially be  **empty**.

```
StudentID    INT PRIMARY KEY
Name         VARCHAR(100) NOT NULL
Department   VARCHAR(100) NOT NULL
Marks        DOUBLE NOT NULL

```

### 4. dao/StudentDAO.java

Implement the database operations using JDBC. Use `PreparedStatement` for all database operations.

Method	Description
`addStudent(Student)`	Adds a new student to the database.
`getAllStudents()`	Returns all students ordered by `StudentID`. Returns an empty list if no students exist.
`getStudentById(int)`	Returns the student with the given ID, or `null` if not found.
`updateStudent(Student)`	Updates the student's name, department and marks. Returns `true` if updated, otherwise `false`.
`deleteStudent(int)`	Deletes the student with the given ID. Returns `true` if deleted, otherwise `false`.
### 5. controller/StudentController.java

The controller should use `StudentDAO` to perform all student operations.

Method	Description
`addStudent(Student)`	Adds a student.
`getAllStudents()`	Retrieves all students.
`getStudentById(int)`	Retrieves a student by ID.
`updateStudent(Student)`	Updates a student.
`deleteStudent(int)`	Deletes a student.

Each method should pass the operation to `StudentDAO`.

### 6. view/StudentView.java

Create a menu-driven interface for managing students. Display the following menu:

```
===== Student Management System =====
1. Add Student
2. View All Students
3. View Student by ID
4. Update Student
5. Delete Student
6. Exit
Enter your choice:

```

After completing an operation, the menu should be displayed again until the user selects  **6. Exit**.

### Option 1: Add Student

Ask the user for the Student ID, Name, Department and Marks, then add the student to the database. On success, display:

```
Student added successfully.

```

### Option 2: View All Students

Display all students in the following format:

```
ID    Name    Department    Marks

```

If there are no students, display:

```
No students found.

```

### Option 3: View Student by ID

Ask for the Student ID and display the student's details. If the student does not exist, display:

```
Student not found.

```

### Option 4: Update Student

Ask for the Student ID, then the new Name, Department and Marks, and update the student record. On success, display:

```
Student updated successfully.

```

If the student does not exist, display:

```
Student not found.

```

### Option 5: Delete Student

Ask for the Student ID and delete the record. On success, display:

```
Student deleted successfully.

```

If the student does not exist, display:

```
Student not found.

```

### Option 6: Exit

Terminate the menu-driven application and display:

```
Exiting application...

```

### Invalid Choice

If the user enters a choice other than `1` to `6`, display:

```
Invalid choice.

```

### 7. Main.java

The `Main` class should start the application in the following order:

- Initialize the database using DatabaseInitializer.
- Create a StudentController.
- Create a StudentView using the controller.
- Start the menu-driven application.

The database must be initialized before the menu is displayed.

### Example Interaction :

When the application starts:

```
===== Student Management System =====
1. Add Student
2. View All Students
3. View Student by ID
4. Update Student
5. Delete Student
6. Exit
Enter your choice:

```

To add a student:

```
Enter your choice: 1
Enter Student ID: 101
Enter Name: Rahul
Enter Department: Computer Science
Enter Marks: 85
Student added successfully.

```

To view all students:

```
Enter your choice: 2
ID    Name    Department    Marks
101   Rahul   Computer Science    85.0

```

To view a student by ID:

```
Enter your choice: 3
Enter Student ID: 101
Student ID: 101
Name: Rahul
Department: Computer Science
Marks: 85.0

```

To update a student:

```
Enter your choice: 4
Enter Student ID: 101
Enter new Name: Rahul Kumar
Enter new Department: Computer Science
Enter new Marks: 90
Student updated successfully.

```

To delete a student:

```
Enter your choice: 5
Enter Student ID: 101
Student deleted successfully.

```

To exit:

```
Enter your choice: 6
Exiting application...

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-07T08:36:07.917Z  

```cpp
        if (controller.deleteStudent(studentID)) {
            System.out.println("Student deleted successfully.");
        } else {
            System.out.println("Student not found.");
        }
    }

    private void displayStudent(Student student) {
        System.out.println("Student ID: " + student.getStudentID());
        System.out.println("Name: " + student.getName());
        System.out.println("Department: " + student.getDepartment());
        System.out.println("Marks: " + student.getMarks());
    }
}
```

---

[View on CodeChef](https://www.codechef.com/problems/EXP24HARD)