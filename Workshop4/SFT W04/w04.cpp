#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_FACTORIALS 10000
#define NUM_FACTS 100

struct FactorialResults
{
	int results[MAX_FACTORIALS];
	int numResults;
};

int factorial(const int n)
{
	//Bug1: Invalid conditions, resulting in infinite recursive calls
	//return (n <= n) ? n * factorial(n - 1) : 1;
	return (n > 1) ? n * factorial(n - 1) : 1; // Corrected
}

int reduceFactorial(const int n)
{
	//return n / n; // Bug2: Dividing n by n always results in 1, except when n is 0, causing division by zero error.
	return (n>0) ? (n/n) : 1; // correct
}

void computeFactorials(struct FactorialResults *results, int numFactorials) //Correct. revised 'results' to add pointer
{
	int i;
	for (i = 0; i < numFactorials; i++)
	{
		// Bug3: Incorrect member access for a pointer to struct. Should use '->' instead of '.'
		//results.results[i] = factorial(i);
		results->results[i] = factorial(i);
	}
	//Bug4: This line is redundant and incorrect, numResults is not used properly. Should assign directly to struct member.
	//results.numResults = numFactorials;
	results->results[i] = factorial(i);
}

int main(void)
{
	struct FactorialResults results = { {0}, 0 };
	int i;
	computeFactorials(&results, NUM_FACTS); //Corrected. add pointer symbol to parameter. The original 'computeFactorials(results, NUM_FACTS);'
	for (i = 0; i < NUM_FACTS; i++)
	{
		results.results[i] = reduceFactorial(results.results[i]);
		printf("%5d %12f\n", i, results.results[i]);
	}
	return 0;
}