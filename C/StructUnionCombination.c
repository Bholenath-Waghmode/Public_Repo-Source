
#include <stdio.h>
#include <stdint.h>

typedef struct {
    union {
        uint32_t data;
        struct {
            uint8_t byte0;
            uint8_t byte1;
            uint8_t byte2;
            uint8_t byte3;
        };
        struct {
            unsigned int bit0 : 1;
            unsigned int bit1 : 1;
            // ...
            unsigned int bit31 : 1;
        };
        struct {
            uint16_t halfword0;
            uint16_t halfword1;
        };
    };
} Memory;

int main() {
    Memory memory;
    memory.data = 0xDEADBEEF; // Example 32-bit value

    // Bit-wise access
    printf("Bit 0: %u\n", memory.bit0);
    printf("Bit 1: %u\n", memory.bit1);
    // ...
    printf("Bit 31: %u\n", memory.bit31);

    // Byte-wise access
    printf("Byte 0: 0x%02X\n", memory.byte0);
    printf("Byte 1: 0x%02X\n", memory.byte1);
    printf("Byte 2: 0x%02X\n", memory.byte2);
    printf("Byte 3: 0x%02X\n", memory.byte3);

    // 16-bit-wise access
    printf("Halfword 0: 0x%04X\n", memory.halfword0);
    printf("Halfword 1: 0x%04X\n", memory.halfword1);

    // Word-wise access
    uint32_t word = memory.data;
    printf("Word: 0x%08X\n", word);

    return 0;
}
