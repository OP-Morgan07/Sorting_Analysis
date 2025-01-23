#include <bits/stdc++.h>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int random_number(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void bubble_sort(int arr[], int n)
{
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

void insertion_sort(int arr[], int n)
{
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

void selection_sort(int arr[], int n)
{
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

int main()
{
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

        int count = numbers.size();
        int arr[count];
        copy(numbers.begin(), numbers.end(), arr);

        int temp_arr[count];
        copy(arr, arr + count, temp_arr);

        auto start = high_resolution_clock::now();
        bubble_sort(temp_arr, count);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Bubble Sort Time: " << file_name << " " << duration.count() << " ns" << endl;

        copy(arr, arr + count, temp_arr);
        start = high_resolution_clock::now();
        insertion_sort(temp_arr, count);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Insertion Sort Time: " << file_name << " " << duration.count() << " ns" << endl;

        copy(arr, arr + count, temp_arr);
        start = high_resolution_clock::now();
        selection_sort(temp_arr, count);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Selection Sort Time: " << file_name << " " << duration.count() << " ns" << endl;
        cout << endl;
    }

    return 0;
}
