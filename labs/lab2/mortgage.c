// Part 2: Mortgage Calculator
// By: Arda Kurama

#include <stdio.h>

int main() {

	float principal, rate, interest, payment, balance, final; // Variable Declarations

	printf("\nPart 2: Mortgage Calculator\n"); // Initial I/O prompting for principal
	printf("By: Arda Kurama\n\n");
	printf("\tEnter Desired Principal: ");
	scanf("%f", &principal);
	while (principal < 0) {  // If principal < 0, prompt again
		printf("\tInvalid Input. Please Try Again: ");
		scanf("%f", &principal);
	}
		
	printf("\tEnter Desired Interest Rate: "); // Initial I/O prompting for interest rate
	scanf("%f", &rate);
	while (rate < 0) {  // If rate < 0, prompt again
		printf("\tInvalid Input. Please Try Again: ");
		scanf("%f", &rate);
	}
		
	printf("\tEnter Desired Monthly Payment: "); // Initial I/O prompting for monthly payment
	scanf("%f", &payment);
	while (payment < 0) {  // If payment < 0, prompt again
		printf("\tInvalid Input. Please Try Again: ");
		scanf("%f", &payment);
	}		

	printf("\n");	
	int month = 1; // Month 1 interest, balance, and header setup
	interest = (principal * rate) / 12;
	balance = (principal + interest) - payment;
	printf("\tMonth\t    Payment\t   Interest\t    Balance\n");

	while (balance >= 0) { // Main while loop to run until balance < 0
		printf("\t%d\t    $%6.2f\t    $%6.2f\t $%9.2f\n", month, payment, interest, balance); // Main printf for output
		month++; // Adds one month

		if (payment > balance) { // If payment > balance, calculator on last calculation
			interest = (balance * rate) / 12;
			final = balance; // Record final balance for final output
			printf("\t%d\t    $%6.2f\t    $%6.2f\t $%9.2f\n", month, balance, interest, 0);
		}

		if (month > 12 && (interest > payment)) { // If after 12 months, interest on balance is > than payment
			printf("\n\tPaying Your Loan is Impossile. Check Your Finances."); // Shut down program and prompt conclusion
			break; // Breaks out of while-loop to prevent infinite loop
		}
					
		interest = (balance * rate) / 12; // Interest recalculation for next month
		balance = (balance + interest) - payment; // Balance recalculation for next month
	}

	printf("\n\tYou paid a total of $%9.2f over %d years and %d months.\n\n", (payment * (month - 1)) + final, month / 12, month % 12); // Final output prompt using "/" and "%" to convert months to years + months and displaying final value stored above

	return 0;
}
