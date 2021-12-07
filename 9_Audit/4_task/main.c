#include <math.h.>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BEGIN_RAND_RANGE -10
#define END_RAND_RANGE 10

struct Point {
    int x, y;
};

struct Vector {
    struct Point begin;
    struct Point end;
}vector;

int getRandInt(int beginRange, int endRange);
void randInitVector(struct Vector *vector, int beginRange, int endRange);
void printVector(struct Vector *vector);
double getVectorModule(struct Vector *vector);

double getMaxVectorModule(struct Vector *vectors, unsigned count);

int main(void) {
    printf_s("Enter a number of vectors: ");
    unsigned vectorsNumber = 0;
    unsigned count = vectorsNumber;
    scanf_s("%u", &vectorsNumber);
    struct Vector *vectors = (struct Vector *)malloc(sizeof(struct Vector) * vectorsNumber);
    if (!vectors) return 1;
    printf_s("Vectors:\n");
    for (unsigned i = 0; i < vectorsNumber; ++i) {
        randInitVector(vectors + i, BEGIN_RAND_RANGE, END_RAND_RANGE);
        printVector(vectors + i);
        printf_s("\n");
    }
    printf_s("Max vector module: %g\n", getMaxVectorModule(vectors, vectorsNumber));

    system("pause");
    return 0;
}

int getRandInt(int beginRange, int endRange) {
    static char seed = 0;
    if (!seed) {
        srand((unsigned)(time(NULL)));
        seed = 1;
    }
    return rand() % (endRange - beginRange + 1) + beginRange;
}

void randInitVector(struct Vector *vector, int beginRange, int endRange) {
    vector->begin.x = getRandInt(beginRange, endRange);
    vector->begin.y = getRandInt(beginRange, endRange);
    vector->end.x = getRandInt(beginRange, endRange);
    vector->end.y = getRandInt(beginRange, endRange);
}

void printVector(struct Vector *vector) {
    printf_s("{ (%d, %d), (%d, %d) }", vector->begin.x, vector->begin.y, vector->end.x, vector->end.y);
}

double getVectorModule(struct Vector *vector) {
    int v_x = vector->end.x - vector->begin.x;
    int v_y = vector->end.y - vector->begin.y;
    double length = sqrt(pow(v_x, 2) + pow(v_y, 2));
    return length;
}

double getMaxVectorModule(struct Vector *vectors, unsigned count) {
    double temp = 0;
    int second_counter = 0;
    if (count == 1) {
        return getVectorModule(vectors);
    }
    else if (second_counter == 0) {
        temp = getVectorModule(vectors + second_counter);
    }
    second_counter++;
    if (count - 1 != second_counter) {
        getMaxVectorModule(vectors, count);
    }
    else if (getVectorModule(vectors + second_counter) > temp) {
        temp = getVectorModule(vectors + second_counter);
    }

    return temp;
}