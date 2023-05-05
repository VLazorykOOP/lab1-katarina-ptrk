#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void task1(int A[], int B[], int C[], int N = 10) {
  /** 8 variant
   * Given array A, B with size N
   * Build array C where C[i] = A[i] * B[i]
   */
  for (int i = 0; i < N; i++) {
    C[i] = A[i] * B[i];
  }
}

void task1(vector<int> &A, vector<int> &B, vector<int> &C, int n = 10) {
  /** 8 variant
   * Given array A, B with size N
   * Build array C where C[i] = A[i] * B[i]
   */
  for (int i = 0; i < A.size(); i++) {
    C.push_back(A[i] * B[i]);
  }
}

int task2(int A[], int N = 10) {
  /** 8 variant
   * Given array A with size N
   * Find max element value among even by value elements
   * located before first odd number
   */
  int *maxElement = nullptr; // creating pointer to nullptr
  for (int i = 0; i < N; i++) {
    if (A[i] % 2 == 1) { // if odd
      break;             // then stop searching
    }
    if (A[i] % 2 == 0) { // if even
      if (maxElement == nullptr || A[i] > *maxElement) {
        maxElement = &A[i]; // update pointer to maximum even element
      }
    }
  }
  if (maxElement) {
    cout << "Maximum even element before first odd: " << *maxElement << endl;
    return *maxElement;
  } else {
    cout << "No even elements before first odd" << endl;
    return -1;
  }
}

int task2(vector<int> &A) {
  /** 8 variant
   * Given array A with size N
   * Find max element value among even by value elements
   * located before first odd number
   */
  int *maxElement = nullptr; // creating pointer to nullptr
  for (int i = 0; i < A.size(); i++) {
    if (A[i] % 2 == 1) { // if odd
      break;             // then stop searching
    }
    if (A[i] % 2 == 0) { // if even
      if (maxElement == nullptr || A[i] > *maxElement) {
        maxElement = &A[i]; // update pointer to maximum even element
      }
    }
  }
  if (maxElement) {
    cout << "Maximum even element before first odd: " << *maxElement << endl;
    return *maxElement;
  } else {
    cout << "No even elements before first odd" << endl;
    return -1;
  }
}

int task3(vector<int> &A, vector<int> &B) {
  /** 8 variant
   * Given array A with size N <= 200
   * Build array B with size N with
   * elements A[i] when roots of
   * equality x^2+3*A[i]*x+5 = 0 is valid and positive
   * Print array B by 5 elements in row
   */
  for (int i = 0; i < A.size(); i++) {
    double D = 3 * A[i] * 3 * A[i] - 4 * 5;     // compute the discriminant
    if (D >= 0) {                               // if both roots are valid
      double root1 = (-3 * A[i] + sqrt(D)) / 2; // compute the first root
      double root2 = (-3 * A[i] - sqrt(D)) / 2; // compute the second root
      if (root1 > 0 && root2 > 0) {             // if both roots are positive
        B.push_back(A[i]);                      // add A[i] to array B
      }
    }
  }
  cout << "B array:" << endl;
  int printed = 0;
  for (int i = 0; i < B.size(); i++) {
    cout << B[i] << " ";
    printed++;
    if (printed == 5) { // if printed 5 elements in row
      printed = 0;      // start counter again
      cout << endl;     // print new line
    }
  }
  return B.size();
}

int task3(int A[], int B[], int N = 10) {
  /** 8 variant
   * Given array A with size N <= 200
   * Build array B with size N with
   * elements A[i] when roots of
   * equality x^2+3*A[i]*x+5 = 0 is valid and positive
   * Print array B by 5 elements in row
   */
  if (N < 0 && N > 200) {
    cout << "N must be <= 200. Aborting..." << endl;
    return 0;
  }
  int sizeB = 0;
  for (int i = 0; i < N; i++) {
    double D = 3 * A[i] * 3 * A[i] - 4 * 5;     // compute the discriminant
    if (D >= 0) {                               // if both roots are valid
      double root1 = (-3 * A[i] + sqrt(D)) / 2; // compute the first root
      double root2 = (-3 * A[i] - sqrt(D)) / 2; // compute the second root
      if (root1 > 0 && root2 > 0) {             // if both roots are positive
        B[sizeB++] = A[i];                      // add A[i] to array B
      }
    }
  }
  cout << "B array:" << endl;
  int printed = 0;
  for (int i = 0; i < sizeB; i++) {
    cout << B[i] << " ";
    printed++;
    if (printed == 5) { // if printed 5 elements in row
      printed = 0;      // start counter again
      cout << endl;     // print new line
    }
  }
  return sizeB;
}

