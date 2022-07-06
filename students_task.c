#include <stdio.h>
#include <string.h>
#include "student.h"

int filesize(char *fname)
{
	FILE *in=fopen(fname,"rb");
	fseek(in, 0L, SEEK_END);
	int size=ftell(in);
	fclose(in);
	return size;
}

void printstud(student cs1)
{
	printf("%-16s %-8s %-7s %-9d %-7c %-16s %-16s\n",cs1.lastname,cs1.initials,cs1.gender,cs1.grade_num,cs1.grade_letter,cs1.university,cs1.work_place);
}

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Usage: [filename] [-f|-p]\n");
		return 1;
	}
	int fsize=filesize(argv[1]);
	FILE *in1=fopen(argv[1],"rb");
	if(!in1)
	{
		printf("Cant open this file\n");
		return 2;
	}
	switch(argv[2][1])
	{
		case 'p':
		{
			int count=fsize/sizeof(student);
			student studs[count];
			char checked[count];
			memset(checked,0,count);
			fread(&studs,sizeof(student),count,in1);
			char found=0;
			printf("Однофамильцы:\n");
			for(int i=0;i<count;i++)
			{
				int eqs=0;
				for(int j=i+1;j<count;j++)
				{
					if(!checked[j] && strcmp(studs[i].lastname,studs[j].lastname)==0)
					{
						if(eqs==0)
							printstud(studs[i]);
						printstud(studs[j]);
						eqs++;
						checked[j]=1;
					}
				}
				if(eqs)
				{
					found=1;
					printf("\n");
				}
			}
			if(!found)
				printf("однофамильцев нет\n");
			break;
		}
		case 'f':
		{
			student cs1;
			printf("LASTNAME         INITIALS GENDER  GRADE_NUM LETTER  UNIVERSITY       WORK_PLACE\n");
			while(fread(&cs1,sizeof(cs1),1,in1)==1)
				printstud(cs1);
			break;
		}
		default:
			printf("unsupported argument\n");
	}
	fclose(in1);
    return 0;
}

