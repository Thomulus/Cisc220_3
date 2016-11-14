#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char character()
{
	struct termios old,new;
	char ch;
	tcgetattr( STDIN_FILENO, &old);
	new = old;
	new.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &new);
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &old);
	return ch;
}

int main(){
	int quality = 0;
	char pswrd[24];
	int i = 0;
	while(1){
		if ((pswrd[i]=character())!='\n'){
			i++;
		}
		else{
			break;
		}
	}
	if (i >=8){
		quality += 1;
	}
	size_t len = strlen(pswrd);
	size_t dif = strcspn(pswrd,"@#$%&*+-=");
	if (len != dif){
		quality+=1;
	}
	dif = strcspn(pswrd,"1234567890");
	if (len != dif){
		quality+=1;
	}
	switch(quality) {
		case 0:
			printf("Terrible\n");
			break;
		case 1:
			printf("Weak\n");
			break;
		case 2:
			printf("Moderate\n");
			break;
		case 3:
			printf("Strong\n");
			break;
	}
}
		
