#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int *factorize(int number)
{
	int *factors = malloc(2 * sizeof(int));
	int index = 0;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			factors[index++] = i;
			factors[index++] = number / i;
			break;
		}
	}
	return factors;
}

int main(int argc, char *argv[])
{
	clock_t start_time = clock();

	if (argc < 2)
	{
		printf("Please provide a file path as an argument.\n");
		return 1;
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("File not found.\n");
		return 1;
	}

	char line[100];
	int *factors;

	while (fgets(line, sizeof(line), file))
	{
		int number = atoi(line);
		factors = factorize(number);
		printf("%d=%d*%d\n", number, factors[0], factors[1]);
		free(factors);
	}

	fclose(file);

	clock_t end_time = clock();
	double time_taken = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000;
	printf("Time taken: %f ms\n", time_taken);

	return 0;
}
