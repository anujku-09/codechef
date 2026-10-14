# CUFS7C

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Authentication System (Register, Login, Protected)

You are given a partially implemented  **Express.js backend**  that manages users stored  **in memory**  (no database is used). Your task is to implement  **password hashing**,  **two public routes**, a  **verifyToken middleware**, and  **one protected route**.

## Given Data
- The application maintains an in-memory users list, which starts empty:

```
let users = [];

```

- Each registered user must be stored in this format:

```
{
  id: 1,
  username: "alice",
  email: "alice@mail.com",
  passwordHash: "<bcrypt hash>"
}

```

- The id is assigned automatically using a counter that starts at 1 and increases by 1 for every new user
- The following constants are provided:

```
const SALT_ROUNDS = 10;
const JWT_SECRET = "SUPER_SECRET_AUTH_KEY";
const TOKEN_EXPIRY = "1h";

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
{ "username": "alice", "email": "alice@mail.com", "password": "alice123" }

```

 **Behavior:** 

- Read username, email and password from the request body
- If any of the three values is missing: Return HTTP 400 Return: { "message": "Username, email and password are required" }
- If a user with the same username already exists: Return HTTP 409 Return: { "message": "User already exists" }
- Otherwise: Hash the password using hashPassword Assign the next available id Push { id, username, email, passwordHash } into the users array Return HTTP 201 Return: { "message": "User registered successfully", "user": { "id": 1, "username": "alice", "email": "alice@mail.com" } }
- The response must never contain the password or the password hash
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
- If the credentials are valid: Sign a JWT using JWT_SECRET Payload must contain id and username Token must expire after TOKEN_EXPIRY Return HTTP 200 Return: { "message": "Login successful", "token": "<jwt token>" }
### 5. verifyToken Middleware

 **Function:**  `verifyToken(req, res, next)`

 **Behavior:** 

- Read the Authorization header from the request
- The header must be in the format: Bearer <token>
- If the header is missing, or does not start with Bearer : Return HTTP 401 Return: { "message": "No token provided" }
- Extract the token from the header
- Verify the token using JWT_SECRET inside a try-catch
- If verification fails because the token has expired (error name is TokenExpiredError): Return HTTP 401 Return: { "message": "Token expired" }
- If verification fails for any other reason: Return HTTP 403 Return: { "message": "Invalid token" }
- If verification succeeds: Attach the decoded payload to req.user Call next()
### 6. Protected Profile Route

 **Endpoint:**  `GET /api/profile`

 **Behavior:** 

- This route must run verifyToken before its handler
- Read the logged-in user's id from req.user
- Find that user in the users array
- If no matching user is found: Return HTTP 404 Return: { "message": "User not found" }
- If found: Return HTTP 200 Return: { "message": "Profile fetched successfully", "user": { "id": 1, "username": "alice", "email": "alice@mail.com" } }
- The response must never contain the password hash

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-14T12:41:05.533Z  

```cpp
import bcrypt from "bcryptjs";
import jwt from "jsonwebtoken";
import { fileURLToPath } from "url";

const app = express();
const PORT = 3000;

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

// --------------------
// In-memory User Data
// --------------------
let users = [];
let nextId = 1;

// Number of salt rounds used for hashing
const SALT_ROUNDS = 10;

// Secret key for signing tokens
const JWT_SECRET = "SUPER_SECRET_AUTH_KEY";

// Token lifetime
const TOKEN_EXPIRY = "1h";

// Middleware
app.use(cors());
app.use(express.json());
import express from "express";
import cors from "cors";
import path from "path";
```

---

[View on CodeChef](https://www.codechef.com/problems/CUFS7C)