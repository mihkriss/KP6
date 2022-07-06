#ifndef student_H
#define student_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// информация студента
typedef struct {
	char lastname[32];
	char initials[8];
	char gender[8];
	short int grade_num;
	char grade_letter;
	char university[16];
	char work_place[32];
} student;

#endif

