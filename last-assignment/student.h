/**
 * @file student.h
 * @author Arian Ahmadinejad
 * @date April 9 2022
 */

/**
 * Student type stores a student with fields first_name, last_name, id, grades and num_grades
 */
typedef struct _student
{
  char first_name[50]; /**< the student's first name */
  char last_name[50];  /**< the student's last name */
  char id[11];         /**< the student's 11 character identification string*/
  double *grades;      /**< a list of grades a student got*/
  int num_grades;      /**< a count of how many grades a student got*/
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student *generate_random_student(int grades);
