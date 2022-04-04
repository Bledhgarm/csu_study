#include <stdio.h>

struct complex {
    int firstOperand, secondOperand, thirdOperation, fourthOperation, result;
}comp;

struct operations {
    char operation;
    char open;
    char close;
    char comma;
    char space;
}op;

int main(void) {
    int result_2 = 0;
    scanf_s("%c%d%c%d%c%c%c%c%c%d%c%d%c", &op.open, 1, &comp.firstOperand, &op.comma, 1, &comp.secondOperand, &op.close, 1, &op.space, 1, &op.operation, 1, &op.space, 1, &op.open, 1, &comp.thirdOperation, &op.comma, 1, &comp.fourthOperation, &op.close, 1);

    switch (op.operation) {
    case '+':
        comp.result = comp.firstOperand + comp.thirdOperation;
        result_2 = comp.secondOperand + comp.fourthOperation;
        break;
    case '-':
        comp.result = comp.firstOperand - comp.thirdOperation;
        result_2 = comp.secondOperand - comp.fourthOperation;
        break;
    case '*':
        comp.result = comp.firstOperand * comp.thirdOperation - comp.secondOperand * comp.fourthOperation;
        result_2 = comp.firstOperand * comp.fourthOperation + comp.secondOperand * comp.thirdOperation;

        break;

    default:
        printf_s("ERROR: UNKNOWN OPERATION\nEXIT WITH ERROR CODE 1\n");
    }
    printf_s("(%d,%d)\n", comp.result, result_2);
    if (comp.result == 0) {
        printf_s("%di", result_2);
    }
    else if (result_2 == 0) {
        printf_s("%d", comp.result);
    }
    else if (comp.result == 0 && result_2) {
        printf_s("%d", comp.result);
    }
    else if (result_2 <= 0) {
        printf_s("%d%di", comp.result, result_2);
    }
    else {
        printf_s("%d + %d", comp.result, result_2);
    }
    return 0;
}