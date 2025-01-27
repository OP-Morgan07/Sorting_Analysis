#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <sstream>
#include <stack>

using namespace std;
using namespace std::chrono;

int random_number(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
            swap(arr[i], arr[min]);
    }
}

// Function to swap two integers
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Partition function for quicksort
int partition(vector<int> &arr, int s, int e)
{
    int pivot = arr[s];
    int start = s;
    int end = e;

    while (start < end)
    {
        while (start < e && arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[end], arr[s]); // Placing pivot in the correct position
    return end;
}

// Recursive quicksort function
void recursive_quickSort(vector<int> &arr, int si, int ei)
{
    if (si < ei)
    {
        int p = partition(arr, si, ei);
        recursive_quickSort(arr, si, p - 1);
        recursive_quickSort(arr, p + 1, ei);
    }
}
void iterative_quickSort(vector<int> &arr, int si, int ei)
{
    stack<pair<int, int>> st;
    st.push({si, ei});

    while (!st.empty())
    {
        pair<int, int> range = st.top();
        st.pop();

        int low = range.first;
        int high = range.second;

        if (low < high)
        {
            int p = partition(arr, low, high);
            st.push({low, p - 1});
            st.push({p + 1, high});
        }
    }
}

// Heapify function to maintain heap property (max-heap)
void heapifyDown(vector<int> &heap, int index, int size)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
    {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(heap[index], heap[largest]);
        heapifyDown(heap, largest, size);
    }
}

// Heap sort function
void heap_Sort(vector<int> &heap)
{
    int size = heap.size();

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyDown(heap, i, size);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heapifyDown(heap, 0, i);
    }
}
int main()
{
    int min, max;
    cout << "Enter the max of the range of random numbers : ";
    cin >> max;

    cout << "Enter the min of the range of the random numbers : ";
    cin >> min;

    int no_of_files;
    cout << "Enter the number of files: ";
    cin >> no_of_files;

    for (int i = 1; i <= no_of_files; i++)
    {
        string file_name = "file" + to_string(i) + ".txt";
        ofstream file(file_name);

        int x;
        cout << "Enter the amount of random numbers: ";
        cin >> x;

        int a[x];
        for (int i = 0; i < x; i++)
        {
            a[i] = random_number(0, 100);
        }

        for (int i = 0; i < x; i++)
        {
            file << a[i];
            if (i != x - 1)
            {
                file << ", ";
            }
        }
    }

    for (int i = 1; i <= no_of_files; i++)
    {
        string file_name = "file" + to_string(i) + ".txt";
        ifstream file(file_name);

        if (!file)
        {
            cerr << "Error opening file!" << endl;
            return 1;
        }

        string line;
        getline(file, line);
        stringstream ss(line);

        vector<int> numbers;
        string temp;
        while (getline(ss, temp, ','))
        {
            numbers.push_back(stoi(temp));
        }

        vector<int> temp_arr = numbers;

        auto start = high_resolution_clock::now();
        bubble_sort(temp_arr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Bubble Sort Time For Unsorted: " << file_name << " " << duration.count() << " ns" << endl;

        start = high_resolution_clock::now();
        bubble_sort(temp_arr);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Bubble Sort Time For Sorted: " << file_name << " " << duration.count() << " ns" << endl;
        cout << endl;
        temp_arr = numbers;
        start = high_resolution_clock::now();
        insertion_sort(temp_arr);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Insertion Sort Time For Unsorted: " << file_name << " " << duration.count() << " ns" << endl;

        start = high_resolution_clock::now();
        insertion_sort(temp_arr);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Insertion Sort Time For Sorted: " << file_name << " " << duration.count() << " ns" << endl;
        cout << endl;

        temp_arr = numbers;
        start = high_resolution_clock::now();
        selection_sort(temp_arr);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Selection Sort Time For Unsorted: " << file_name << " " << duration.count() << " ns" << endl;

        start = high_resolution_clock::now();
        selection_sort(temp_arr);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Selection Sort Time For Sorted: " << file_name << " " << duration.count() << " ns" << endl;
        cout << endl;

        temp_arr = numbers;
        start = high_resolution_clock::now();
        recursive_quickSort(temp_arr, 0, temp_arr.size() - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Recursive Quick Sort On Unsorted array Time (" << file_name << "): " << duration.count() << " ns" << endl;

        // QuickSort on sorted array
        start = high_resolution_clock::now();
        recursive_quickSort(temp_arr, 0, temp_arr.size() - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Recursive Quick Sort On Sorted array Time (" << file_name << "): " << duration.count() << " ns" << endl;
        cout << endl;

        temp_arr = numbers;
        start = high_resolution_clock::now();
        iterative_quickSort(temp_arr, 0, temp_arr.size() - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Iterative Quick Sort On Unsorted array Time (" << file_name << "): " << duration.count() << " ns" << endl;

        // QuickSort on sorted array
        start = high_resolution_clock::now();
        iterative_quickSort(temp_arr, 0, temp_arr.size() - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Iterative Quick Sort On Sorted array Time (" << file_name << "): " << duration.count() << " ns" << endl;
        cout << endl;

        // Heap Sort on unsorted array
        temp_arr = numbers;
        start = high_resolution_clock::now();
        heap_Sort(temp_arr);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Heap Sort On Unsorted array Time (" << file_name << "): " << duration.count() << " ns" << endl;

        // Heap Sort on sorted array
        start = high_resolution_clock::now();
        heap_Sort(temp_arr);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Heap Sort On Sorted array Time (" << file_name << "): " << duration.count() << " ns" << endl
             << endl
             << endl;
    }

    return 0;
}
