#include "utils.h"
#include <string.h>


void clean_fgets(char *pos) {
  strtok(pos, "\n");
}
