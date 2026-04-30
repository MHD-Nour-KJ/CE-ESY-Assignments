#include <stdio.h>
#include <string.h>
#define SIZE 15

typedef struct {
    char buffer[SIZE];
    int head, tail, counter;
} CircularBuffer;

void start(CircularBuffer *cirBuff) {
    cirBuff->head = 0;
    cirBuff->tail = 0;
    cirBuff->counter = 0;
}

int isFull(CircularBuffer *cirBuff) {
    return cirBuff->counter == SIZE;
}

int isEmpty(CircularBuffer *cirBuff) {
    return cirBuff->counter == 0;
}

void write(CircularBuffer *cirBuff, char data) {
    if (isFull(cirBuff)) {
        printf("Buffer Overflow\n");
        return;
    }
    cirBuff->buffer[cirBuff->tail] = data;
    cirBuff->tail = (cirBuff->tail + 1) % SIZE;
    cirBuff->counter++;
}

char read(CircularBuffer *cirBuff) {
    if (isEmpty(cirBuff)) {
        printf("Buffer Underflow\n");
        return '\0';
    }
    char data = cirBuff->buffer[cirBuff->head];
    cirBuff->head = (cirBuff->head + 1) % SIZE;
    cirBuff->counter--;
    return data;
}

int main() {

    printf("\n");

    CircularBuffer cirBuff;
    start(&cirBuff);
    
    char theName[100];
    scanf("%s", theName);
    
    strcat(theName, "CE-ESY");
    
    for (int i = 0; i < strlen(theName); i++) {
        write(&cirBuff, theName[i]);
    }
    
    while (!isEmpty(&cirBuff)) {
        char x = read(&cirBuff);
        if (x != '\0') {
            printf("%c", x);
        }
    }
    return 0;
}
