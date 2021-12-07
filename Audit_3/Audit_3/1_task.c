#include <stdio.h> 

int main(void) {
    int firstOperand, secondOperand, thirdOperation, fourthOperation, result = 0;
    int result_2 = 0;
    char operation;
    char open;
    char close;
    char comma;
    char space;
    scanf_s("%c%d%c%d%c%c%c%c%c%d%c%d%c", &open,1, &firstOperand, &comma, 1, &secondOperand, &close, 1, &space, 1, &operation, 1, &space, 1, &open, 1,&thirdOperation, &comma, 1, &fourthOperation, &close, 1);

    switch (operation) {
    case '+':
        result = firstOperand + thirdOperation;
        result_2 = secondOperand + fourthOperation;
        break;
    case '-':
        result = firstOperand - thirdOperation;
        result_2 = secondOperand - fourthOperation;
        break;
    case '*':
        result = firstOperand * thirdOperation - secondOperand * fourthOperation;
        result_2 = firstOperand * fourthOperation + secondOperand * thirdOperation;
        
        break;

    default:
        printf_s("ERROR: UNKNOWN OPERATION\nEXIT WITH ERROR CODE 1\n");
    }
    printf_s("(%d,%d)\n", result, result_2);
    if (result == 0) {
        printf_s("%di", result_2);
    }
    else if (result_2 == 0) {
        printf_s("%d", result);
    }
    else if (result == 0 && result_2) {
        printf_s("%d", result);
    }
    else if (result_2 <= 0){
        printf_s("%d%di", result, result_2);
    }
    else {
        printf_s("%d + %d", result, result_2);
    }
    return 0;
}