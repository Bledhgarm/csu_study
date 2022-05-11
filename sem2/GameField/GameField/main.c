#include "raylib.h"

#include <stdlib.h>
#include <time.h>

#define FPS 1000000

#define MOVE_CHANCE         0.45

#define FIELD_SIZE          WIDTH * HEIGHT / SQUARE_SIDE / SQUARE_SIDE / 2
#define SQUARE_SIDE         10
#define WIDTH               1920 / 2
#define HEIGHT              1080 / 2
#define COLOR               DARKGREEN
#define BACKGROUND_COLOR    RAYWHITE

void checkSeed(void) {
    static bool seedIsReady = false;
    if (!seedIsReady) {
        srand(time(NULL));
        seedIsReady = true;
    }
}

typedef struct {
	int x, y;
} Point;

typedef struct Node{
    Point point;
    struct Node* next;
    struct Node* prev;
} Node;

Node* newNode(void) {
    return (Node*)calloc(1, sizeof(Node));
}

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} Queue;

Queue* newQueue(void) {
    return (Queue*)calloc(1, sizeof(Queue));
}

void queuePush(Queue* queue, Point* point) {
    Node* node = newNode();
    node->point.x = point->x;
    node->point.y = point->y;
    queue->size++;
    if (queue->head == NULL) {
        queue->tail = node;
    }
    else {
        queue->head->prev = node;
        node->next = queue->head;
    }
    queue->head = node;
}

Node* queuePop(Queue* queue) {
    if (queue->size == 0) {
		return NULL;
    }
    queue->size--;
    Node* node = queue->tail;
    queue->tail = queue->tail->prev;
    if (queue->size == 0) {
        queue->head = queue->tail = NULL;
    }
    else {
        queue->tail->next = NULL;
    }
    return node;
}

void queueFree(Queue* queue) {
    Node* node = queue->head;
    for(int i = 0; i < queue->size; i++) {
        Node* nextNode = node->next;
        free(node);
        node = nextNode;
    }
    free(queue);
}

typedef struct {
	Point* points;	
    int side;
    int size;
    int area;
    Color color;
    int width;
    int height;
} Field;

void freeField(Field* field) {
    free(field->points);
    free(field);
}

bool fieldContainsPoint(Field* field, Point* point) {
    for (int i = 0; i < field->size; i++) {
        if (field->points[i].x == point->x && field->points[i].y == point->y)
            return true;
    }
    return false;
}

void drawSquare(Field* field, int index) {
        DrawRectangle(field->points[index].x, field->points[index].y, field->side, field->side, field->color);
}

void drawField(Field* field) {
    for (int i = 0; i < field->area; i++) {
        drawSquare(field, i);
    }
}

bool randChance(float chance) {
    checkSeed();
    return ((float)rand() / RAND_MAX) < chance;
}

Field* generateField(int width, int height, int size, int side, Color color) {
    checkSeed();
    Field* field = (Field*)malloc(sizeof(Field));
    field->color = color;
    field->size = size;
    field->side = side;
    field->width = width;
    field->height = height;
    field->area = 0;
    field->points = (Point*)calloc(field->size, sizeof(Point));

    // generate first point
    field->points[0].x = rand() % width;
    field->points[0].y = rand() % height;
    field->area++;
    Queue* queue = newQueue();
    queuePush(queue, &field->points[0]);

    for (int i = 1; i < field->size;) {
        Node* node = queuePop(queue);
        if (node == NULL) {
            int ind = rand() % i;
			queuePush(queue, &field->points[ind]);
            continue;
        }
        Point* point = &node->point;
        Point newPoints[4] = {{point->x, point->y + side}, {point->x, point->y - side}, {point->x - side, point->y}, {point->x + side, point->y}};
        for (int j = 0; j < 4 && i < field->size; j++) {
            bool newPointIsOkey = newPoints[j].x >= 0 && newPoints[j].x < width && newPoints[j].y >= 0 && newPoints[j].y < height;
            if (newPointIsOkey && randChance(MOVE_CHANCE) && !fieldContainsPoint(field, &newPoints[j])) {
                queuePush(queue, &newPoints[j]);
                field->points[i] = newPoints[j];
                field->area++;
                i++;
				BeginDrawing();
				ClearBackground(BACKGROUND_COLOR);
				drawField(field);
				EndDrawing();
            }
        }
        free(node);
    }
    queueFree(queue);
    return field;
}

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "2D Field");
    SetTargetFPS(FPS);
    Field* field = generateField(WIDTH, HEIGHT, FIELD_SIZE, SQUARE_SIDE, COLOR);
    int f = FIELD_SIZE;
    while (IsKeyPressed(KEY_ESCAPE) || !WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            freeField(field);
			field = generateField(WIDTH, HEIGHT, FIELD_SIZE, SQUARE_SIDE, COLOR);
        }
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        drawField(field);
        EndDrawing();
    }
    freeField(field);

    CloseWindow();

    return 0;
}
