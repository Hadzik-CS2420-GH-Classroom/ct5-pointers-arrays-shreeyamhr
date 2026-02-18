#include "pointers_and_arrays.h"

#include <iostream>

void pointersAndArrays() {
    std::cout << "=== Pointers and Arrays ===" << '\n';

    // --- 1. Declaring pointers and arrays ---
    // ? SEE DIAGRAM: images/array_in_memory.png — shows how the array is laid out in memory
    std::cout << "\n--- 1. Declaring Pointers and Arrays ---" << '\n';

    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;

    // TODO: Declare a pointer called 'ptr' that points to the first element of 'numbers'
	int* ptr = &numbers[0];  //simply int* ptr = numbers; also works because the array name decays to a pointer to its first element
    // ! DISCUSSION: Why int* ptr and not int *ptr?
    //   Both compile — the * can go next to the type or the variable name.
    //   We prefer int* ptr because it reads as "ptr is of type int-pointer."
    //   The alternative (int *ptr) is C-style and can be misleading:
    //       int* a, b;   // a is a pointer, b is just an int! (surprising)
    //   Best practice: declare one variable per line when using pointers.
    //
    // ! DISCUSSION: Why &numbers[0] and not just numbers[0]?
    //   numbers[0] gives you the VALUE stored at index 0 (which is 10).
    //   &numbers[0] gives you the ADDRESS of index 0 (where 10 lives in memory).
    //   A pointer stores an address, so we need & to get the address.
    //   Also valid: int* ptr = numbers;  (the array name decays to a pointer
    //   to its first element — we'll see this in arrays_as_pointers.cpp)

    std::cout << "Array first element: " << numbers[0] << '\n';
    // TODO: Print the value that 'ptr' points to using the dereference operator (*)
    // Expected output: "Pointer points to: 10"
	std::cout << "Pointer points to: " << *ptr << '\n';
    // ! DISCUSSION: Why *ptr and not ptr?
    //   ptr holds an address (e.g., 0x7ffd1234).
    //   *ptr "dereferences" the pointer — it follows the address and gives
    //   you the value stored there. Think of * as "go to that address."
    //   Printing ptr would print the address. Printing *ptr prints 10.

    // --- 2. Taking the address of array elements ---
    std::cout << "\n--- 2. Address of Array Elements ---" << '\n';


    std::cout << "Address of numbers array: " << numbers << '\n';
    //
    // ! DISCUSSION: Why does printing 'numbers' show an address?
    //   When you use an array name in most expressions, it "decays" to a
    //   pointer to its first element. So cout << numbers prints the address
    //   of numbers[0]. This is the same as cout << &numbers[0].

    // TODO: Print the address of numbers[0] using the address-of operator (&)
    // Expected output: "Address of numbers[0]: <some address>"
	std::cout << "Address of numbers[0]: " << &numbers[0] << '\n';

    // TODO: Print the address of numbers[1] using the address-of operator (&)
    // Expected output: "Address of numbers[1]: <some address>"
	std::cout << "Address of numbers[1]: " << &numbers[1] << '\n';
    // TODO: Print the difference in bytes between &numbers[1] and &numbers[0]
    //       Hint: cast the addresses to (char*) before subtracting to get bytes
    // Expected output: "Bytes between elements: 4"
	std::cout << "Bytes between elements: " << (char*)&numbers[1] - (char*)&numbers[0] << '\n';

    // ! DISCUSSION: Why cast to (char*) before subtracting?
    //   Pointer arithmetic is scaled by the type size. If we subtract two
    //   int* pointers, we get the difference in "number of ints" (which is 1).
    //   By casting to char* first, each unit is 1 byte, so the subtraction
    //   gives us the actual byte distance (4 bytes for a 32-bit int).
    //
    // ! DISCUSSION: Why is it 4 bytes apart?
    //   An int is typically 4 bytes on most modern systems. Each element in
    //   the array is stored contiguously, so &numbers[1] is exactly
    //   sizeof(int) = 4 bytes after &numbers[0].

    // --- 3. Dereferencing pointers ---
    // ? SEE DIAGRAM: images/pointer_address_value.png — shows *, &, addresses, and values
    std::cout << "\n--- 3. Dereferencing Pointers ---" << '\n';

    int value = 42;

    // TODO: Declare a pointer called 'pValue' that points to 'value'
	int* pValue = &value;

    // ! DISCUSSION: Why do we need & here but not with arrays?
    //   'value' is a plain int, not an array. It doesn't decay to a pointer.
    //   We must explicitly take its address with &value.
    //   With arrays, the name itself decays to a pointer (a convenience).

    // TODO: Print the value of 'value' by dereferencing 'pValue'
    // Expected output: "Dereferenced value: 42"
	std::cout << "Dereferenced value: " << *pValue << '\n';

    // TODO: Change 'value' through the pointer by assigning 99 to *pValue
	*pValue = 99;
    // ! DISCUSSION: How does *pValue = 99 change 'value'?
    //   pValue holds the address of 'value'. Writing to *pValue means
    //   "go to that address and store 99 there." Since that address IS
    //   where 'value' lives, 'value' itself changes. The pointer didn't
    //   copy the data — it's an alias to the same memory location.

    std::cout << "After modification through pointer:" << '\n';
    // TODO: Print 'value' directly to show it changed
    // Expected output: "value is now: 99"
	printf("value is now: %d\n", value);
    // --- 4. Pointer arithmetic ---
    // ? SEE DIAGRAM: images/array_in_memory.png — shows pointer arithmetic on the array
    std::cout << "\n--- 4. Pointer Arithmetic ---" << '\n';

	int* start = numbers;//decays to pointer to first element
    //
    // ! DISCUSSION: Why can we write int* start = numbers without &?
    //   The array name 'numbers' decays to a pointer to its first element.
    //   So this is equivalent to: int* start = &numbers[0];

    std::cout << "start points to: " << *start << '\n';
	std::cout << "start + 0 points to: " << *(start + 0) << '\n';

    // TODO: Use pointer arithmetic (start + 1) to print the second element
    // Expected output: "start + 1 points to: 20"
    
    // ! DISCUSSION: Why does start + 1 skip 4 bytes, not 1 byte?
    //   Pointer arithmetic is type-aware. start is an int*, so +1 advances
    //   by sizeof(int) = 4 bytes, landing exactly on the next int in the array.
    std::cout << "start + 1 points to: " << *(start + 1) << '\n';

    // TODO: Use pointer arithmetic (start + 3) to print the fourth element
    // Expected output: "start + 3 points to: 40"
	std::cout << "start + 3 points to: " << *(start + 3) << '\n';
    // TODO: Create a pointer 'end' that points to the last element using pointer arithmetic
    //
    // ! DISCUSSION: Why size - 1 and not just size?
    //   start + size points ONE PAST the last element (used as a sentinel).
    //   start + size - 1 points to the actual last element (index 4).
    //   Off-by-one errors with pointers are a common source of bugs!
	int* end = start + size - 1;
	std::cout << "start + size - 1 points to: " << *end << '\n';

    // TODO: Print all elements by incrementing a pointer in a for loop
    //       Hint: use a pointer that starts at 'numbers' and increments with ++
    // Expected output: "Walking with pointer: 10 20 30 40 50"
    //
    // ! DISCUSSION: Why p < numbers + size and not p <= numbers + size?
    //   numbers + size points to one-past-the-end — reading from that
    //   address would be undefined behavior (accessing memory you don't own).
    //   Using < keeps us safely within the array bounds.
    //   This is the same pattern as iterators: begin() to end(), where
    //   end() is one past the last element.
	std::cout << "Walking with pointer: ";
    for (int* p = numbers; p < numbers + size; ++p) {
        std::cout << *p << " ";
	}
    // ! DISCUSSION: Does ++p skip the first element?
    //   No! In a for loop, the update step (++p) runs AFTER each iteration,
    //   not before the first one. The order is: init → check → body → update.
    //   So p starts at numbers[0], prints it, THEN advances to numbers[1].
    //
    // ? SEE DIAGRAM: images/pre_vs_post_increment.png — shows ++p vs p++ step by step
    // ! DISCUSSION: Why ++p and not p++?
    //   Both increment p by one element, and both produce the same loop output.
    //   The difference:
    //     ++p  (pre-increment)  — increments p, then returns the NEW value
    //     p++  (post-increment) — saves a copy of p, increments p, returns the OLD copy
    //   In this for loop it doesn't matter since we discard the return value.
    //   But ++p is preferred in C++ because p++ creates an unnecessary
    //   temporary copy. For plain pointers the compiler optimizes it away,
    //   but ++p is the standard C++ style and a good habit to build early.
    //
    // ! DISCUSSION: In modern C++, you'd normally use a range-based for loop:
    //     for (int num : numbers) { std::cout << num << " "; }
    //   This is cleaner, safer, and less error-prone — no pointer,
    //   no bounds to get wrong. But understanding the pointer version
    //   above is essential — it's what the range-based for does under the hood!

    std::cout << "Walking with pointer: ";

    // your loop here

    std::cout << '\n';
}
