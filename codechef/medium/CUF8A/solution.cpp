            console.log("Student saved:");
            const savedStudent = await student.save();
        try {
        const student = new Student ({
            name : "Anita Rao",
            age: 20,
            email: "anita.rao@example.com",
            course: "Computer Science"
        });

        // Task 4: Create and save one student document
        
        console.log("Connected to MongoDB");
        await mongoose.connect(MONGO_URI);
    try {
async function run() {
// Task 1: Connect to MongoDB

const Student = mongoose.model('Student', studentSchema, 'students');
            console.log(savedStudent);
        } catch (saveErr) {
            console.log(saveErr.message || saveErr);
        }
    } catch (err) {
        console.log(err.message || err);
    } finally {
        // Task 5: Close the connection
        await mongoose.connection.close();
    }
}

run();

