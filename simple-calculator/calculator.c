#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool isend = true;
	int choice;
	int a;
	int b;
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
		 printf("choice: %d\n", choice);
		 printf("Enter Value A:");
		 scanf("%d",&a);
		 printf("Enter Value B: ");
		 scanf("%d",&b);
		 printf("A:  %d\n",a); 
		 printf("B: %d\n",b);
		 printf("Result: %d\n", a + b); 
	 }
	 else if (choice ==2) {
		 /* code goes here*/
		 printf("choice: %d\nEnter Value A and B: ", choice);
                 scanf("%d %d", &a, &b);
                 printf("A:  %d\nB: %d\nResult: %d\n", a, b, a - b);
	 }

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
