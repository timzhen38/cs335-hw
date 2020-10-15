//Tim Zhen

#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H

#include <iostream>
#include <vector>
using namespace std;

class SequenceMap
{
    public:
    //zero parameter constructor
    SequenceMap() = default;

    //copy-constructor
    SequenceMap(const SequenceMap& other) = default;

    //copy assignment
    SequenceMap& operator=(const SequenceMap& other) = default;

    //move constructor
    SequenceMap(SequenceMap&& other) = default;

    //move assignment
    SequenceMap& operator=(SequenceMap&& other) = default;

    //destructor
    ~SequenceMap() = default;

    //constructs sequenceMap from 2 strings
    SequenceMap(const string &a_rec_seq, const string&an_enz_acro)
    {
        recognition_sequence_ = a_rec_seq;
        enzyme_acronyms_ = {an_enz_acro};
    }

    //string comparison between recognition_sequences
    bool operator<(const SequenceMap &rhs) const
    {
        return recognition_sequence_ < rhs.recognition_sequence_;
    }
    
    //overloaded << operator
    friend ostream &operator<<(ostream &out, const SequenceMap &other)
    {
        string seq;
        int otherSize = (other.enzyme_acronyms_).size();
        for (int i = 0; i < otherSize; i++)
        {
            seq += other.enzyme_acronyms_[i];
            seq += " ";
        }
        out << seq;
        return out;
    }

    //merges other_sequence.enzyme_acronyms_ with enzyme_acronyms_
    //keep other_sequence.enzyme_acronyms_ the same
    void Merge(const SequenceMap &other_sequence)
    {
        //the recognition sequences need to be equal to each other
        if (recognition_sequence_ != other_sequence.recognition_sequence_)
            return;
        enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[0]);
    }
    private:
        string recognition_sequence_;
        vector<string> enzyme_acronyms_;
}; 






#endif