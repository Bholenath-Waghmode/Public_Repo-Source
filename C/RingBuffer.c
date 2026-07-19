// Ring buffer implementation in C17
//Author:Bholenath Waghmode
//Date: 2026/07/17  
#include <stdio.h>  

typedef unsigned int uint32_t; // Define uint32_t for C17
typedef unsigned char uint8_t; // Define uint8_t for C17

#define BUFFER_SIZE 10 // Define the size of the ring buffer
uint32_t buffer[BUFFER_SIZE]; // Example buffer of size 10

typedef struct MyBuffer{
    uint32_t *buffer; // Pointer to the buffer array
    uint32_t head;    // Index of the head of the buffer
    uint32_t tail;
    uint32_t size;    // Size of the buffer 
}MyBuffer_ts;

// Implementation of ring buffer functions would go here, such as initialization, adding elements, removing elements, and checking if the buffer is full or empty.  

//Eg. 12345

//Prototypes for the ring buffer functions
uint8_t InitRingBuffer(MyBuffer_ts*,uint32_t*,uint32_t);
uint8_t AddToRingBuffer( MyBuffer_ts*, uint32_t);
uint8_t RemoveFromRingBuffer(MyBuffer_ts*, uint32_t*);
uint8_t IsRingBufferFull(MyBuffer_ts*);
uint8_t IsRingBufferEmpty(MyBuffer_ts*);
uint32_t GetRingBufferSize(MyBuffer_ts*);
uint32_t GetRingBufferCapacity(MyBuffer_ts*);



uint8_t InitRingBuffer(MyBuffer_ts *Mybuffer, uint32_t *buffer, uint32_t size){

    if (Mybuffer == NULL || buffer == NULL || size == 0) {
        return 0; // Return 0 for failure
    }   
    Mybuffer->buffer = buffer;
    Mybuffer->head = 0;
    Mybuffer->tail = 0;      
    Mybuffer->size = 0; // Initialize size to 0
    return 1; // Return 1 for success
}
uint8_t AddToRingBuffer(MyBuffer_ts *Mybuffer, uint32_t data){
   if (Mybuffer == NULL) {
        return 0; // Return 0 for failure
   }
   // Implementation for adding data to the ring buffer
    Mybuffer->buffer[Mybuffer->head] = data;
    Mybuffer->head = (Mybuffer->head+1 )%BUFFER_SIZE; // Update head and wrap around if necessary
    Mybuffer->size++; // Update size and wrap around if necessary
   return 1; // Return 1 for success
}

//Remove or read from the ring buffer
uint8_t RemoveFromRingBuffer(MyBuffer_ts *Mybuffer, uint32_t *data  ){
    if (Mybuffer == NULL || data == NULL) {
        return 0; // Return 0 for failure
    }
    // Implementation for removing data from the ring buffer
    *data = Mybuffer->buffer[Mybuffer->tail];
    Mybuffer->tail = (Mybuffer->tail + 1) % BUFFER_SIZE; // Update tail and wrap around if necessary
    Mybuffer->size--; // Update size and wrap around if necessary
    return 1; // Return 1 for success
}

uint8_t IsRingBufferEmpty(MyBuffer_ts *Mybuffer){
    if (Mybuffer == NULL) {
        return 1; // Return 1 for empty (or error)
    }
    return (Mybuffer->size == 0); // Return 1 if empty, 0 otherwise
}

uint8_t IsRingBufferFull(MyBuffer_ts *Mybuffer){
    if (Mybuffer == NULL) {
        return 1; // Return 1 for full (or error)
    }
    return (Mybuffer->size == BUFFER_SIZE); // Return 1 if full, 0 otherwise
}

uint32_t GetRingBufferSize(MyBuffer_ts *Mybuffer){
    if (Mybuffer == NULL) {
        return 0; // Return 0 for error
    }
    return Mybuffer->size; // Return the current size of the buffer
}   
uint32_t GetRingBufferCapacity(MyBuffer_ts *Mybuffer){
    if (Mybuffer == NULL) {
        return 0; // Return 0 for error
    }
    return BUFFER_SIZE; // Return the capacity of the buffer
}       


// Example usage of the ring buffer 
// In a real application, you would typically have a main function or other functions that utilize the ring buffer for data storage and retrieval.
// For example, you might have a producer-consumer scenario where one part of your program adds data to the buffer and another part removes data from it.   
// You would also want to handle synchronization if the buffer is accessed from multiple threads or interrupt contexts.     
// The following is a simple example of how you might use the ring buffer in a main function.
// Note: This is just a demonstration and may not be complete or fully functional without additional context and error handling.    
// Example usage of the ring buffer
// Function demostrate use of all operation of ring buffer

uint32_t RingeBufferOperations(MyBuffer_ts *Mybuffer){
    uint32_t data;
    // Add data to the ring buffer
    for (uint32_t i = 0; i < BUFFER_SIZE; i++) {
        if (AddToRingBuffer(Mybuffer, i)) {
            printf("Added %u to ring buffer\n", i);
        } else {
            printf("Failed to add %u to ring buffer\n", i);
        }
    }

    // Remove data from the ring buffer
    while (!IsRingBufferEmpty(Mybuffer)) {
        if (RemoveFromRingBuffer(Mybuffer, &data)) {
            printf("Removed %u from ring buffer\n", data);
        } else {
            printf("Failed to remove data from ring buffer\n");
        }
    }

    return 0; // Return 0 for success
}


int main() {
    // Example usage of the ring buffer
    printf("Ring buffer implementation in C17\n");

    // Initialize the ring buffer
    MyBuffer_ts myBuffer;
    if (InitRingBuffer(&myBuffer, buffer, BUFFER_SIZE)) {
        printf("Ring buffer initialized successfully\n");
    } else {
        printf("Failed to initialize ring buffer\n");
        return 1; // Exit with error
    }

    // Perform operations on the ring buffer
    RingeBufferOperations(&myBuffer);       




    return 0;
}   