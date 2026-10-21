    public Course updateCourse(@PathVariable Long id, @RequestBody Course updatedCourse) {

        Course course = courseRepository.findById(id).orElse(null);

        if (course != null) {
            course.setTitle(updatedCourse.getTitle());
            course.setCredits(updatedCourse.getCredits());
            return courseRepository.save(course);
    @PutMapping("/{id}")
    // Update Course

    }
        return courseRepository.findById(id).orElse(null);
    public Course getCourseById(@PathVariable Long id) {
    @GetMapping("/{id}")
    // Get Course By ID

    }
        return courseRepository.findAll();
        }