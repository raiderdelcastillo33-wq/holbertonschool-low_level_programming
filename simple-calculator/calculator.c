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
 * clear_input - Discards invalid characters from standard input.
 */
void clear_input(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
		;
}

/**
 * read_operands - Reads two integer operands.
 * @a: Pointer to the first operand.
 * @b: Pointer to the second operand.
 */
void read_operands(int *a, int *b)
{
	while (1)
	{
		printf("A: ");

		if (scanf("%d", a) == 1)
			break;

		printf("Invalid number\n");
		clear_input();
	}

	while (1)
	{
		printf("B: ");

		if (scanf("%d", b) == 1)
			break;

		printf("Invalid number\n");
		clear_input();
	}
}

/**
 * handle_operation - Handles the selected calculator operation.
 * @choice: User menu choice.
 */
void handle_operation(int choice)
{
	int a, b, result;
	double div_result;

	if (choice < 0 || choice > 4)
	{
		printf("Invalid choice\n");
		return;
	}

	if (choice == 1)
	{
		read_operands(&a, &b);
		result = a + b;
		printf("Result: %d\n", result);
	}

	if (choice == 2)
	{
		read_operands(&a, &b);
		result = a - b;
		printf("Result: %d\n", result);
	}

	if (choice == 3)
	{
		read_operands(&a, &b);
		result = a * b;
		printf("Result: %d\n", result);
	}

	if (choice == 4)
	{
		read_operands(&a, &b);

		if (b == 0)
			printf("Error: division by zero\n");
		else
		{
			div_result = (double)a / b;
			printf("Result: %.1f\n", div_result);
		}
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

	while (1)
	{
		print_menu();

		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid choice\n");
			clear_input();
			continue;
		}

		if (choice == 0)
			break;

		handle_operation(choice);
	}

	printf("Bye!\n");

	return (0);
}
