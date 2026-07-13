#include <stdio.h>
#include <stdint.h>

// Function pointer example
void printValue(uint32_t value) {
    printf("Value: 0x%08X\n", value);
} 

void processValue(uint32_t value, void (*callback)(uint32_t)) {
    // Perform some processing (for demonstration, we'll just call the callback)
    callback(value);
}  

void exampleFunctionPointerUsage() {
    uint32_t value = 0xDEADBEEF; // Example 32-bit value
    processValue(value, printValue); // Passing function pointer as callback
}

// Array of function pointers example
void printValueHex(uint32_t value) {
    printf("Value (Hex): 0x%08X\n", value);
}

void printValueDec(uint32_t value) {
    printf("Value (Decimal): %u\n", value);
}


// Main function demonstrating function pointer usage and pointer arithmetic

int main() {
    exampleFunctionPointerUsage();  

    // Array of function pointers
    void (*callbacks[])(uint32_t) = {printValue, printValueHex, printValueDec};
    int numCallbacks = sizeof(callbacks) / sizeof(callbacks[0]);

    uint32_t value = 0xDEADBEEF;
    for (int i = 0; i < numCallbacks; i++) {
        callbacks[i](value);
    }

    //uint32_t value = 0xDEADBEEF; // Example 32-bit value
    uint8_t *bytePtr = (uint8_t *)&value; // Pointer to the first byte of the value

    // Accessing individual bytes using pointer arithmetic
    printf("Byte 0: 0x%03X\n", bytePtr[0]); // Least significant byte
    printf("Byte 1: 0x%03X\n", bytePtr[1]);
    printf("Byte 2: 0x%03X\n", bytePtr[2]);
    printf("Byte 3: 0x%03X\n", bytePtr[3]); // Most significant byte

    return 0;
}





