#include <iostream>
#include "LongInteger.h"
#include "LongInteger.cpp"

#include <string>
using namespace std;

//prototypes
void isNumberValid(string&, int, int); // done
void isIntegerValid(string&, const int); // done
bool isOnlyDigits(string); //done 
void EmptyArray(string[], int);//done 
void MakeSpaces(int); //done 
int stringToIntMain(string); //done 
bool spacesCheck(string); //done 
bool isdigit(char); //done 
bool leadWithZero(string);
string intToString(int); //done 
string arrayToString(LongInteger, const int); //done 
int SumAlignment(LongInteger[], LongInteger&);
int SmallestInt(const LongInteger, const LongInteger); //done 
LongInteger add(const LongInteger, const LongInteger, const int); //done 
LongInteger multiply(const LongInteger, const LongInteger, LongInteger[12], const int); //done 

int main()
{
    const int MAX_NUMBERS = 13;
    const int MIN_NUMBERS = 2;
    const int MAX_DIGITS = 12;
    const int ARRAY_SIZE = 33;

    LongInteger integer_List[MAX_NUMBERS];
    LongInteger interim_products[12];
    LongInteger sum_integer;
    LongInteger product_integer; 
    LongInteger value_holder;
    string temp_num_of_integers;
    string will_continue_answer;
    string integer_input = "";
    string ambiguous_input;
    int num_of_integers = 0;
    int smallest_int_size;
    int horizonal_line_size;
    bool will_continue = true;
    
    //int integer_size;

    while(will_continue)
    {
        cout << "\nHow many integers would you like to add and multiply? ";
        getline(cin, temp_num_of_integers);
        isNumberValid(temp_num_of_integers, MIN_NUMBERS, MAX_NUMBERS);
        num_of_integers = stringToIntMain(temp_num_of_integers);
 
        for (int i = 0; i < num_of_integers; i++)
        {
            cout << "\nInteger #" << i+1 << " --> ";
            getline(cin,integer_input);
            isIntegerValid(integer_input, MAX_DIGITS);
            //check for valid input of Integer
            integer_List[i].stringToArray(integer_input); //input into LongInteger array
        }
  
        //call multiplication function 
        product_integer = multiply(integer_List[0], integer_List[num_of_integers - 1], interim_products, ARRAY_SIZE);
        
        //get sum of of all integers  
        for (int i = 1; i < num_of_integers; i++)
        {
            if (i == 1)
            {
                value_holder = add(integer_List[0], integer_List[1], ARRAY_SIZE);
                sum_integer = value_holder; 
                continue;
            }
        
            sum_integer = add(value_holder, integer_List[i], ARRAY_SIZE);
            value_holder = sum_integer; 
        }
        
        //get smallest int for multiplication
        smallest_int_size = SmallestInt(integer_List[0], integer_List[num_of_integers - 1]);
        //get size of horizonal line for formatting
        sum_integer.AddCommas();
        product_integer.AddCommas();
        horizonal_line_size = sum_integer.IntSize() + 3;
        
        cout << "\nThe sum of:\n\n"; 
        //display all integers and final product
        for (int i = 0; i < num_of_integers; i++)
        { 
            if (i != num_of_integers - 1)
            {
                
                integer_List[i].AddCommas();
                MakeSpaces(horizonal_line_size - integer_List[i].IntSize());
                integer_List[i].displayNumber();
            }
            else 
            {
                 cout << "+) ";
                 integer_List[i].AddCommas();
                 MakeSpaces((horizonal_line_size - 3) - integer_List[i].IntSize());
                 integer_List[i].displayNumber();
              
                 for (int i = 0; i < horizonal_line_size; i++)
                   {
                       cout << "-";
                   }
              
                 cout << endl;
                 MakeSpaces(horizonal_line_size - sum_integer.IntSize());
                 sum_integer.displayNumber();
            }
        }
        //horizonal line size is now based on length of product_integer
        horizonal_line_size = product_integer.IntSize() + 3;
        cout << "\nThe product of: \n" << endl;
        //add commas to numbers to will be used if nessesary  
        // make the nessesary spaces so everything lines up
        if(integer_List[0].IntSize() >= integer_List[num_of_integers - 1].IntSize())
        {
            MakeSpaces(horizonal_line_size - integer_List[0].IntSize());
            integer_List[0].displayNumber();
            cout << "*)";
          
            MakeSpaces((horizonal_line_size - 2) - integer_List[num_of_integers - 1].IntSize());
            integer_List[num_of_integers - 1].displayNumber();
        }
        else
        {
            MakeSpaces(horizonal_line_size - integer_List[num_of_integers - 1].IntSize());
            integer_List[num_of_integers - 1].displayNumber();
            cout << "*)";
    
            MakeSpaces((horizonal_line_size - 2) - integer_List[0].IntSize());
            integer_List[0].displayNumber(); 
        }
        
        
        for(int i = 0; i < horizonal_line_size; i++)
        {
            cout << "-";
        }
        cout << endl;
        //print out intermediate multiplication steps
        for (int i = 0; i < smallest_int_size; i++)
        {
            if (i != smallest_int_size - 1)
            {
                interim_products[i].AddCommas();
                MakeSpaces(horizonal_line_size - interim_products[i].IntSize());
                interim_products[i].displayNumber();    
            }
            else 
            {
                cout << "+)";
                interim_products[i].AddCommas();
                MakeSpaces((horizonal_line_size - 2) - interim_products[i].IntSize());
                interim_products[i].displayNumber(); 
                for(int i = 0; i < horizonal_line_size; i++)
                {
                    cout << "-";
                }
                cout << endl;
            } 
        }
        
          
        //product_integer.AddCommas();
        MakeSpaces(horizonal_line_size - product_integer.IntSize());
        product_integer.displayNumber();
    
        cout << "\nPress any key to continue.....";
        cin.get();
        
        /*
        getline(cin, will_continue_answer);
    
        while (will_continue_answer != "n" && 
               will_continue_answer != "N" && 
               will_continue_answer!= "y" && 
               will_continue_answer != "Y") 
          {
              cout << "Input enter is neither a yes or a no. Please enter yes or no if you want to continue.";
              cin >> will_continue_answer;
              cin.ignore();
          }
      
          if (will_continue_answer == "n" || will_continue_answer == "N")
          {
              will_continue = false;
          }
      
        //reset all longinteger variables
        for (int i = 0; i < MAX_NUMBERS; i++)
        {
            if ( i < MAX_DIGITS)
            {
                integer_List[i].Reset();
                interim_products[i].Reset();  
            }
            else 
            {
                integer_List[i].Reset(); 
            }  
        }
        sum_integer.Reset();
        product_integer.Reset();
        value_holder.Reset();
        */
      }
  
      cout << "\nThe program has ended. Good day!";
}

