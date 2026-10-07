# JAVEXP01

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Practice Problem - Movie Management API
### Instructions:
- Complete your code first.
- Click on "Run" to compile and run the application.
- Use the menu displayed in the console to test the movie operations.
- If you make any changes to the code after running, you must run the application again.
- At last, after running the code, click on "Submit".
### Goal :

Build a Java application that manages movie records using JDBC and MVC architecture.

The application must store movie data in an H2 database and provide CRUD operations through a simple menu-driven interface.

The application should use:

- Movie as the model.
- MovieDAO for database operations.
- MovieController to handle movie operations.
- MovieView for the menu-driven user interface.
- DBConnection to establish the database connection.
- DatabaseInitializer to create the database table.

All files are already provided. Complete the code marked `TODO`. Do not rename any class or method.

### Project Structure :

```
movie-jdbc-mvc/
├── pom.xml    (H2 dependency already added)
└── src/main/
    └── java/com/example/
        ├── Main.java
        ├── model/
        │   └── Movie.java
        ├── controller/
        │   └── MovieController.java
        ├── dao/
        │   └── MovieDAO.java
        ├── view/
        │   └── MovieView.java
        └── util/
            ├── DBConnection.java
            └── DatabaseInitializer.java

```

### Your Task :
### 1. model/Movie.java

Create the `Movie` model with the following fields:

Field	Type
`movieID`	`int`
`title`	`String`
`director`	`String`
`rating`	`double`

Implement:

- A default constructor.
- A parameterized constructor: Movie(int movieID, String title, String director, double rating)
- Getters and setters for all four fields.
### 2. util/DBConnection.java

Complete `getConnection()` to return a database connection using `DriverManager`.

- URL: jdbc:h2:./moviedb
- Username: sa
- Password: ""
### 3. util/DatabaseInitializer.java

Complete `initialize()` to create the `Movie` table if it does not already exist. The table should initially be  **empty**.

```
MovieID     INT PRIMARY KEY
Title       VARCHAR(100) NOT NULL
Director    VARCHAR(100) NOT NULL
Rating      DOUBLE NOT NULL

```

### 4. dao/MovieDAO.java

Implement the database operations using JDBC. Use `PreparedStatement` for all database operations.

Method	Description
`addMovie(Movie)`	Adds a new movie to the database.
`getAllMovies()`	Returns all movies ordered by `MovieID`. Returns an empty list if no movies exist.
`getMovieById(int)`	Returns the movie with the given ID, or `null` if not found.
`updateMovie(Movie)`	Updates the movie's title, director and rating. Returns `true` if updated, otherwise `false`.
`deleteMovie(int)`	Deletes the movie with the given ID. Returns `true` if deleted, otherwise `false`.
### 5. controller/MovieController.java

The controller should use `MovieDAO` to perform all movie operations.

Method	Description
`addMovie(Movie)`	Adds a movie.
`getAllMovies()`	Retrieves all movies.
`getMovieById(int)`	Retrieves a movie by ID.
`updateMovie(Movie)`	Updates a movie.
`deleteMovie(int)`	Deletes a movie.

Each method should pass the operation to `MovieDAO`.

### 6. view/MovieView.java

Create a menu-driven interface for managing movies. Display the following menu:

```
===== Movie Management System =====
1. Add Movie
2. View All Movies
3. View Movie by ID
4. Update Movie
5. Delete Movie
6. Exit
Enter your choice:

```

After completing an operation, the menu should be displayed again until the user selects  **6. Exit**.

### Option 1: Add Movie

Ask the user for the Movie ID, Title, Director and Rating, then add the movie to the database. On success, display:

```
Movie added successfully.

```

### Option 2: View All Movies

Display all movies in the following format:

```
ID    Title    Director    Rating

```

If there are no movies, display:

```
No movies found.

```

### Option 3: View Movie by ID

Ask for the Movie ID and display the movie's details. If the movie does not exist, display:

```
Movie not found.

```

### Option 4: Update Movie

Ask for the Movie ID, then the new Title, Director and Rating, and update the movie record. On success, display:

```
Movie updated successfully.

```

If the movie does not exist, display:

```
Movie not found.

```

### Option 5: Delete Movie

Ask for the Movie ID and delete the record. On success, display:

```
Movie deleted successfully.

```

If the movie does not exist, display:

```
Movie not found.

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
- Create a MovieController.
- Create a MovieView using the controller.
- Start the menu-driven application.

The database must be initialized before the menu is displayed.

### Example Interaction :

When the application starts:

```
===== Movie Management System =====
1. Add Movie
2. View All Movies
3. View Movie by ID
4. Update Movie
5. Delete Movie
6. Exit
Enter your choice:

```

To add a movie:

```
Enter your choice: 1
Enter Movie ID: 401
Enter Title: Inception
Enter Director: Christopher Nolan
Enter Rating: 8.8
Movie added successfully.

```

To view all movies:

```
Enter your choice: 2
ID    Title    Director    Rating
401   Inception   Christopher Nolan    8.8

```

To view a movie by ID:

```
Enter your choice: 3
Enter Movie ID: 401
Movie ID: 401
Title: Inception
Director: Christopher Nolan
Rating: 8.8

```

To update a movie:

```
Enter your choice: 4
Enter Movie ID: 401
Enter new Title: Inception (2010)
Enter new Director: Christopher Nolan
Enter new Rating: 9.0
Movie updated successfully.

```

To delete a movie:

```
Enter your choice: 5
Enter Movie ID: 401
Movie deleted successfully.

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
**Submitted:** 2026-10-07T08:38:48.397Z  

```cpp
        while (!scanner.hasNextInt()) { System.out.print(p); scanner.next(); }
        int v = scanner.nextInt(); scanner.nextLine(); return v;
    }
    private double readDouble(String p) {
        System.out.print(p);
        while (!scanner.hasNextDouble()) { System.out.print(p); scanner.next(); }
        double v = scanner.nextDouble(); scanner.nextLine(); return v;
    }
    private String readLine(String p) {
        System.out.print(p);
        return scanner.nextLine();
    }
}

```

---

[View on CodeChef](https://www.codechef.com/problems/JAVEXP01)