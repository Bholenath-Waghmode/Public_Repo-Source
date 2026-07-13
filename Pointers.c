#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t value = 0xDEADBEEF; // Example 32-bit value
    uint8_t *bytePtr = (uint8_t *)&value; // Pointer to the first byte of the value

    // Accessing individual bytes using pointer arithmetic
    printf("Byte 0: 0x%03X\n", bytePtr[0]); // Least significant byte
    printf("Byte 1: 0x%03X\n", bytePtr[1]);
    printf("Byte 2: 0x%03X\n", bytePtr[2]);
    printf("Byte 3: 0x%03X\n", bytePtr[3]); // Most significant byte

    return 0;
}