/*
-----------------------------------------------------------
 Validates the input for the number of integers the program
 will allow 
-----------------------------------------------------------
*/
void isNumberValid(string& size, int lowerBound, int upperBound)
{
    while ((stringToIntMain(size) < lowerBound || stringToIntMain(size) > upperBound) || (!spacesCheck(size)) || size.find('.') != -1 || size.length() > 12 )
  {
    if (size.find('.') != -1)
    {

        cout << "\nInput cannot be a decimal, try again.\n--> ";
        getline(cin, size);
        continue;
    }

    if (!spacesCheck(size))
    {
        cout << "\nInput cannot have a space. Try again.\n--> ";
        getline(cin, size);
        continue;
    }

    if (stringToIntMain(size) < lowerBound || stringToIntMain(size) > upperBound)
    {
        cout << "\nThe input was not a number between " << lowerBound << " and " << upperBound << " try again.\n--> ";
        getline(cin, size);
        continue;
    }
  }
}

/*
-----------------------------------------------------------
 converts the string parameter into its integer equivalent
-----------------------------------------------------------
*/
int stringToIntMain(string playerNum)
{

   int num = 0;
   int l = playerNum.length();

   for (int i = 0; i < l; i++)
   {

    num = num * 10 + (int(playerNum[i]) - 48 ); 
   }

  return num;

}

/*
-----------------------------------------------------------
 A component of integer input checking by returning true or false
 if there are spaces within input
-----------------------------------------------------------
*/
bool spacesCheck(string playerName)
{
    for (int i = 0; i < playerName.length(); i++)
    {
        if (playerName[i] == ' ')
        {
           return false;
        }
    }
    return true;
}

