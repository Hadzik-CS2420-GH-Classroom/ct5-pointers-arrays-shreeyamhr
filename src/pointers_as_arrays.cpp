#include "pointers_as_arrays.h"

#include <iostream>

void pointersAsArrays() {
    std::cout << "\n=== Treating Pointers as Arrays ===" << '\n';

    int data[] = {100, 200, 300, 400, 500};
    int size = 5;

    // ? SEE DIAGRAM: images/pointer_as_array.png — shows data and ptr pointing to the same memory
    // A pointer to the first element of data
    int* ptr = data;
    //
    // ! DISCUSSION: Why does int* ptr = data work without &?
    //   Same reason as before — the array name 'data' decays to a pointer
    //   to its first element. This is identical to: int* ptr = &data[0];

    // --- 1. Using bracket [] indexing on a pointer ---
    // ? SEE DIAGRAM: images/array_in_memory.png — shows how ptr[i] maps to memory
    std::cout << "\n--- 1. Bracket Indexing on a Pointer ---" << '\n';

    std::cout << "Array access:   data[0] = " << data[0] << '\n';

	std::cout << "Pointer access: ptr[0] = " << ptr[0] << '\n';
    // TODO: Print ptr[0] to show that a pointer can use [] just like an array
    // Expected output: "Pointer access: ptr[0] = 100"
	//std::cout << "Pointer access: ptr[0] = " << ptr[0] << '\n';
    // ! DISCUSSION: How can a pointer use [] like an array?
    //   The [] operator is defined for pointers: ptr[i] is just a shorthand
    //   for *(ptr + i). The compiler rewrites it to pointer arithmetic.
    //   This is why arrays and pointers are so interchangeable in C/C++.

    // TODO: Print ptr[2] to access the third element through the pointer
    // Expected output: "Pointer access: ptr[2] = 300"
	std::cout << "Pointer access: ptr[2] = " << ptr[2] << '\n';
    // TODO: Print ptr[4] to access the last element through the pointer
    // Expected output: "Pointer access: ptr[4] = 500"
	std::cout << "Pointer access: ptr[4] = " << ptr[4] << '\n';
    // ! DISCUSSION: What happens if you do ptr[5] or ptr[100]?
    //   No compile error! C++ does NOT check array bounds. ptr[5] reads
    //   whatever happens to be in memory after the array — this is
    //   undefined behavior. It might crash, return garbage, or seem to
    //   "work" (the worst outcome, because the bug hides). Always track
    //   your array size and stay within bounds.

    // --- 2. Iterating using pointer with array syntax ---
    std::cout << "\n--- 2. Looping with Pointer Using [] Syntax ---" << '\n';
    for (int i = 0; i < size; ++i) {
        std::cout << "ptr[" << i << "] = " << ptr[i] << '\n';
	}

    // TODO: Write a for loop that uses ptr[i] to print all elements
    //       Use 'size' as the loop bound
    // Expected output:
    //   ptr[0] = 100
    //   ptr[1] = 200
    //   ptr[2] = 300
    //   ptr[3] = 400
    //   ptr[4] = 500
    //
    // ! DISCUSSION: Is looping with ptr[i] the same as looping with data[i]?
    //   Yes, exactly. Since ptr points to data[0], ptr[i] and data[i]
    //   access the same memory. The compiler generates identical code.
    //   The difference is semantic: ptr is a variable (can be reassigned),
    //   while data is a fixed array name (cannot be reassigned).

    // Bonus discussion: Why does this work?
    // ptr[i] is equivalent to *(ptr + i)
    // The compiler translates bracket notation into pointer arithmetic!
    std::cout << "\nBonus - these are equivalent:" << '\n';
    std::cout << "  ptr[2]      = " << ptr[2] << '\n';
    std::cout << "  *(ptr + 2)  = " << *(ptr + 2) << '\n';

}
