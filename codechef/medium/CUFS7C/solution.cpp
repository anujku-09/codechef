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