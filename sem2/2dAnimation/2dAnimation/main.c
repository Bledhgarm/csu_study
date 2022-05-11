#include "raylib.h"
#include <time.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

typedef enum {LEFT = -1, RIGHT = 1} Direction;

typedef struct {
    Point center;
    int radius;
    Color color;
    Direction direction;
    int speed;
} Ball;

void drawBall(Ball* ball) {
    DrawCircle(ball->center.x, ball->center.y, ball->radius, ball->color);
}

void collisions(Ball* left, Ball* right, int fieldWidth) {
    if (left->center.x + left->radius >= right->center.x - right->radius) {
        int col = (left->center.x + left->radius) - (right->center.x - right->radius);
        col /= 2;
        left->center.x -= col;
        right->center.x += col;
        left->direction *= -1;
        right->direction *= -1;
    }
    else {
        if (left->center.x - left->radius < 0) {
            left->direction *= -1;
			left->center.x = left->radius;
		}
        if (right->center.x + right->radius > fieldWidth) {
            right->direction *= -1;
            right->center.x = fieldWidth - right->radius;
        }
    }
}

void animationTick(Ball* left, Ball* right, int FPS) {
    left->center.x += left->speed * left->direction * (1. / FPS);
    right->center.x += right->speed * right->direction * (1. / FPS);
}

int main(void)
{
    srand(time(NULL));
    const SPEED = 500;
    const int RADIUS = 100;
    const int WIDTH = 800, HEIGHT = 600, FPS = 60;
    InitWindow(WIDTH, HEIGHT, "2D animation");
    SetTargetFPS(FPS);

    Ball leftBall = { (Point) { RADIUS + (WIDTH / 2 - 2 * RADIUS) * ((float)rand() / RAND_MAX), HEIGHT / 2 },
        RADIUS,
        RED,
        RIGHT,
        SPEED * ((float)rand() / RAND_MAX)};
    Ball rightBall = { (Point) { WIDTH - RADIUS - (WIDTH / 2 - 2 * RADIUS) * ((float)rand() / RAND_MAX) , HEIGHT / 2},
        RADIUS,
        GREEN,
        LEFT,
        SPEED * ((float)rand() / RAND_MAX) };


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        animationTick(&leftBall, &rightBall, FPS);
        collisions(&leftBall, &rightBall, WIDTH);
        drawBall(&leftBall);
        drawBall(&rightBall);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
