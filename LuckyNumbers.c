#include <stdio.h>
#include <stdlib.h>
int Lucky();
int Lucky() {
	int number[4];
	for ( int i=1000; i < 10000; i++ ){
		int j = i;
		int k = 3;
		while (j){
			number[k] = (j % 10);
			k = k - 1;
			j/=10;
		}
		if ((number[0] + number[1] + number[2] + number[3])%7 ==0){
			printf("%i\n",i);
		}
	}
	return 0;
}
int main(){
	Lucky();
}
