#include <stdio.h>

/**
 * print_menu - Prints the calculator menu.
 */
void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
	printf("Choice: ");
}

/**
 * handle_operation - Handles the selected calculator operation.
 * @choice: User menu choice.
 */
void handle_operation(int choice)
{
	int a, b, result;

	if (choice < 0 || choice > 4)
		printf("Invalid choice\n");
	if (choice == 1)
	{
		printf("A: ");
		scanf("%d", &a);
		printf("B: ");
		scanf("%d", &b);
		result = a + b;
		printf("Result: %d\n", result);
	}
	if (choice == 2)
	{
		printf("A: ");
		scanf("%d", &a);
		printf("B: ");
		scanf("%d", &b);
		result = a - b;
		printf("Result: %d\n", result);
	}
	if (choice == 3)
	{
		printf("A: ");
		scanf("%d", &a);
		printf("B: ");
		scanf("%d", &b);
		result = a * b;
		printf("Result: %d\n", result);
	}
}

/**
 * main - Entry point for the simple calculator program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice;

	printf("Simple Calculator\n");
	do {
		print_menu();
		scanf("%d", &choice);
		handle_operation(choice);
	} while (choice != 0);

	printf("Bye!\n");

	return (0);
}
