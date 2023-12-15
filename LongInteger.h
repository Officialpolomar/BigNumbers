#include <iostream>
#include <string>
using namespace std;


#ifndef LONGINTEGER_H
#define LONGINTEGER_H
#define MAX_SIZE 33 


class LongInteger {

    private:
    char integer[MAX_SIZE];
    bool isDigit(char) const;


    public:
     LongInteger();
    ~LongInteger();
    void stringToArray(const string); // done 
    void operator=(const LongInteger&); // done 
    void displayNumber() const; // done 
    void SetChar(char, int); // done 
    void AddCommas(); //done
    void Reset(); //done 
    char GetChar(int) const; // done
    bool IsEmpty() const; // done 
    int IntSize() const; //done
    int MaxSize() const; //done 
};


#endif