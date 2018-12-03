#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "dynamicArray.h"

#define M_PI 3.14159265358979323846
#define M_E 2.71828182845904523536

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}


/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 2);

	double operand1;
	double operand2;

	operand2 = topDynArr(stack);
	popDynArr(stack);
	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, operand1 + operand2);

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 2);

	double operand1;
	double operand2;

	operand2 = topDynArr(stack);
	popDynArr(stack);
	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, operand1 - operand2);


}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 2);

	double operand1;
	double operand2;

	operand2 = topDynArr(stack);
	popDynArr(stack);
	operand1 = topDynArr(stack);
	popDynArr(stack);
	if (operand2 == 0)
	{
		printf("Error - You Cannot Divide By Zero\n");
		printf("Goodbye");
		exit(0);
	}
	else
	{
		pushDynArr(stack, operand1 / operand2);
	}
}


/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their product is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 2);

	double operand1;
	double operand2;

	operand2 = topDynArr(stack);
	popDynArr(stack);
	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, operand1 * operand2);

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their result is pushed back onto the stack.
*/
void power(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 2);

	double operand1;
	double operand2;

	operand2 = topDynArr(stack);
	popDynArr(stack);
	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(operand1, operand2));

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top two elements are popped and
	their result is pushed back onto the stack.
*/
void square(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 1);

	double operand1;

	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(operand1, 2));

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top two elements are popped and
	their result is pushed back onto the stack.
*/
void cubing(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 1);

	double operand1;

	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(operand1, 3));

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top two elements are popped and
	their result is pushed back onto the stack.
*/
void absolute(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 1);

	double operand1;

	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, abs(operand1));

}


/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top two elements are popped and
	their result is pushed back onto the stack.
*/
void squareRoot(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 1);

	double operand1;

	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, sqrt(operand1));

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top two elements are popped and
	their result is pushed back onto the stack.
*/
void exponential(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 1);

	double operand1;

	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, exp(operand1));

}


/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top two elements are popped and
	their result is pushed back onto the stack.
*/
void naturalLog(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 1);

	double operand1;

	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, log(operand1));

}


/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top two elements are popped and
	their result is pushed back onto the stack.
*/
void regularLog(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	/* FIXME: You will write this function */
	assert(sizeDynArr(stack) >= 1);

	double operand1;

	operand1 = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, log10(operand1));

}


double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	double num;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			square(stack);
		else if(strcmp(s, "^3") == 0)
			cubing(stack);
		else if(strcmp(s, "abs") == 0)
			absolute(stack);
		else if(strcmp(s, "sqrt") == 0)
			squareRoot(stack);
		else if(strcmp(s, "exp") == 0)
			exponential(stack);
		else if(strcmp(s, "ln") == 0)
			naturalLog(stack);
		else if(strcmp(s, "log") == 0)
			regularLog(stack);
		else 
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			if (isNumber(s, &num) == 1)
			{
				pushDynArr(stack, num);
			}
			else if(strcmp(s, "pi") == 0)
			{
				pushDynArr(stack, M_PI);
			}
			else if(strcmp(s, "e") == 0)
			{
				pushDynArr(stack, M_E);
			}
			else
			{
				printf("Invalid entry: %s\nProgram Execution Halted \n", s);
				printf("Goodbye");
				exit(0);
			}
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	//should be only one number left on the stack
	if(sizeDynArr(stack) == 1)
	{
		result = topDynArr(stack);
	}
	else
	{
		printf("Error: input formatted incorrectly, too many numbers left on the stack.\n");
		printf("Goodbye");
		exit(0);
	}

	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	printf("RPN Calculator\n\n");

	printf("The result of the calculation is: %f\n\n", calculate(argc,argv));
	printf("Goodbye");
	return 0;
}
