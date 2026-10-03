import React from "react";

const StudentList = () => {
  const students = [
    { id: 1, name: "John", age: 20 },
    { id: 2, name: "Emma", age: 22 },
    { id: 3, name: "Liam", age: 19 },
    { id: 4, name: "Olivia", age: 21 }
  ];

  return (
    <div>
      {students.map((student) => (
        <div key = {student.id} className="student-card">
          <h3>{student.name}</h3>
          <p>Age: {student.age}</p>
        </div>
      ))}
    </div>
  );
};

export default StudentList;