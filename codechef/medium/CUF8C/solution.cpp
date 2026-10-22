    ]);

    // Task 5: Populate course information
    console.log("\nStudents with course details:");
    const populatedStudents = await Student.find().populate("course");
    populatedStudents.forEach((s) => {
      console.log(`${s.name} - ${s.course.name} (${s.course.code})`);
    });

    // Task 6: Filter students by course
    console.log("\nComputer Science students:");
    const csCourse = await Course.findOne({ code: "CS" });
    const csStudents = await Student.find({ course: csCourse._id });
    csStudents.forEach((s) => {
      console.log(s.name);
    });

    // Task 7: Search students by name
    console.log("\nStudents matching search:");
    const matchingStudents = await Student.find({
      name: { $regex: "ar", $options: "i" }
    });
    matchingStudents.forEach((s) => {
      console.log(s.name);
    });

    // Task 8: Sort students by age
    console.log("\nStudents sorted by age:");
    const sortedStudents = await Student.find().sort({ age: 1 });
    sortedStudents.forEach((s) => {
      console.log(`${s.name} - ${s.age}`);
    });

    // Task 9: Paginate the students
    console.log("\nPaginated students:");
    const paginatedStudents = await Student.find()
      .sort({ age: 1 })
      .skip(2)
      .limit(2);
    paginatedStudents.forEach((s) => {
      console.log(`${s.name} - ${s.age}`);
    });
  } catch (error) {
    console.error("Error:", error.message);
  } finally {
    // Task 10: Close the connection
    await mongoose.connection.close();
    console.log("\nMongoDB connection closed");
  }
}

main();