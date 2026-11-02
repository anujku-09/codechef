package com.example.demo.controller;

import com.example.demo.observer.NotificationLog;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

// TODO: mark this class as a REST controller
// TODO: set the base path to /api/notifications
@RestController
@RequestMapping("/api/notifications")
public class NotificationController {

    private final NotificationLog log;

    public NotificationController(NotificationLog log) {
        this.log = log;
    }