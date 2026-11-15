package com.example.demo.service;

import com.example.demo.model.Student;
import org.springframework.stereotype.Service;
import java.util.List;

@Service
public class StudentService {
    private final List<Student> students = List.of(
        new Student("Arjun", "Computer Science"),
        new Student("Meera", "Electronics"),
        new Student("Rahul", "Mechanical"),
        new Student("Sneha", "Civil")
    );

    public List<Student> getAllStudents() {
        return students;
    }
}