/*
 * @param int sizeMax - maximum size of array
 * Asks for user to input size of array
 * and returns proper size from 0 to sizeMax, inputted by user
 */
int ConsoleInputSizeArray(const int sizeMax) {
  int size = 0;
  do {
    cout << "Input size Array (0 < 1 < " << sizeMax << "): ";
    cin >> size;
  } while (size <= 0 || size >= sizeMax);
  return size;
}

/*
 *   Input array A[] with size "size" from keyboard
 */
void ConsoleInputArray(int size, int A[]) {
  for (int i = 0; i < size; i++) {
    cout << ""
            "Array ["
         << i << "]: ";
    cin >> A[i];
  }
}

/*
 * @param size - size of array
 * @param int A[] - array
 * filling of array using random numbers from -10 to 10
 */
void RndInputArray(int size, int A[]) {
  int r1 = 0, r2 = 0;
  for (int i = 0; i < size; i++) {
    r1 = rand();
    A[i] = (r1 % 20) - 10;

    cout << A[i] << " ";
  }
  cout << endl;
}

/*
 * Writes array arr[] with size n to text file fileName
 */
void WriteArrayTextFile(int n, int arr[], const char *fileName) {
  ofstream fout(fileName);
  if (fout.fail())
    return;
  for (int i = 0; i < n; i++)
    fout << arr[i] << " ";
  fout.close();
}

/*
 * Writes vector array arr[] with size n to text file fileName
 */
void WriteArrayTextFile(vector<int> &arr, const char *fileName) {
  ofstream fout(fileName);
  if (fout.fail())
    return;
  for (int i = 0; i < arr.size(); i++)
    fout << arr[i] << " ";
  fout.close();
}

/*
 *  Reads array from text file with size n
 *  return size of array
 */
int ReadArrayTextFile(int n, int arr[], const char *fileName) {
  int size;
  ifstream fin(fileName);
  if (fin.fail())
    return 0;
  fin >> size;
  if (size <= 0)
    return 0;
  if (size > n)
    size = n;
  for (int i = 0; i < n; i++)
    fin >> arr[i];
  fin.close();
  return size;
}

// returns size of array inside file
int getArraySizeTextFile(const char *fileName) {
  int size;
  ifstream fin(fileName);
  if (fin.fail())
    return 0;
  fin >> size;
  if (size <= 0)
    return 0;
  fin.close();
  return size;
}

// write array *arr with size n inside binary file fileName
void WriteArrayBinFile(int n, int *arr, const char *fileName) {
  // ios_base
  ofstream bfout(fileName, ios_base::binary);
  if (bfout.fail())
    return;
  bfout.write((const char *)&n, sizeof(int));
  std::streamsize cn = static_cast<std::streamsize>(n) * sizeof(double);
  bfout.write((const char *)arr, cn);
  bfout.close();
}

/** reads array from bin file with size n from fileName
 * writes array inside *arr
 */
int ReadArrayBinFile(int n, int *arr, const char *fileName) {
  int size = 0;
  ifstream bfin(fileName, ios_base::binary);
  if (bfin.fail())
    return 0;
  bfin.read((char *)&size, sizeof(int));
  if (size <= 0)
    return 0;
  if (size > n)
    size = n;
  bfin.read((char *)arr, static_cast<std::streamsize>(size) * sizeof(double));
  bfin.close();
  return size;
}

// input vector A with size size from keyboard
void ConsoleInputVector(int size, vector<int> &A) {
  double d;
  for (int i = 0; i < size; i++) {
    cout << " Array[ " << i << "] ";
    cin >> d;
    A.push_back(d);
  }
  return;
}

