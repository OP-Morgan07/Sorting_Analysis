# Sorting_Analysis
# Sorting Algorithm Performance Analysis

## Overview
This project generates random numbers, writes them to files, reads them back, and analyzes the performance of three sorting algorithms:

1. **Bubble Sort**
2. **Insertion Sort**
3. **Selection Sort**

## Features
- User inputs the number of files to generate.
- Each file contains a user-specified number of random integers.
- Sorting time for each algorithm is measured in nanoseconds.
- Results are displayed in the console.

## Files
- `sorting_algorithms.cpp`: The main C++ program containing the sorting algorithms and execution logic.
- `file1.txt`, `file2.txt`, etc.: Generated data files containing random numbers.

## Requirements
- A C++ compiler (e.g., g++, clang++)
- Standard C++ libraries

## Compilation
To compile the code, use the following command:
```sh
 g++ sorting_algorithms.cpp -o sorting_analysis
```

## Execution
Run the compiled executable:
```sh
./sorting_analysis
```

Follow the prompts to enter the number of files and the number of random numbers to be generated.

## Sorting Algorithms Explanation
1. **Bubble Sort**: Compares adjacent elements and swaps them if they are in the wrong order. Repeats until sorted.
2. **Insertion Sort**: Builds the sorted array one element at a time by shifting elements to their correct position.
3. **Selection Sort**: Finds the minimum element and places it in the sorted position, repeating for each subsequent element.

## Sample Output
```
Enter the number of files: 2
Enter the amount of random numbers: 5
Bubble Sort Time: file1.txt 5000 ns
Insertion Sort Time: file1.txt 3000 ns
Selection Sort Time: file1.txt 4000 ns
```

## Improvements
- Add support for more efficient sorting algorithms such as Merge Sort and Quick Sort.
- Write performance results to a log file.
- Provide visualization of sorting times.

## License
This project is licensed under the MIT License.

