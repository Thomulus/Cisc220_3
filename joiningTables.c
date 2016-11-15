//Thomas Parker 1009877
#include <stdio.h>

void main() {
	char students[6][24];
	char courses[6][24];
	char student_courses[12][24];
	int i = 0;
	FILE *fp;
	fp =  fopen("/home/thomas/Cisc220_3/student.txt","r");
	while (1){
		if (feof(fp)){
			break;
		}
		fgets(students[i],24, (FILE*)fp);
		i ++;
	}
	FILE *fl;
	i = 0;
	fl = fopen("/home/thomas/Cisc220_3/course.txt","r");
	while (1){
		if (feof(fl)){
			break;
		}
		fgets(courses[i],24, (FILE*)fl);
		i++;
	}
	FILE *fm;
	i =0;
	fm = fopen("/home/thomas/Cisc220_3/student_course.txt","r");
	while (1){
		if (feof(fm)){
			break;
		}
		fgets(student_courses[i],24, (FILE*)fm);
		i++;
	}
	while(1){
		int Lowest = 96;
		int LowestIndex = 0;
		int LowestWordIndex =0;
		for ( int m = 1; m<6; m++) {
			for ( int n = 0; n < 16; n++) {
				if (students[m][n] > 64){
					if (students[m][n] > 96){
						break;
					}
					if (students[m][n] < Lowest){
						Lowest = students[m][n];
						LowestIndex = m;
						LowestWordIndex = n;
						break;
					}
				}
			}
		}
		char StudentID[6];
		for ( int o = 0; o<6; o++){
			StudentID[o] = students[LowestIndex][o];
		}
		char StudentName[4];
		for ( int p =0; p<4; p++){
			if (students[LowestIndex][LowestWordIndex+p] > 64){
				StudentName[p] = students[LowestIndex][LowestWordIndex+p];
			}
			else {
				StudentName[p] = 32;
			}
			students[LowestIndex][LowestWordIndex+p] = 32;
		}
		for ( int q = 1; q<11; q++){
			for ( int r = 0; r<6; r++){
				if (student_courses[q][r] != StudentID[r]){
					break;
				}
				if (r ==5){
					printf("%s ",StudentName);:wq

					for ( int s = 1; s < 6; s++){
						if (courses[s][0] == student_courses[q][7]){
							for (int t =2; t<9; t++){
								printf("%c",courses[s][t]);
							}
						}
					}
					printf("\n");
				}
			}
		}
	int continuing = 0;
	for ( int z =1; z<6; z++){
		if ((students[z][7] <96) & (students[z][7] > 64)){
			continuing = 1;
		}
	}
	if (continuing == 0){
		break;
	}
	}
}
