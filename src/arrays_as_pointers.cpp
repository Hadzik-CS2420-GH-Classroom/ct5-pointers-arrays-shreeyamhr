#include "arrays_as_pointers.h"

#include <iostream>

// This helper function takes a POINTER, not an array
// When you pass an array to this function, it "decays" into a pointer
void printArray(const int* arr, int size) {
    std::cout << "Inside printArray (received as pointer):" << '\n';
    for (int i = 0; i < size; ++i) {
        std::cout << "  *(arr + " << i << ") = " << *(arr + i) << '\n';
    }
}
//
// ! DISCUSSION: Why const int* arr and not int* arr?
//   The const means this function promises not to modify the data
//   through the pointer. It's a read-only view. This is good practice:
//   if a function only needs to read data, mark the pointer const.
//   The compiler will catch accidental writes (e.g., *arr = 5 won't compile).
//
// ! DISCUSSION: Why does the parameter say int* but we pass an array?
//   When you write void foo(int arr[]), the compiler secretly rewrites
//   it to void foo(int* arr). There is NO difference — array parameters
//   are always pointers. This means sizeof(arr) inside the function gives
//   the size of a pointer (8 bytes on 64-bit), NOT the array size.
//   That's why we always pass 'size' as a separate parameter.

void arraysAsPointers() {
    std::cout << "\n=== Treating Arrays as Pointers ===" << '\n';

    int grades[] = {95, 87, 72, 91, 88};
    int size = 5;

    // --- 1. Array decay: passing an array to a pointer parameter ---
    std::cout << "\n--- 1. Array Decay to Pointer ---" << '\n';

    // Notice: 'grades' is an array, but printArray expects a pointer (const int*)
    // The array "decays" (automatically converts) to a pointer to its first element

    // TODO: Call printArray, passing 'grades' as the first argument and 'size' as the second
	printArray(grades, size);
    // ! DISCUSSION: What is "array decay"?
    //   When an array is used where a pointer is expected, the compiler
    //   automatically converts (decays) it to a pointer to its first element.
    //   grades  -->  &grades[0]  (happens silently)
    //   This is a one-way conversion: you lose the array's size information.
    //   That's why we must pass 'size' separately — the function has no
    //   way to know how many elements the pointer points to.
    //
    // Expected output:
    //   Inside printArray (received as pointer):
    //     *(arr + 0) = 95
    //     *(arr + 1) = 87
    //     *(arr + 2) = 72
    //     *(arr + 3) = 91
    //     *(arr + 4) = 88

    // --- 2. Using pointer arithmetic directly on an array name ---
    // ? SEE DIAGRAM: images/array_in_memory.png — shows pointer arithmetic on array elements
    std::cout << "\n--- 2. Pointer Arithmetic on Array Name ---" << '\n';

    std::cout << "grades itself points to address: " << grades << '\n';

    // TODO: Print the value of *grades (dereference the array name as if it were a pointer)
    // Expected output: "First element (*grades): 95"
	std::cout << "First element (*grades): " << *grades << '\n';
    // ! DISCUSSION: Why can we dereference an array name with *?
    //   Because 'grades' decays to a pointer in this expression.
    //   *grades is the same as *(grades + 0) which is grades[0].

    // TODO: Print the value of *(grades + 2)
    // Expected output: "Third element *(grades + 2): 72"
	std::cout << "Third element *(grades + 2): " << *(grades + 2) << '\n';
    // ! DISCUSSION: How is *(grades + 2) different from grades[2]?
    //   They are identical. grades[2] is defined as *(grades + 2).
    //   The bracket notation is just a more readable way to write
    //   pointer arithmetic. Use whichever is clearer in context.

    // TODO: Print the value of *(grades + 4)
    // Expected output: "Fifth element *(grades + 4): 88"
	std::cout << "Fifth element *(grades + 4): " << *(grades + 4) << '\n';
    // Key takeaway: An array name can be used almost everywhere a pointer can!
    // The main difference: you can't reassign an array name (grades = something_else; won't compile)
    std::cout << "\nKey difference: arrays can't be reassigned:" << '\n';
    std::cout << "  int* ptr = grades;  // OK - pointer can point to array" << '\n';
    std::cout << "  ptr = nullptr;      // OK - pointer can be reassigned" << '\n';
    std::cout << "  // grades = ptr;    // ERROR - array name can't be reassigned!" << '\n';
    //
    // ! DISCUSSION: Why can't you reassign an array name?
    //   An array name is NOT a pointer variable — it's a label for a block
    //   of memory the compiler allocated. It always refers to that same
    //   block. A pointer is a variable that holds an address and can be
    //   changed to point somewhere else.
    //   Think of it this way:
    //     - An array name is like your home address (fixed)
    //     - A pointer is like a GPS pin (you can move it anywhere)
}
