# CUFS7B

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### User Authentication API (Register & Login)

You are given a partially implemented  **Express.js backend**  that manages users stored  **in memory**  (no database is used).
Your task is to implement the  **password hashing helpers**  and  **two API endpoints**  for registration and login.

## Given Data
- The application maintains an in-memory users list, which starts empty:

```
let users = [];

```

- Each registered user must be stored in this format:

```
{ username: "alice", passwordHash: "<bcrypt hash>" }

```

- The following constants are provided:

```
const SALT_ROUNDS = 10;
const JWT_SECRET = "SUPER_SECRET_AUTH_KEY";

```

## Tasks
### 1. Hash a Password

 **Function:**  `hashPassword(password)`

 **Behavior:** 

- Accept a plain-text password as a parameter
- Generate a salt using SALT_ROUNDS
- Hash the password with bcrypt using that salt
- Return the generated hash as a string
### 2. Verify a Password

 **Function:**  `verifyPassword(password, storedHash)`

 **Behavior:** 

- Accept a plain-text password and a bcrypt hash as parameters
- Compare the password against the hash using bcrypt
- Return true if the password matches the hash
- Return false if it does not match
### 3. Register a User

 **Endpoint:**  `POST /api/register`

 **Request body:** 

```
{ "username": "alice", "password": "alice123" }

```

 **Behavior:** 

- Read username and password from the request body
- If either value is missing: Return HTTP 400 Return: { "message": "Username and password are required" }
- If a user with the same username already exists: Return HTTP 409 Return: { "message": "User already exists" }
- Otherwise: Hash the password using hashPassword Push { username, passwordHash } into the users array Return HTTP 201 Return: { "message": "User registered successfully", "username": "alice" }
- The plain-text password must never be stored in the array
### 4. Login a User

 **Endpoint:**  `POST /api/login`

 **Request body:** 

```
{ "username": "alice", "password": "alice123" }

```

 **Behavior:** 

- Read username and password from the request body
- If either value is missing: Return HTTP 400 Return: { "message": "Username and password are required" }
- Find the user in the users array by exact username match
- If the user is not found, or the password does not match the stored hash: Return HTTP 401 Return: { "message": "Invalid credentials" }
- If the credentials are valid: Sign a JWT using JWT_SECRET Payload must contain username Token must expire in 1 hour Return HTTP 200 Return: { "message": "Login successful", "token": "<jwt token>" }

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-07T04:50:16.428Z  

```cpp
export default app;
export { hashPassword, verifyPassword, JWT_SECRET };
```

---

[View on CodeChef](https://www.codechef.com/problems/CUFS7B)