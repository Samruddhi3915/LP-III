#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int partition(vector<int> &input, int low, int high)
{
    int left = low + 1;
    int right = high;
    int pivot = input[low];
    while (left <= right)
    {
        while (left <= right && input[left] < pivot)
        {
            left++;
        }
        while (left <= right && input[right] >= pivot)
        {
            right--;
        }
        if (left <= right)
        {
            swap(input[left], input[right]);
        }
    }
    swap(input[low], input[right]);
    return right;
}

void quickSort(int low, int high, vector<int> &input)
{
    if (low < high)
    {
        int pivot = partition(input, low, high);
        quickSort(low, pivot, input);
        quickSort(pivot + 1, high, input);
    }
}

int randomPartition(vector<int> &input, int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);
    swap(input[random], input[low]);
    return partition(input, low, high);
}

void randomQS(int low, int high, vector<int> &input)
{
    if (low < high)
    {
        int pivot = randomPartition(input, low, high);
        randomQS(low, pivot, input);
        randomQS(pivot + 1, high, input);
    }
}

void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main()
{
    char v = 'Y';
    while (v == 'Y' || v == 'y')
    {
        cout << "1. Deterministic QS\n";
        cout << "2. Randomized QS\n";
        cout << "Enter a choice:\n";
        int ch;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int n;
            cin >> n;
            vector<int> input(n);
            for (int i = 0; i < n; i++)
            {
                cin >> input[i];
            }

            // Space complexity estimation (a rough estimate)
            size_t space_used = sizeof(int) * (n + 1) + sizeof(char) + sizeof(v); // Variables and vectors
            space_used += sizeof(int) * 2 * n;                                   // Function parameters
            space_used += sizeof(int) * 3;                                       // Loop variables

            clock_t start = clock();
            quickSort(0, n - 1, input);
            clock_t end = clock();

            double duration = double(end - start) / CLOCKS_PER_SEC;
            cout << "Sorted vector: ";
            printVector(input);
            cout << "Time taken: " << duration << " seconds\n";
            cout << "Space used: " << space_used << " bytes\n";
            break;
        }
        case 2:
        {
            int n;
            cin >> n;
            vector<int> input(n);
            for (int i = 0; i < n; i++)
            {
                cin >> input[i];
            }

            // Space complexity estimation (a rough estimate)
            size_t space_used = sizeof(int) * (n + 1) + sizeof(char) + sizeof(v); // Variables and vectors
            space_used += sizeof(int) * 2 * n;                                   // Function parameters
            space_used += sizeof(int) * 3;                                       // Loop variables

            clock_t start = clock();
            randomQS(0, n - 1, input);
            clock_t end = clock();

            double duration = double(end - start) / CLOCKS_PER_SEC;
            cout << "Sorted vector: ";
            printVector(input);
            cout << "Time taken: " << duration << " seconds\n";
            cout << "Space used: " << space_used << " bytes\n";
            break;
        }
        }

        cout << "Do you want to continue?";
        cin >> v;
    }

    return 0;
}
