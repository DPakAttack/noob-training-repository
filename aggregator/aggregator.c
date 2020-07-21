#include "stdio.h"
#include "stdlib.h"


int aggregate(int values_count, char** values, int identity, int (*aggregator)(int, int));
int add(int first, int second);
int mult(int first, int second);


int main(int argc, char** argv) {
  int agg_fn_selector;
  int aggregation;

  printf("Select aggregation function to use (1: add, 2: mult):");

  scanf("%d", &agg_fn_selector);

  if (agg_fn_selector == 1) {
    aggregation = aggregate(argc - 1, argv + 1, 0, add);
  } else if (agg_fn_selector == 2) {
    aggregation = aggregate(argc - 1, argv + 1, 1, mult);
  } else {
    printf("Invalid aggregation function specified.\n");
    return 1;
  }

  printf("Aggregation: %d\n", aggregation);

  return 0;
}


int aggregate(int values_count, char** values, int identity, int (*aggregator)(int, int)) {
  int aggregation = identity;
  
  for (char** value = values; value < values + values_count; value++) {
    printf("%s\t", *value);
    aggregation = (*aggregator)(aggregation, atoi(*value));
  }

  return aggregation;
}


int add(int first, int second) {
  return first + second;
}


int mult(int first, int second) {
  return first * second;
}