/*
-----------------------------------------------------------
 The function adds together the character arrays within two 
 LongInteger objects. In addition, it returns 
 a LongInteger object with the sum.
-----------------------------------------------------------
*/
LongInteger add(const LongInteger Int1, const LongInteger Int2, const int ARRAY_SIZE)
{
    int biggest_integer_size; 
    int temp_sum_value;
    string str_double_digit;
    bool carry_the_one = false;
    LongInteger localInteger;

    if (Int1.IntSize() > Int2.IntSize())
    {
          biggest_integer_size = Int1.IntSize();
    }
    else if (Int1.IntSize() < Int2.IntSize())
    {
          biggest_integer_size = Int2.IntSize();
    }
    else
    {
          biggest_integer_size = Int1.IntSize();
    }
    
    for (int i = ARRAY_SIZE - 1; i >= ARRAY_SIZE - biggest_integer_size; i--)
    {
           //conditional for if indexes add up to nine or less
        if (int(Int1.GetChar(i) - '0') + int(Int2.GetChar(i) - '0') < 10)
          
        {    
        
            if(carry_the_one)
            { 
                if(int(Int1.GetChar(i) - '0') + int(Int2.GetChar(i) - '0') + 1 == 10 || 
                  int(Int1.GetChar(i) - '0') + 1 == 10 || 
                  int(Int2.GetChar(i) - '0') + 1 == 10)
                 {
                      //carrying the one from last sum that was equal or over 10(this addition goes over nine from the one being carried)
                      if(Int1.GetChar(i) == ' ')
                      {
                         str_double_digit = intToString(int(Int2.GetChar(i) - '0') + 1);
                         temp_sum_value = int(str_double_digit[1]);
                         localInteger.SetChar(char(temp_sum_value), i);
                         carry_the_one = true;
                      }
                      else if(Int2.GetChar(i) == ' ')
                      {
                         str_double_digit = intToString(int(Int1.GetChar(i) - '0') + 1);
                         temp_sum_value = int(str_double_digit[1]);
                         localInteger.SetChar(char(temp_sum_value), i);
                         carry_the_one = true;
                      }
                      else
                      {
                        str_double_digit = intToString(int(Int1.GetChar(i) - '0') + int(Int2.GetChar(i) - '0') + 1);
                         temp_sum_value = int(str_double_digit[1]);
                         localInteger.SetChar(char(temp_sum_value), i);
                         carry_the_one = true;
                      }
                     
                      if(i == ARRAY_SIZE - biggest_integer_size)
                      {
                            localInteger.SetChar(char(49), i-1);
                      }
                 }
                else
                 { 
                      //carrying the one from last sum that was equal or over 10(this addition still doesn't go over nine)
                      if(Int1.GetChar(i) == ' ')
                      {
                          temp_sum_value = int(Int2.GetChar(i) - '0') + 1;
                          localInteger.SetChar(char(temp_sum_value + 48), i);
                          carry_the_one = false;
                      }
                      else if(Int2.GetChar(i) == ' ')
                      {
                          temp_sum_value = int(Int1.GetChar(i) - '0') + 1;
                          localInteger.SetChar(char(temp_sum_value + 48), i);
                          carry_the_one = false;
                      }
                      else
                      {
                          temp_sum_value = int(Int1.GetChar(i) - '0') + int(Int2.GetChar(i) - '0') + 1;
                          localInteger.SetChar(char(temp_sum_value + 48), i);
                          carry_the_one = false;
                      }
                      
                 } 
            }
            else 
            {
                  //adding indexes that don't have a sum of over nine and a one is not being carried
                     if (Int1.GetChar(i) == ' ')
                     {
                         temp_sum_value = int(Int2.GetChar(i) - '0');
                         localInteger.SetChar(char(temp_sum_value + 48), i);
                         carry_the_one = false;
                     }
                     else if (Int2.GetChar(i) == ' ')
                     {
                         temp_sum_value = int(Int1.GetChar(i) - '0');
                         localInteger.SetChar(char(temp_sum_value + 48), i);
                         carry_the_one = false;
                     }
                     else
                     {
                        temp_sum_value = int(Int1.GetChar(i) - '0') + int(Int2.GetChar(i) - '0');
                        localInteger.SetChar(char(temp_sum_value + 48), i);
                        carry_the_one = false;
                     }
            }
                
        }   
        else if (int(Int1.GetChar(i) - '0') + int(Int2.GetChar(i) - '0') >= 10)
        {
             if (carry_the_one)
             {
                  //add one to addition since one is being carried
                  str_double_digit = intToString(int(Int1.GetChar(i) - '0') + int(Int2.GetChar(i) - '0') + 1);
                  temp_sum_value = int(str_double_digit[1]);
                  localInteger.SetChar(char(temp_sum_value), i);
                  carry_the_one = true;
               
                  if (i == ARRAY_SIZE - biggest_integer_size)
                  {
                        localInteger.SetChar(char(49), i-1);
                  }  
             }
             else 
             {
                  // do not add one to addition since one is not being carried
                  str_double_digit = intToString(int(Int1.GetChar(i) - '0') + int(Int2.GetChar(i)) - '0');
                  temp_sum_value = int(str_double_digit[1]);
                  localInteger.SetChar(char(temp_sum_value), i);
                  carry_the_one = true;
               
                  if (i == ARRAY_SIZE - biggest_integer_size)
                  {
                        localInteger.SetChar(char(49), i-1);
                  }
             }        
         }   
     } 
    return localInteger;
 }

