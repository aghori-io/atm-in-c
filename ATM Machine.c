#include<stdio.h>
#include<ctype.h>

#define DEFAULT_PIN 1234
#define INITIAL_BALANCE 9999.99

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char proceed;
    int inputPin, re, option;
    float balance = INITIAL_BALANCE, wdrawAmt;
    int userPIN = DEFAULT_PIN;  // Variable to store the user's PIN

    printf("Successfully inserted ATM Card.\n");

    pinEntry:
    printf("Enter your PIN: ");
    if (scanf("%d", &inputPin) != 1 || inputPin < 1000 || inputPin > 9999) {
        printf("Invalid PIN. Please enter a 4-digit number.\n");
        clearInputBuffer(); // Clear input buffer
        goto pinEntry;
    }

    if (inputPin == userPIN) {
        menu:
        printf("\nATM Menu:\n1. Withdraw\n2. Display Balance\n3. Change PIN\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                amtEntry:
                printf("Enter the amount you want to withdraw: ");
                scanf("%f", &wdrawAmt);

                if (balance < wdrawAmt) {
                    printf("\nInsufficient Balance\n\n");
                    goto amtEntry;
                } else {
                    balance -= wdrawAmt;
                    printf("________________\n");
                    printf("Please Collect Your Cash\nLast Withdrawal Amount: %.2f\n", wdrawAmt);
                    printf("Remaining Balance: %.2f\n", balance);
                    printf("________________\nThank You\n");
                    printf("Withdraw Again? (0. No, 1. Yes): ");
                    scanf("%d", &re);

                    if (re == 1) {
                        goto pinEntry;
                    } else {
                        printf("Transaction Completed.\n");
                    }
                }
                break;

            case 2:
                printf("Your Current Balance: %.2f\n", balance);
                goto menu;

            case 3:
                printf("Enter new PIN: ");
                if (scanf("%d", &userPIN) != 1 || userPIN < 1000 || userPIN > 9999) {
                    printf("Invalid PIN. Please enter a 4-digit number.\n");
                    clearInputBuffer(); // Clear input buffer
                    goto menu;
                }
                printf("PIN successfully changed!\n");
                goto menu;

            case 4:
                printf("Transaction Completed.\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                goto menu;
        }
    } else {
        printf("Wrong PIN\n_________\n\n");
        goto pinEntry;
    }

    return 0;
}
