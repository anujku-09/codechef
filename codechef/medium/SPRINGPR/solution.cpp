package com.example.demo;

import com.example.demo.model.Student;
import com.example.demo.service.StudentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

@Component
public class CollegeApp implements CommandLineRunner {

    @Autowired
    private StudentService studentService;

    @Override
    public void run(String... args) {
        System.out.println("Student Details:");
        for (Student s : studentService.getAllStudents()) {
            System.out.println("Name: " + s.getName() + ", Branch: " + s.getBranch());
        }
    }
}