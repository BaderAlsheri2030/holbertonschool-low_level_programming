#include <stdio.h>
#include <time.h> /* Added: declares clock_t, clock(), and CLOCKS_PER_SEC. */

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
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

    return sum;
}

int main(void)
{
    unsigned long checksum;

    /*
     * Added: clock_t variables hold clock readings in processor clock ticks.
     * Each phase has a start and end reading. TOTAL has its own pair.
     */
    clock_t total_start, total_end;
    clock_t build_start, build_end;
    clock_t process_start, process_end;
    clock_t reduce_start, reduce_end;

    /* Added: these variables hold the converted times in seconds. */
    double total_seconds;
    double build_seconds;
    double process_seconds;
    double reduce_seconds;

    /*
     * TOTAL begins immediately before data building and ends after reduction.
     * It includes the three function calls and the small timing overhead.
     */
    total_start = clock();

    /* BUILD_DATA measures only the build_dataset() call. */
    build_start = clock();
    build_dataset();
    build_end = clock();

    /* PROCESS measures only the process_dataset() call. */
    process_start = clock();
    process_dataset();
    process_end = clock();

    /* REDUCE measures only the reduce_checksum() call. */
    reduce_start = clock();
    checksum = reduce_checksum();
    reduce_end = clock();

    total_end = clock();

    /*
     * Added: subtracting clock readings gives elapsed processor clock ticks.
     * Divide by CLOCKS_PER_SEC to convert those ticks to seconds.
     */
    total_seconds =
        (double)(total_end - total_start) / CLOCKS_PER_SEC;
    build_seconds =
        (double)(build_end - build_start) / CLOCKS_PER_SEC;
    process_seconds =
        (double)(process_end - process_start) / CLOCKS_PER_SEC;
    reduce_seconds =
        (double)(reduce_end - reduce_start) / CLOCKS_PER_SEC;

    /*
     * Keep the checksum calculation, but do not print it: the required output
     * contract allows exactly four timing lines and no additional output.
     */
    (void)checksum;

    /* Added: print exactly four lines, in the required order and format. */
    printf("TOTAL seconds: %.6f\n", total_seconds);
    printf("BUILD_DATA seconds: %.6f\n", build_seconds);
    printf("PROCESS seconds: %.6f\n", process_seconds);
    printf("REDUCE seconds: %.6f\n", reduce_seconds);

    return 0;
}
