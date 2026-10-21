package com.example.demo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

@Component
public class OfficeApp implements CommandLineRunner{
    @Autowired
    private EmployeeService employeeService;

    @Override
    public void run(String... args) throws Exception {
        System.out.println("Student Details:");
        for(Employee s : employeeService.getAllStudents()) {
            System.out.println("Name: " + s.getName() + ", Branch: " + s.getBranch());
        }
    }
}