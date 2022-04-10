/**
 * @file main.c
 * @author Arian Ahmadinejad
 * @date April 9 2022
 * @mainpage Course Library
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

int main()
{
  srand((unsigned)time(NULL));

  /**
   * Initialize course "MATH101"
   */

  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics"); // setting the course name
  strcpy(MATH101->code, "MATH 101");              // setting the course code

  for (int i = 0; i < 20; i++)
    enroll_student(MATH101, generate_random_student(8)); // enrolling students in the course

  print_course(MATH101); // print the course info

  // finding and printing the top student
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);
  // finding and printing the total students passing and their name
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++)
    print_student(&passing_students[i]);

  return 0;
}