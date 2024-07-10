#include <stdio.h>

int main() {
    signed int input_bits = 0b1100; // -4 in 4-bit signed representation
    signed char output_bits;

    // Truncate to 3 bits
    output_bits = input_bits & 0b111; // Mask with 0b111 to keep only the lower 3 bits

    // Output the result
    printf("Input bits: %d\n", input_bits);
    printf("Output bits: %d\n", output_bits);

    return 0;
}
