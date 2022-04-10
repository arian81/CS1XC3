/**
 * @file course.c
 * @author Arian Ahmadinejad
 * @date April 9 2022
 */
#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Adds student to a course by adding one to the total count of students in the course.
 * It then uses calloc to instantiate the list holding students if there are no students enrolled in
 * the course before or uses realloc to resize the list to fit one more student.
 * In the end it adds the student to the list.
 *
 * @param course a struct that holds the information about a course
 * @param student a struct that holds information about a student
 * @return nothing
 */

void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1)
  {
    course->students = calloc(1, sizeof(Student));
  }
  else
  {
    course->students =
        realloc(course->students, course->total_students * sizeof(Student));
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief prints a course's data in a user-friendly format(name, code, total students, and the information of all students enrolled in the course)
 *
 * @param course a struct that holds the information about a course
 * @return nothing
 */
void print_course(Course *course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++)
    print_student(&course->students[i]);
}

/**
 * @brief Finds the student with highest mark
 *
 * @param course a struct that holds the information about a course
 * @return Student struct
 */

Student *top_student(Course *course)
{
  if (course->total_students == 0)
    return NULL;

  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
  // uses the general algorithm for finding max number in a list where you choose some arbitary number, chekc if the value at current index is bigger and if yes swap the values until you get to end of the list.
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average)
    {
      max_average = student_average;
      student = &course->students[i];
    }
  }

  return student;
}

/**
 * @brief goes through the list of students,finds and returns the list of students with averages more than 50% who are passing the course
 *
 * @param course a struct that holds the information about a course
 * @param total_passing an integer to keep track of how many students are passing the course
 * @return Student struct
 */

Student *passing(Course *course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;

  // counting how many students are above 50%
  for (int i = 0; i < course->total_students; i++)
    if (average(&course->students[i]) >= 50)
      count++;

  // making a list big enough to hold passing students (size was found in the loop above)
  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++;
    }
  }

  *total_passing = count;

  return passing;
}