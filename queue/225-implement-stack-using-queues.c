/*
Problem: 225. Implement Stack using Queues
Pattern: Queue
Time: push - O(n), pop/top/empty - O(1)
Space: O(n) for the underlying storage
Idea: Use a single queue. On push, enqueue the new element, then rotate 
      the queue n times (n = size before the push) by dequeuing and 
      re-enqueuing each existing element. This brings the newest element 
      to the front, so pop/top can just read from the front directly, 
      giving LIFO behavior using only FIFO operations.
*/
typedef struct {
    int* data;
    int capacity;
    int front;
    int size;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = malloc(sizeof(MyStack));
    stack->capacity = 100;
    stack->data = malloc(stack->capacity * sizeof(int));
    stack->front = 0;
    stack->size = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    int n = obj->size;

    int backIndex = (obj->front + obj->size) % obj->capacity;
    obj->data[backIndex] = x;
    obj->size++;

    for (int i = 0; i < n; i++) {
        int dequeued = obj->data[obj->front];
        obj->front = (obj->front + 1) % obj->capacity;

        int newBack = (obj->front + obj->size - 1) % obj->capacity;
        obj->data[newBack] = dequeued;
    }
}

int myStackPop(MyStack* obj) {
    int val = obj->data[obj->front];
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return val;
}

int myStackTop(MyStack* obj) {
    return obj->data[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
}
