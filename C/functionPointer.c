#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int (*callback)(int, int) = NULL; 

int operationCallRegister(int (*fun)(int x, int y)) {
    if (fun != NULL) {
        // REMOVED: The misleading error print statement from here
        callback = fun; 
        return 1; // Good practice: return 1 for success
    } else {
        printf("Error: Function pointer is NULL.\n");
        return 0; // Return 0 for failure
    }
}

int main(void) {
    operationCallRegister(add);

    // Added a safety check in main just in case registration fails
    if (callback != NULL) {
        printf("Result of addition: %d\n", callback(2, 3)); 
    } else {
        printf("Failed to execute: Callback is NULL.\n");
    }

    return 0;
}
