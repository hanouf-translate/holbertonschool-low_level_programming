#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool isend = true;
	int choice;
	printf("welcome\n");
	
	while(isend){
	 printf("Simple Calculator\n"
        "1) Add\n"
        "2) Subtract\n"
        "3) Multiply\n"
        "4) Divide\n"
        "0) Quit\n");

	 scanf("%d", &choice);

	 if (choice ==1){
		 /* code goes here*/
	 }
	 else if (choice ==2) {
		 /* code goes here*/}

	 else if (choice == 3) {
		 /* code goes here*/}
	else if (choice == 4){
		/* code goes here*/}
	else if (choice == 0){
		isend = false;}
	 else {
		printf("Invalid choice"); 
	 }


		
	}
	printf("Bye!");
	return 0;

	}
