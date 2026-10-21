    console.log();


  } catch (error) {
    console.error("Error:", error.message);
  } finally {
    // TODO: Delete a student using its ID.
    const deletedPriya = await Student.findByIdAndDelete(priyaId)
    console.log("Student deleted:");
    console.log(deletedPriya);
    // Delete a student by ID

    console.log();

    console.log(updatedRahul);
    console.log("Student updated:");
    );
      {new: true}
      {age : 23},