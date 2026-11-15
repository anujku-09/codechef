            Optional<Course> course = courseRepository.findById(3L);
            // READ ONE

            courseRepository.findAll().forEach(System.out::println);
            // READ ALL
            System.out.println(">>> All courses:");
            System.out.println(">>> Saved 5 courses");

            courseRepository.save(new Course("Database Systems",  3.0));
            courseRepository.save(new Course("Spring Boot",       4.0));
            courseRepository.save(new Course("Data Structures",   3.5));
            courseRepository.save(new Course("Web Development",   2.5));
            courseRepository.save(new Course("Java Basics",       3.0));
            course.ifPresent(c -> System.out.println(">>> Found: " + c));

            // UPDATE
            courseRepository.findById(2L).ifPresent(c -> {
                c.setCredits(5.0);
                courseRepository.save(c);
                System.out.println(">>> Updated: " + c);
            });

            // DELETE
            courseRepository.deleteById(5L);
            System.out.println(">>> Deleted course ID 5");

            // FINAL LIST
            System.out.println(">>> Final list:");
            courseRepository.findAll().forEach(System.out::println);
        };
    }
}