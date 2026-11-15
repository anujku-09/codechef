 // Task 9: Paginate the students
 // TODO: Return page 2 with a page size of 2.
 console.log("\nPaginated students:");
 const paginatedStudents = await Student.find()
     .sort({ age: 1 })
     .skip(2)
     .limit(2);
 paginatedStudents.forEach((s) => {
     console.log(`${s.name} ${s.age}`);
 });

 } catch (error) {
 console.error("Error:", error.message);
 } finally {
 // Task 10: Close the connection
 // TODO: Close the MongoDB connection here.
 await mongoose.connection.close();
 console.log("\nMongoDB connection closed");
 }
}

main();