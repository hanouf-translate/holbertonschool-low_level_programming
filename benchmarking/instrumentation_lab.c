#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return (*state);
}

static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

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

static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return (sum);
}

int main(void)
{
	unsigned long checksum;
	clock_t global_start, global_end;
	clock_t t_start, t_end;
	double total_t, build_t, process_t, reduce_t;

	/* Start overall program timer */
	global_start = clock();

	/* Benchmark Phase 1: Build Dataset */
	t_start = clock();
	build_dataset();
	t_end = clock();
	build_t = (double)(t_end - t_start) / CLOCKS_PER_SEC;

	/* Benchmark Phase 2: Process Dataset */
	t_start = clock();
	process_dataset();
	t_end = clock();
	process_t = (double)(t_end - t_start) / CLOCKS_PER_SEC;

	/* Benchmark Phase 3: Reduce Checksum */
	t_start = clock();
	checksum = reduce_checksum();
	t_end = clock();
	reduce_t = (double)(t_end - t_start) / CLOCKS_PER_SEC;

	/* End overall program timer */
	global_end = clock();
	total_t = (double)(global_end - global_start) / CLOCKS_PER_SEC;

	if (checksum == 0ul)
		printf("impossible\n");

	/* Required output (exact contract format, 6 decimal points) */
	printf("TOTAL seconds: %.6f\n", total_t);
	printf("BUILD_DATA seconds: %.6f\n", build_t);
	printf("PROCESS seconds: %.6f\n", process_t);
	printf("REDUCE seconds: %.6f\n", reduce_t);

	return (0);
}
