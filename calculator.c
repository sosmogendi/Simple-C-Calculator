#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * performCalculation - performs calculation on operands
 * @operand1: first operand
 * @operand2: second operand
 * @operator: operator to act on operands
 * Return: result of operation
 */

float performCalculation(float operand1, float operand2, char operator)
{
	float result;

	switch (operator)
	{
		case '/':
			if (operand2 != 0)
				result = operand1 / operand2;
			else
			{
				printf("Error: Division by zero is not allowed.\n");
				return (NAN);
			}
			break;
		case '*':
			result = operand1 * operand2;
			break;
		case '+':
			result = operand1 + operand2;
			break;
		case '-':
			result = operand1 - operand2;
			break;
		default:
			printf("Error: Invalid operator '%c'\n", operator);
			return NAN;
	}
	return (result);
}

/**
 * main - entry into the calculator
 *
 * @argc: no of args
 * @argv: array of args
 * Return: 0
 */

int main(void)
{
	float operand1;
	float operand2;
	char operator;
	float answer;
	int validInput;
	char userInput[256];

	while (1)
	{
		printf("Enter calculation (or 'q' to quit): ");
		fgets(userInput, sizeof(userInput), stdin);
		if (strcmp(userInput, "q\n") == 0 || strcmp(userInput, "Q\n") == 0)
		{
			break;
		}
		validInput = sscanf(userInput, "%f %c %f", &operand1, &operator, &operand2);
		if (validInput != 3)
		{
			printf("Error: Invalid input.\n");
			continue;
		}
		answer = performCalculation(operand1, operand2, operator);
		if (!isnan(answer))
		{
			printf("%.9g %c %.9g = %.6g\n\n", operand1, operator, operand2, answer);
		}
	}
	return (0);
}
