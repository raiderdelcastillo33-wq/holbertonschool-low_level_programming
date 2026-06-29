#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

/**
 * next_value - Generate the next deterministic pseudo-random value.
 * @state: Pointer to the current generator state.
 *
 * Return: The updated state value.
 */
static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return (*state);
}

/**
 * build_dataset - Fill the static dataset with deterministic values.
 */
static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

/**
 * process_dataset - Apply arithmetic processing to each dataset value.
 */
static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

/**
 * reduce_checksum - Reduce the dataset into a checksum value.
 *
 * Return: The computed checksum.
 */
static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return (sum);
}

/**
 * main - Measure execution time for each program phase.
 *
 * Return: 0 on success, 1 if checksum is impossible.
 */
int main(void)
{
	unsigned long checksum;
	clock_t total_start, total_end;
	clock_t build_start, build_end;
	clock_t process_start, process_end;
	clock_t reduce_start, reduce_end;
	double total_seconds, build_seconds;
	double process_seconds, reduce_seconds;

	total_start = clock();
	build_start = clock();
	build_dataset();
	build_end = clock();
	process_start = clock();
	process_dataset();
	process_end = clock();
	reduce_start = clock();
	checksum = reduce_checksum();
	reduce_end = clock();
	total_end = clock();

	build_seconds = (double)(build_end - build_start);
	build_seconds /= (double)CLOCKS_PER_SEC;
	process_seconds = (double)(process_end - process_start);
	process_seconds /= (double)CLOCKS_PER_SEC;
	reduce_seconds = (double)(reduce_end - reduce_start);
	reduce_seconds /= (double)CLOCKS_PER_SEC;
	total_seconds = (double)(total_end - total_start);
	total_seconds /= (double)CLOCKS_PER_SEC;

	if (checksum == 0ul)
		return (1);

	printf("TOTAL seconds: %.6f\n", total_seconds);
	printf("BUILD_DATA seconds: %.6f\n", build_seconds);
	printf("PROCESS seconds: %.6f\n", process_seconds);
	printf("REDUCE seconds: %.6f\n", reduce_seconds);

	return (0);
}
