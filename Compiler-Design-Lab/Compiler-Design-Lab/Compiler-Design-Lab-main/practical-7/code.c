#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Stack for parser
int stack[MAX];
int top = -1;

// Push function
void push(int val) {
    stack[++top] = val;
}

// Pop function
void pop(int n) {
    top -= n;
}

// Display stack
void display() {
    int i;
    for(i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {

    // LALR Parsing Table (simplified)
    // States: 0–5
    // Terminals: id, +, $
    // Non-terminals: E, T

    char action[6][3][10] = {
        {"S5", "", ""},      // state 0
        {"", "S3", "ACC"},   // state 1
        {"", "R2", "R2"},    // state 2
        {"S5", "", ""},      // state 3
        {"", "R3", "R3"},    // state 4
        {"", "R1", "R1"}     // state 5
    };

    int goTo[6][2] = {
        {1,2},
        {-1,-1},
        {-1,-1},
        {-1,4},
        {-1,-1},
        {-1,-1}
    };

    char input[MAX];
    int ip = 0;

    printf("Enter input string (use i for id): ");
    scanf("%s", input);
    strcat(input, "$");

    push(0);

    while(1) {

        int state = stack[top];
        char symbol = input[ip];

        int col;

        if(symbol == 'i')
            col = 0;
        else if(symbol == '+')
            col = 1;
        else
            col = 2;

        char *act = action[state][col];

        if(act[0] == 'S') {

            int next = act[1] - '0';

            push(next);
            ip++;

        }
        else if(act[0] == 'R') {

            int rule = act[1] - '0';

            switch(rule) {

                case 1: // E -> E+T
                    pop(3);
                    push(goTo[stack[top]][0]);
                    break;

                case 2: // E -> T
                    pop(1);
                    push(goTo[stack[top]][0]);
                    break;

                case 3: // T -> id
                    pop(1);
                    push(goTo[stack[top]][1]);
                    break;
            }
        }
        else if(strcmp(act,"ACC")==0) {

            printf("String Accepted\n");
            break;
        }
        else {

            printf("String Rejected\n");
            break;
        }
    }

    return 0;
}
