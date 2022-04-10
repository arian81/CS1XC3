/**
 * @file course.h
 * @author Arian Ahmadinejad
 * @date April 9 2022
 */

#include "student.h"
#include <stdbool.h>

/**
 * course type stores a course with fields : name, code, students, total_students
 */

typedef struct _course
{
  char name[100];     /**< name of the course*/
  char code[10];      /**< course code */
  Student *students;  /**< list of students taking the course */
  int total_students; /**< count of students taking the course */
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course *course);
Student *passing(Course *course, int *total_passing);
