# Sorting Algorithm Performance Comparison

This project generates random numbers, stores them in files, and measures the performance of various sorting algorithms on those numbers. The sorting algorithms implemented include Bubble Sort, Insertion Sort, Selection Sort, Recursive Quick Sort, Iterative Quick Sort, and Heap Sort.

## Features
- Generates random numbers within a user-defined range.
- Stores random numbers in multiple files.
- Reads data from files and applies different sorting algorithms.
- Measures the execution time for sorting unsorted and sorted arrays.
- Provides a performance comparison for various sorting techniques.

## Sorting Algorithms Implemented
1. **Bubble Sort**
2. **Insertion Sort**
3. **Selection Sort**
4. **Recursive Quick Sort**
5. **Iterative Quick Sort**
6. **Heap Sort**

## How to Compile and Run

### Compilation:
Ensure you have a C++ compiler (e.g., g++) installed, then compile the program using the following command:

```bash
 g++ -std=c++17 sorting_algorithms.cpp -o sorting_algorithms
```

### Running the Program:

```bash
 ./sorting_algorithms
```

## Input Format
The program will prompt the user for the following inputs:
1. The maximum value in the range of random numbers.
2. The minimum value in the range of random numbers.
3. The number of files to generate.
4. The number of random numbers to store in each file.

## Output
The program outputs the time taken (in nanoseconds) for each sorting algorithm to process both unsorted and sorted data, including:

- Bubble Sort Time For Unsorted/Sorted
- Insertion Sort Time For Unsorted/Sorted
- Selection Sort Time For Unsorted/Sorted
- Recursive Quick Sort Time For Unsorted/Sorted
- Iterative Quick Sort Time For Unsorted/Sorted
- Heap Sort Time For Unsorted/Sorted

## File Handling
- The random numbers are stored in text files named `file1.txt`, `file2.txt`, etc.
- The numbers in the files are comma-separated.
- The program reads the files and processes the data for sorting.

## Example Execution
```shell
Enter the max of the range of random numbers : 100
Enter the min of the range of the random numbers : 1
Enter the number of files: 3
Enter the amount of random numbers: 10
```

## Dependencies
- Standard C++ libraries: `iostream`, `fstream`, `vector`, `cstdlib`, `ctime`, `chrono`, `sstream`, `stack`

## Notes
- The sorting algorithms work on arrays of integers.
- Timing is measured using the C++ `<chrono>` library for high precision.

## License
This project is open-source and available for educational purposes.

