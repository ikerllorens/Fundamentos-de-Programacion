

struct _Vector {

  unsigned int size;
  int *values;
  unsigned int numberValues;
};

typedef struct _Vector *Vector;

Vector newVector(const unsigned int size);

void insert(Vector vec, const int value, const unsigned int index);
void push_back(Vector vec, const int value);
void pop_back(Vector vec);
void clearVector(Vector vec);
Vector destroyVector(Vector vec);
void printVector(const Vector vec);
