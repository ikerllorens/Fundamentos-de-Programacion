#include "DynamicMemory.h"

int main(int argc, char *argv[]) {

  Vector vec = newVector(6);
  int test[5] = {1, 2, 3, 4, 5};

  for (int i = 0; i < 5; i++) {
    insert(vec, test[i], i);
  }

  printVector(vec);

  push_back(vec, 6);
  printVector(vec);

  pop_back(vec);
  printVector(vec);

  clearVector(vec);
  printVector(vec);


  vec = destroyVector(vec);
  return 0;
}