/*
-----------------------------------------------------------
The function multiplies together the character arrays within 
two LongInteger objects. In addition, it returns a LongInteger 
object with the product(uses add function as well).
-----------------------------------------------------------
*/
LongInteger multiply(const LongInteger first_integer, const LongInteger last_integer, LongInteger products[12], const int ARRAY_SIZE)
{
    LongInteger product_integer;
    LongInteger value_holder;
    string interim_products[12];
    string str_first_integer = arrayToString(first_integer, first_integer.MaxSize());
    string str_last_integer = arrayToString(last_integer, last_integer.MaxSize());
    int counter = 0;
    int product_value;
    int carried_value = 0;
    int number_of_ints = 0;
    string str_equivalent = "";

    EmptyArray(interim_products,12);

    if(str_first_integer.size() <= str_last_integer.size())
    {
         number_of_ints = str_first_integer.size(); // get number of integers
        //multiply first integer by the last integer
        for (int i = str_first_integer.size() - 1; i >= 0; i--) // TODO: reverse loop
        {
            carried_value = 0; // reset carried value everytime inner loop finishes
            for (int j = str_last_integer.size() - 1; j >= 0; j--)
            {
                if (int(str_first_integer[i] - '0') * int(str_last_integer[j] - '0') + carried_value < 10)
                {
                    product_value = int(str_first_integer[i] - '0') * int(str_last_integer[j] - '0') + carried_value;
                    str_equivalent = intToString(product_value);
                    interim_products[i].insert(0,str_equivalent);
                    carried_value = 0;
                    
                } 
                else 
                {
                    if (int(str_first_integer[i] - '0') * int(str_last_integer[j] - '0') + carried_value >= 10)
                    {
                        product_value = int(str_first_integer[i] - '0') * int(str_last_integer[j] - '0') + carried_value;
                        str_equivalent = intToString(product_value);
                        if(j == 0)
                        {
                            interim_products[i].insert(0,str_equivalent);
                        } 
                        else
                        {
                            interim_products[i].insert(0,str_equivalent.substr(1,1));
                            carried_value = int(str_equivalent[0] - '0'); 
                        }
                    }    
                } 
            }
              //adding zeros to intermediate product based on digit placement
              for (int k = 0; k < number_of_ints - (i+1); k++)
              {
                   interim_products[i].push_back('0');
              }
              
        }
    } 
    else
    {
        number_of_ints = str_last_integer.size(); //get number of integers
        for (int i = str_last_integer.size() - 1; i >= 0; i--)
        {
            carried_value = 0;
            for (int j = str_first_integer.size() - 1; j >= 0; j--)
            {
                if (int(str_first_integer[j] - '0') * int(str_last_integer[i] - '0') + carried_value < 10)
                  {
                      product_value = int(str_first_integer[j] - '0') * int(str_last_integer[i] - '0') + carried_value;
                      str_equivalent = intToString(product_value);
                      interim_products[i].insert(0,str_equivalent);
                      carried_value = 0;
                  } 
                  else 
                  {
                      if (int(str_first_integer[j] - '0') * int(str_last_integer[i] - '0') + carried_value >= 10)
                      {
                          product_value = int(str_first_integer[j] - '0') * int(str_last_integer[i] - '0') + carried_value;
                          str_equivalent = intToString(product_value);
                          if (j == 0)
                          {
                              interim_products[i].insert(0,str_equivalent);
                            
                          } 
                          else
                          {
                              interim_products[i].insert(0,str_equivalent.substr(1,1));
                              carried_value = int(str_equivalent[0] - '0'); 
                          }
                                
                      }    
                  }
                 counter++;
             }
              
              for (int k = 0; k < number_of_ints - (i+1); k++)
              {
                  interim_products[i].push_back('0');
              }
              
         } 
  
    }
    //convert interim strings into the longInteger objects and
    //call add function on everything in list add to LongInteger product variable  
    for (int i = 0; i < number_of_ints; i++)
    {
        products[i].stringToArray(interim_products[i]); 
    }

    for (int j = 1; j <= number_of_ints; j++)
    {
        if (j == 1)
        {
            value_holder = add(products[0], products[1], ARRAY_SIZE);
          product_integer= value_holder; 
            continue;
        }

          product_integer= add(value_holder, products[j], ARRAY_SIZE);
          value_holder = product_integer; 
    }

    

  return product_integer;

}

