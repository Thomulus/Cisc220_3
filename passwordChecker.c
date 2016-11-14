#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

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
	printf("%d",ch);
	return ch;
}

int main(){
	char pswrd[24];
	int i = 0;
	character();
	/*while(1){
		pswrd[i]=character();
		///if (pswrd[i] == "\n"){
		//	break;
		///	printf("1");
		}
		i++;
	}*/
	//printf("%d Hello my baby hello my darling, \n hello my ragtime gal \n", pswrd[1]);
}
		
