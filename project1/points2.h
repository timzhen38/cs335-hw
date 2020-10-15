// Tim Zhen 2/10/20
// The class Points2 describes a sequence of  2D points
// such as how many points the sequence has and whether they 
// are integers or doubles

#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
using namespace std;

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2 {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor. 
  // Set size to 0.
  Points2()
  {
    size_ = 0;
  }

  // Copy-constructor.
  Points2(const Points2 &rhs)
  {
    sequence_ = rhs.sequence_;
    size_ = rhs.size();
  }

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points2 copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  Points2& operator=(const Points2 &rhs)
  {
    Points2 copy = rhs;
    swap(*this, copy);
    return *this;
  }

  // Move-constructor. 
  Points2(Points2 &&rhs)
  {
    sequence_ = move(rhs.sequence_);
    size_ = move(rhs.size_);
    rhs.sequence_ = nullptr; //deallocate
    rhs.size_ = 0;
  }

  // Move-assignment.
  // Just use std::swap() for all variables.
  Points2& operator=(Points2 &&rhs)
  {
    swap(size_,rhs.size_);
    swap(sequence_,rhs.sequence_);
    return *this;
  }

  ~Points2()
  {
    delete[] sequence_; 
  }

  // End of big-five.

  // One parameter constructor.
  Points2(const std::array<Object, 2>& item) 
  {
    sequence_ = new array<Object,2>; //allocating space for single sequence
    *sequence_ = item;
    size_ = 1;
  }

  // Read a chain from standard input.
  void ReadPoints2() 
  {
    // Part of code included (without error checking).
    std::string input_line;
    std::getline(std::cin, input_line); 
    std::stringstream input_stream(input_line);
    if (input_line.empty()) return;
    // Read size of sequence (an integer).
    int size_of_sequence;
    input_stream >> size_of_sequence;
    // Allocate space for sequence.
    sequence_ = new array<Object,2>[size_of_sequence];
    size_ = size_of_sequence;
    
    Object token;
    for (int i = 0 ;input_stream >> token; ++i) {
      // Read coordinates.
      // Fill sequence_ here.
      sequence_[i][0] = token;
      input_stream >> token;
      sequence_[i][1] = token;
    }
    
  }

  size_t size() const {
    return size_;
  }

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const { 
    if (location > size_)
    {
      abort();
    }
    else
    {
      return sequence_[location];
    }
    
  }

 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2 operator+(const Points2 &c1, const Points2 &c2) 
 {
   Points2<double> sum;
   int sizeDiff = 0; //the difference in sequence sizes
   sum.size_ = c1.size();
   //when the sequences are the same size
   if (c1.size() == c2.size())
   {
     for (int i = 0; i < c1.size(); i++)
     {
       sum.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0]; 
       sum.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
     }
   }
   //when c1 is larger than c2
   else if(c1.size() > c2.size())
   {
     sizeDiff = (c1.size()-c2.size())+1; //the difference in sizes
     for (int i = 0; i < sizeDiff; i++)
     {
       sum.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0]; 
       sum.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
     }
     while (sizeDiff < c1.size())
     {
       sum.sequence_[sizeDiff][0] = c1.sequence_[sizeDiff][0];
       sum.sequence_[sizeDiff][1] = c1.sequence_[sizeDiff][1];
       sizeDiff++;
     }
   }
   //when c2 is larger than c1
   else
   {
     sum.size_ = c2.size();
     sizeDiff = (c2.size()-c1.size())+1;
     for (int i = 0; i < sizeDiff; i++)
     {
       sum.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0]; 
       sum.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
     }
     while (sizeDiff < c2.size())
     {
       sum.sequence_[sizeDiff][0] = c2.sequence_[sizeDiff][0];
       sum.sequence_[sizeDiff][1] = c2.sequence_[sizeDiff][1];
       sizeDiff++;
     }
   } 
   return sum;   
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2) 
 {
   if (some_points2.size() == 0)
    out << "()";
   for (int i = 0; i < some_points2.size(); i++)
   {
     out << "(" << some_points2.sequence_[i][0] << ", " << some_points2.sequence_[i][1] << ") ";
   }
   out << endl;
   return out;
 }
 
 private:
  // Sequence of points. 
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_
