#include <iostream>
#include "LongInteger.h"
#include <string>
using namespace std;
/*
-----------------------------------------------------------
empties private char array when object is created
-----------------------------------------------------------
*/
LongInteger::LongInteger()
{
      for(int i = 0; i < MAX_SIZE; i++)
      {
            integer[i] = ' '; 
      }
}

/*
-----------------------------------------------------------
empties private char array when object is deleted
-----------------------------------------------------------
*/
LongInteger::~LongInteger()
{
      for(int i = 0; i < MAX_SIZE; i++)
      {
            integer[i] = ' '; 
      }
}

/*
-----------------------------------------------------------
transfers string into the private char array of object
-----------------------------------------------------------
*/
void LongInteger::stringToArray(const string strInt)
{
   
    int str_Size = strInt.size();
    int array_Size = MAX_SIZE;
    int j = 0;
    if(strInt != " ")
    {
        for (int i = 0; i < str_Size; i++)
        {
            if(strInt[str_Size - 1 - i] != ' ')
            {
            integer[array_Size - 1 - j] = strInt[str_Size - 1 - i];
            j++;
            }
        }
    }
}
/*
-----------------------------------------------------------
displays the full number within the object
-----------------------------------------------------------
*/
void LongInteger::displayNumber() const
{
    bool number_started = false; 
    for(int i = 0; i < MAX_SIZE; i++)
        {
            if((isDigit(integer[i])))
            {
                 number_started = true;
            }

            if(number_started)
            {
                 cout << integer[i];
            } 
            
            if(i == MAX_SIZE - 1 && !number_started){
                //if array all zeros return zero as Integer number 
             cout << "\b0";
            }
        }
  cout << endl;
}
/*
-----------------------------------------------------------
returns the amount of digits are within the object
-----------------------------------------------------------
*/
int LongInteger::IntSize() const
{
    int counter = 0;
    bool number_started = false;  
  
    for(int i = 0; i < MAX_SIZE; i++)
    {
        if((isDigit(integer[i])))
        {
             number_started = true;
        }

        if(number_started)
        {
             counter++;
        } 
    }

    return counter;
}

char LongInteger::GetChar(int index) const
{
      return integer[index]; 
}

void LongInteger::SetChar(char digit, int index)
{
      integer[index] = digit; 
}

void LongInteger::operator=(const LongInteger& Integer)
{
      for(int i = MAX_SIZE - 1; i >= MAX_SIZE - Integer.IntSize(); i--)
      {
            integer[i] = Integer.GetChar(i); 
      }
}

/*
-----------------------------------------------------------
returns true or false whether a character is a digit or not
-----------------------------------------------------------
*/

bool LongInteger::isDigit(char digit) const
{
      if(digit == '0'){
        return true;
      }
      if(digit == '1'){
        return true;
      }
      if(digit == '2'){
        return true;
      }
      if(digit == '3'){
        return true;
      }
      if(digit == '4'){
        return true;
      }
      if(digit == '5'){
        return true;
      }
      if(digit == '6'){
        return true;
      }
      if(digit == '7'){
        return true;
      }
      if(digit == '8'){
        return true;
      }
      if(digit == '9'){
        return true;
      }

    return false;  
}


void LongInteger::AddCommas()
{
  int divider = 3;
  int counter = 1;
  string temp_str = "";
  bool number_started = false;  
  //convert private array back into a string
  if(IntSize() > 3)
  {

        for(int i = 0; i < MAX_SIZE; i++)
        {
              if((isDigit(integer[i])))
              {
                    number_started = true;
              }

              if(number_started)
              {
                    temp_str.push_back(integer[i]); 
              } 
        }
      //for every three numbers add comma if there is a fourth number ahead then insert "," between 3rd and 4th 
        for(int i = temp_str.size() - 1; i >= 0; i--)
        {
              if(counter % divider  == 0 && isDigit(temp_str[i-1]))
              {
                    temp_str.insert(i,",");
              }

              counter++;  
         }
  }
   
    stringToArray(temp_str); 
}

int LongInteger:: MaxSize() const
{
  return MAX_SIZE;
}


bool LongInteger:: IsEmpty() const
{
    bool is_nonzero = true;
  
    for(int i = 0; i < IntSize(); i++)
    {
        if(isDigit(integer[i]) && integer[i] != '0')
        {
            is_nonzero = false;   
        }   
    }
  return is_nonzero;
}

void LongInteger::Reset()
{
    for(int i = 0; i < MAX_SIZE; i++)
    {
        integer[i] = ' ';
    }
}