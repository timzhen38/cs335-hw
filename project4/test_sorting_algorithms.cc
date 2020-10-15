// Homework 4
// Testing Sorting Algorithms
// Tim Zhen

#include "Sort.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

// Test function that shows how you can time a piece of code.
// Just times a simple loop.

void TestTiming() {
  cout << "Test Timing" << endl;
  const auto begin = chrono::high_resolution_clock::now();
  // Time this piece of code.
  int sum = 0;
  for (int i = 1; i < 10000; ++i) sum ++;
  // End of piece of code to time.
  const auto end = chrono::high_resolution_clock::now();    
  cout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
  cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms" << endl;

}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  // Use rand() to generate random integer
  // Add code
  vector<int> returnVec;
  srand(time(0)); //seed for generating random numbers
  for (int i = 0; i < size_of_vector; i++)
  {
    returnVec.push_back(rand());
  }
  return returnVec;

}

// Generate and returns sorted vecotr of size @size_of_vector
// If smaller_to_larger is true, returns vector sorted from small to large
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) {
  // Add code
  vector<int> returnVec;
  if (smaller_to_larger)
  {
    for(int i = 0; i < size_of_vector; i++)
    {
      returnVec.push_back(i);
    }
  }
  else if(!smaller_to_larger)
  {
    for (int j = size_of_vector; j > 0; j--)
    {
      returnVec.push_back(j);
    }
  }
  return returnVec;
}

// Verifies that a vector is sorted given a comparator
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {
  int counter = 0; //counter to check if the vector is in ascending or descending order
  for (int i = 0; i < (input.size()-1); i++)
  {
    if (less_than(input[i],input[i+1]) || (input[i] == input[i+1]))
    {
      counter++;
    }
  }
  if (counter == input.size()-1)
    return true;
  else
    return false;
}

// Computes duration given a start time and a stop time in nano seconds
long long ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time) {
  // Add code
  return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
}

// Wrapper function to test different sorting algorithms
void sortTestingWrapper(int argc, char **argv) {
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);
  if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small") {
    cout << "Invalid input type" << endl;
    return ;
  }
  if (input_size <= 0) {
    cout << "Invalid size" << endl;
    return ;
  }
  if (comparison_type != "less" && comparison_type != "greater") {
    cout << "Invalid comparison type" << endl;
    return ;
  }
  
  // This block of code to be removed for your final submission.
  //TestTiming();

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  vector<int> input_vector; //for mergesort
  vector<int> input_vector2; //for quicksort
  vector<int> input_vector3; //for heapsort
  vector<int> input_vector4; //for saving the original vector so we can reset the 3 vectors for quick sort variations
  if (input_type == "random") {
    // Generate random vector
    input_vector = GenerateRandomVector(input_size);
  } else {
    // Generate sorted vector.
    if (input_type == "sorted_small_to_large")
    {
      input_vector = GenerateSortedVector(input_size,true);
    }
    if (input_type == "sorted_large_to_small")
    {
      input_vector = GenerateSortedVector(input_size,false);
    }
  }
  input_vector2 = input_vector;
  input_vector3 = input_vector;
  input_vector4 = input_vector;
  // Call quicksort / heapsort / mergesort using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // MergeSort(input_vector, less<int>{})
  // otherwise call
  // MergeSort(input_vector, greater<int>{})
  // ...
  if (comparison_type == "less")
  {
    cout << "Heapsort" << endl << endl;
    auto begin = chrono::high_resolution_clock::now();
    MergeSort(input_vector, less<int>{});
    cout << "Runtime: <" << ComputeDuration(begin,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector,less<int>{}) << endl << endl;
    
    cout << "MergeSort" << endl << endl;
    begin = chrono::high_resolution_clock::now(); //for computing duration of heapsort
    HeapSort(input_vector2,less<int>{});
    cout << "Runtime: <" << ComputeDuration(begin,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector2,less<int>{}) << endl << endl;

    cout << "QuickSort" << endl << endl;
    begin = chrono::high_resolution_clock::now(); //for computing duration of quicksort
    QuickSort(input_vector3,less<int>{});
    cout << "Runtime: <" << ComputeDuration(begin,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector3,less<int>{}) << endl << endl;
  }

  if (comparison_type == "greater")
  {
    cout << "Heapsort" << endl << endl;
    auto begin = chrono::high_resolution_clock::now();
    MergeSort(input_vector, greater<int>{});
    cout << "Runtime: <" << ComputeDuration(begin,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector,greater<int>{}) << endl << endl;
    
    cout << "MergeSort" << endl << endl;
    begin = chrono::high_resolution_clock::now(); //for computing duration of heapsort
    HeapSort(input_vector2,greater<int>{});
    cout << "Runtime: <" << ComputeDuration(begin,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector2,greater<int>{}) << endl << endl;

    cout << "QuickSort" << endl << endl;
    begin = chrono::high_resolution_clock::now(); //for computing duration of quicksort
    QuickSort(input_vector3,greater<int>{});
    cout << "Runtime: <" << ComputeDuration(begin,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector3,greater<int>{}) << endl << endl;
  }

  // Call quicksort with median of three as pivot / middle as pivot / first as pivot using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // QuickSort(input_vector, less<int>{})
  // otherwise call
  // QuickSort(input_vector, greater<int>{})
  // ...
  cout << "Testing Quicksort Pivot Implementations" << endl << endl;

  //resetting vectors so they are unsorted again
  input_vector = input_vector4;
  input_vector2 = input_vector4;
  input_vector3 = input_vector4;

  if (comparison_type == "less")
  {
    cout << "Median of Three" << endl << endl; //median of three pivot quicksort
    auto beginQ = chrono::high_resolution_clock::now(); //quicksort's begin variable
    QuickSort(input_vector, less<int>{});
    cout << "Runtime: <" << ComputeDuration(beginQ,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector,less<int>{}) << endl << endl;
    
    cout << "Middle" << endl << endl; //middle pivot quicksort
    beginQ = chrono::high_resolution_clock::now(); 
    QuickSort2(input_vector2,less<int>{});
    cout << "Runtime: <" << ComputeDuration(beginQ,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector2,less<int>{}) << endl << endl;

    cout << "First" << endl << endl; //first pivot quicksort
    beginQ = chrono::high_resolution_clock::now();
    QuickSort3(input_vector3,less<int>{});
    cout << "Runtime: <" << ComputeDuration(beginQ,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector3,less<int>{}) << endl << endl;
  }

  if (comparison_type == "greater")
  {
    cout << "Median of Three" << endl << endl; //median of three pivot quicksort
    auto beginQ = chrono::high_resolution_clock::now(); //quicksort's begin variable
    QuickSort(input_vector, greater<int>{});
    cout << "Runtime: <" << ComputeDuration(beginQ,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector,greater<int>{}) << endl << endl;
    
    cout << "Middle" << endl << endl; //middle pivot quicksort
    beginQ = chrono::high_resolution_clock::now(); 
    QuickSort2(input_vector2,greater<int>{});
    cout << "Runtime: <" << ComputeDuration(beginQ,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector2,greater<int>{}) << endl << endl;

    cout << "First" << endl << endl; //first pivot quicksort
    beginQ = chrono::high_resolution_clock::now();
    QuickSort3(input_vector3,greater<int>{});
    cout << "Runtime: <" << ComputeDuration(beginQ,chrono::high_resolution_clock::now()) << "> ns" << endl;
    cout << "Verified: " << VerifyOrder(input_vector3,greater<int>{}) << endl << endl;
  }
}

int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
  
  sortTestingWrapper(argc, argv);

  return 0;
}
