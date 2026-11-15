        });
            }
                required: true
                type: String,
            course: {
            },
                unique: true
                required: true,
                type: String,
            email: {
            },
                required: true
                type: Number,
            },
            age: {
                type: String,
                required: true
            name: {

        // Task 2: Define studentSchema
        const studentSchema = new mongoose.Schema({
        console.log("Connected to MongoDB");
        await mongoose.connect(MONGO_URI);
    try {
async function run() {
// Task 1: Connect to MongoDB

const MONGO_URI = "mongodb://127.0.0.1:27017/studentdb";
const mongoose = require('mongoose');

// Connection string for the lab environment

        // Task 3: Create the Student model