int main() {
  srand(time(NULL));
  cout << "1. Task 1" << endl;
  cout << "2. Task 2" << endl;
  cout << "3. Task 3" << endl;
  int task = 0;
  while (task == 0 || task > 3 || task < 1) { // select task from 1-3
    cin >> task;
  }
  cout << "1. Input from console, write to text file" << endl;
  cout << "2. Input size from console, create random arrays, write in binary "
          "file"
       << endl;
  cout << "3. Input from text file inside dynamic arrays, write inside text "
          "file and print"
       << endl;
  cout << "4. Input from console inside vector" << endl;
  int choose = 0;
  while (choose == 0 || choose > 4) { // choose how to execute selected task
    cin >> choose;
    switch (choose) {
    case 1: { // input from console, write to text file
      cout << "Input size <= 200: " << endl;
      int size = ConsoleInputSizeArray(200); // writing size
      int A[200], B[200], C[200];
      cout << "Input array A." << endl;
      ConsoleInputArray(size, A); // input array
      switch (task) {
      case 1: {
        cout << "Input array B." << endl;
        ConsoleInputArray(size, B); // input array B for task 1
        task1(A, B, C, size);       // execute task 1
        WriteArrayTextFile(
            size, C,
            "/home/ob3r0n/Desktop/lab1"); // write result C array inside file
                                          // with specified path
        break;
      }
      case 2: {
        int result = task2(A, size); // execute task 2
        WriteArrayTextFile(
            1, &result,
            "/home/ob3r0n/Desktop/lab1"); // write result inside file
        break;
      }
      case 3: {
        int sizeB = task3(A, B, size); // execute task 3
        WriteArrayTextFile(sizeB, B,
                           "/home/ob3r0n/Desktop/lab1"); // write result
        break;
      }
      }

      break;
    }
    case 2: {
      // input size from console, create random, write to binary
      cout << "Input size <= 200: " << endl;
      int size = ConsoleInputSizeArray(200);
      int A[200], B[200], C[200];
      RndInputArray(size, A); // randomly fill array
      switch (task) {
      case 1: {
        RndInputArray(size, B); // randomly fill array
        task1(A, B, C, size);
        WriteArrayBinFile(
            size, C,
            "/home/ob3r0n/Desktop/lab1"); // write result to binary file
        break;
      }
      case 2: {
        int result = task2(A, size);
        WriteArrayBinFile(1, &result, "/home/ob3r0n/Desktop/lab1");
        break;
      }
      case 3: {
        int sizeB = task3(A, B, size);
        WriteArrayBinFile(sizeB, B, "/home/ob3r0n/Desktop/lab1");
        break;
      }
      }
      break;
    }
    case 3: {
      // input from text file inside dynamic, write inside text file and print
      int *A, *B, *C; // create dynamic arrays
      int size = getArraySizeTextFile(
          "/home/ob3r0n/Desktop/lab1inputA"); // get size from first file
      A = new int[size];                      // initialize array with size
      ReadArrayTextFile(
          size, A,
          "/home/ob3r0n/Desktop/lab1inputA"); // read and write to array
      switch (task) {
      case 1: {
        B = new int[size];
        ReadArrayTextFile(size, B, "/home/ob3r0n/Desktop/lab1inputB");
        C = new int[size];
        task1(A, B, C, size);
        WriteArrayTextFile(size, C, "/home/ob3r0n/Desktop/lab1");
        for (int i = 0; i < size; i++) {
          cout << C[i] << " ";
        }
        cout << endl;
        delete[] A; // free space, initialized by new
        delete[] B;
        delete[] C;
        break;
      }
      case 2: {
        int result = task2(A, size);
        WriteArrayTextFile(1, &result, "/home/ob3r0n/Desktop/lab1");
        cout << result << endl;
        delete[] A;
        break;
      }
      case 3: {
        int sizeB = task3(A, B, size);
        WriteArrayTextFile(sizeB, B, "/home/ob3r0n/Desktop/lab1");
        for (int i = 0; i < sizeB; i++) {
          cout << B[i] << " ";
        }
        cout << endl;
        delete[] A;
        break;
      }
      default: {
        delete[] A;
        break;
      }
      }
      break;
    }
    case 4: {
      // input from console inside vector, output in console
      std::vector<int> A, B, C;              // create vectors
      int size = ConsoleInputSizeArray(200); // write size
      ConsoleInputVector(size, A);           // write vector from console
      switch (task) {
      case 1: {
        cout << "Input array B." << endl;
        ConsoleInputVector(size, B);
        task1(A, B, C);                      // execute task 1
        for (int i = 0; i < B.size(); i++) { // B.size() returns size of array B
          cout << B[i] << " ";               // print B array
        }
        cout << endl;
        break;
      }
      case 2: {
        int result = task2(A);
        cout << "Result: " << result << endl;
        break;
      }
      case 3: {
        task3(A, B);
        for (int i = 0; i < B.size(); i++) {
          cout << B[i] << " ";
        }
        cout << endl;
        break;
      }
      }
      break;
    }
    }
  }
  return 1;
}
