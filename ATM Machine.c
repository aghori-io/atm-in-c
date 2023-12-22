//This is a simple ATM machine program in C.

#include<stdio.h>
#define PIN 1234 //default pincode for the ATM

int main() {
	char proceed; //variable proceed takes a single key entry as sign to imitate the card has been inserted
	int inpPin, re; //inpPin variable takes user input pincode
	float amt, wdrawAmt;
	
	amt = 9999.99;
	printf("Insert your ATM \a");
	scanf("%c", &proceed);
	pinEntry:
	printf("Enter your pin: \a");
	scanf("%d", &inpPin);
	
	if(inpPin==PIN){ //program proceeds if the user input pin matches the predefined pincode, else it restarts from pinEntry
		amtEntry:
		printf("Enter the amount you want to withdraw: \a");
		scanf("%2f", &wdrawAmt);
		
		if (amt<wdrawAmt) {
			printf("\nInsufficient Balance\n\n\a\a");
			goto amtEntry;
		}
			else {
				amt = amt - wdrawAmt; //calculation of remaining balance in the account
				printf("________________\n");
					printf("Please Collect Your Cash \a\nLast Withdraw Amt: %.2f \n", wdrawAmt); 
					printf("Remaining Balance: %.2f \n", amt); //limiting amount to 2 decimal points 
					printf("________________\nThank You");
					printf("Withdraw Again? \t 0. No 1. Yes \n"); //confirmation for rewithdrawal - if the user wants to withdraw amount again, the program goes to pinEntry
					fflush(stdin); //buffer clearance
					scanf("%d", &re); 
					if(re==1){
						goto pinEntry;
					}
					else goto finish;
					
				}
				
				
			
		
		 }
		else {
			printf("WRONG PIN \n_________\n\a\a");
			goto pinEntry;
		}
		finish:
			return 0;
	
	}
	
	
