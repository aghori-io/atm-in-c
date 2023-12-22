#include<stdio.h>
#define PIN 1234

int main() {
	char proceed;
	int inpPin, re;
	float amt, wdrawAmt;
	
	amt = 9999.99;
	printf("Insert your ATM \a");
	scanf("%c", &proceed);
	pinEntry:
	printf("Enter your pin: \a");
	scanf("%d", &inpPin);
	
	if(inpPin==PIN){
		amtEntry:
		printf("Enter the amount you want to withdraw: \a");
		scanf("%2f", &wdrawAmt);
		
		if (amt<wdrawAmt) {
			printf("\nInsufficient Balance\n\n\a\a");
			goto amtEntry;
		}
			else {
				amt = amt - wdrawAmt;
				printf("________________\n");
					printf("Please Collect Your Cash \a\nLast Withdraw Amt: %.2f \n", wdrawAmt);
					printf("Remaining Balance: %.2f \n", amt);
					printf("________________\nThank You");
					printf("Withdraw Again? \t 0. No 1. Yes \n");
					fflush(stdin);
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
	
	