/*
-----------------------------------------------------------
compresses the charactors within the LongInteger array
into a string and returns the string
-----------------------------------------------------------
*/
string arrayToString(LongInteger integer, const int ARRAY_SIZE)
{
    string temp_str;
    bool number_started = false;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
          if((isdigit(integer.GetChar(i))))
          {
                number_started = true;
          }

          if(number_started)
          {
               temp_str.push_back(integer.GetChar(i)); 
          }
    }
    return temp_str;
}

/*
-----------------------------------------------------------
converts any integer between 0 and 99 into a string
-----------------------------------------------------------
*/
string intToString(int number)
{

   int tens_digit;
   int ones_digit;
   int multiple_of_ten;
   string string_version = "";
   if (number < 10)
   {
      ones_digit = number % 10;
      string_version.push_back(char(ones_digit + 48));
   } 
   else 
   {
      tens_digit = number % 10;
      multiple_of_ten = number - tens_digit;
      ones_digit = multiple_of_ten / 10;
      string_version.push_back(char(ones_digit + 48));
      string_version.push_back(char(tens_digit + 48));
   }
   return string_version;

}

/*
-----------------------------------------------------------
fills an array of string with blank spaces(make it empty)
-----------------------------------------------------------
*/
void EmptyArray(string string_list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        string_list[i] = " ";
    }
}
/*
-----------------------------------------------------------
returns true or false whether a character is a digit or not
-----------------------------------------------------------
*/
bool isdigit(char digit)
{
      if (digit == '0'){
        return true;
      }
      if (digit == '1'){
        return true;
      }
      if (digit == '2'){
        return true;
      }
      if (digit == '3'){
        return true;
      }
      if (digit == '4'){
        return true;
      }
      if (digit == '5'){
        return true;
      }
      if (digit == '6'){
        return true;
      }
      if (digit == '7'){
        return true;
      }
      if (digit == '8'){
        return true;
      }
      if (digit == '9'){
        return true;
      }

    return false;  
}

/*
-----------------------------------------------------------
couts a certain amount of blank spaces based on the integer
parameter
-----------------------------------------------------------
*/
void MakeSpaces(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        cout << " ";
    }
}

/*
-----------------------------------------------------------
returns the size of the smaller LongInteger object
-----------------------------------------------------------
*/
int SmallestInt(const LongInteger int1, const LongInteger int2)
{
    if (int1.IntSize() <= int2.IntSize())
    {
        return int1.IntSize();
    }
    else
    {
        return int2.IntSize();   
    }
}
/*
-----------------------------------------------------------
Input validation for when the user input integers

checks whether:
- there is anything besides digits in input
- if there are spaces with the input
- if there's a integer with multiple digits that leads
  with a zero
-----------------------------------------------------------
*/
void isIntegerValid(string &int_input, const int MAX_DIGITS)
{
    while (!isOnlyDigits(int_input) || !spacesCheck(int_input) || !leadWithZero(int_input) || int_input.length() > MAX_DIGITS || int_input == "")
    {
        if (!isOnlyDigits(int_input))
        {
            cout << "\nThere is a character within input that is not a digit, try again.\n--> ";
            getline(cin,int_input);  
            continue;
        }
        if (!spacesCheck(int_input))
        {
            cout << "\nThere cannot be a space within the input, try again.\n--> ";
            getline(cin,int_input);  
            continue;
        }
        if (int_input.length() > MAX_DIGITS)
        {
            cout << "\nInteger cannot be longer than 12 digits, try again.\n--> ";
            getline(cin,int_input);
            continue;
        }
        if(!leadWithZero(int_input))
        {
            cout << "\nInteger with multiple digits cannot lead with a zero, try again.\n--> ";
            getline(cin, int_input); 
        }

        if (int_input == "")
        {
         cout << "\nInput cannot be blank, try again.\n--> ";
         getline(cin,int_input);
         continue;
          
        }
    }  
}
/*
-----------------------------------------------------------
returns true or false whether string consist of only digits
or not
-----------------------------------------------------------
*/
bool isOnlyDigits(string int_input)
{
  for (int i = 0; i < int_input.length(); i++)
  {
      if (!isdigit(int_input[i]) && int_input[i] != ' ')
      {
        return false;
      }
  }

  return true;
}

/*
-----------------------------------------------------------
The function returns false if the string has a length of 2 
or greater and leads with a zero. Otherwise, it returns true.
-----------------------------------------------------------
*/
bool leadWithZero(string int_input)
{
    if(int_input.length() == 1 || int_input[0] != '0')
    {
        return true;    
    }
  
    return false;
}
