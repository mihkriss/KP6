#include <stdio.h>
#include <string.h>
#include "student.h"

// чтение информации студента с консоли
int readStudent1(student *a)
{
	return scanf("%[^;];%[^;];%[^;];%hd;%c;%[^;];%[^\n]\n",a->lastname,a->initials,a->gender,&a->grade_num,&a->grade_letter,a->university,a->work_place)==7;
}

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Usage: [filename]\n");
		return 1;
	}
	printf("input format:\nlastname;initials;gender;grade_num;grade_letter;university;work_place\n");
	FILE *out1=fopen(argv[1],"wb");
	if(!out1)
	{
		printf("Cant open this file\n");
		return 2;
	}
	student cs1;
	while(readStudent1(&cs1))
		fwrite(&cs1,sizeof(cs1),1,out1);
	printf("saved\n");
	fflush(out1);
	fclose(out1);
	return 0;
}

