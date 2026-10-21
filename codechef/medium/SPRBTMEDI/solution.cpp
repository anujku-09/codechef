            studentRepository.save(new Student("David",   65.75));
            studentRepository.save(new Student("Eva",     79.0));
            System.out.println(">>> Saved 5 students");

            // READ ALL
            System.out.println(">>> All students:");
            studentRepository.findAll().forEach(System.out::println);

            // READ ONE
            Optional<Student> student = studentRepository.findById(3L);
            student.ifPresent(s -> System.out.println(">>> Found: " + s));

            // UPDATE
            studentRepository.findById(2L).ifPresent(s -> {
                s.setMarks(95.0);
                studentRepository.save(s);
                System.out.println(">>> Updated: " + s);
            });

            // DELETE
            studentRepository.deleteById(5L);
            System.out.println(">>> Deleted student ID 5");

            // FINAL LIST
            System.out.println(">>> Final list:");