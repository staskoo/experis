#include<iostream>
#include<set>

using namespace std;

int factorial(int a_num)
{
    if(a_num < 2)
    {
        return 1;
    }
    return a_num * factorial(a_num -1);
}

bool isNumberPolindrome(int a_number, int a_numDigits)
{
    int modulo = 1;
    if(a_number < 10)
    {
        return true;
    }
    for(int i = 0; i < a_numDigits - 2; i++)
    {
        modulo = modulo * 10;
    }
    a_number = a_number / 10;
    a_number = a_number % modulo;
    isNumberPolindrome(a_number, a_numDigits - 2);
    if(modulo > 10)
    {
        modulo = modulo / 10;
    }
    if(a_number / modulo == a_number % 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isisNumberPolindromeRec2(int a_number, int* a_numberCopy)
{
    bool status = false;
    if(a_number == 0)
    {
        return true;
    }
    status = isisNumberPolindromeRec2(a_number / 10, a_numberCopy);
    if(status && (a_number % 10 == *a_numberCopy % 10))
    {
        status = true;
    }
    else
    {
        status = false;
    }
    *a_numberCopy /= 10;
    return status;
}

bool isNumberPolindrome2(int a_number)
{
    int* numCopy = new int(a_number);
    bool status = isisNumberPolindromeRec2(a_number, numCopy);
    return status;
}


void posibleK(char* a_set, size_t a_sizeOfSet, size_t a_k )
{
    if(a_k == 1)
    {
        return;
    }
    posibleK(a_set, a_sizeOfSet, a_k - 1);
    cout << a_set[0];
}

int myAtoiRec(char* a_strNumber)
{
    if(*a_strNumber == '\0')
    {
        return 0;
    }
    int agregatedNum = myAtoiRec(a_strNumber + 1);
    char charNum = *a_strNumber;
    int intNum = charNum - 48;
    agregatedNum = agregatedNum * 10 + intNum;
    return agregatedNum;
}

int sizeOfStr(const char* a_str)
{
     if(a_str == 0)
     {
          return 0;
     }
     int size = 0;
     while(a_str[size] != '\0')
     {
          size++;
     }
     return size;
}

int myAtoiRec2(char* a_strNumber, int a_size)
{
     int count = 0, check;
    // loop to count the no. of alphabets in str
    for (int i = 0; i <= sizeOfStr(a_strNumber); ++i) {
 
        // check if str[i] is an alphabet
        check = isalpha(a_strNumber[i]);
 
        // increment count if str[i] is an alphabet
        if (check)
            ++count;
    }
    if (count != 0) {
        return 0;
    }

    if(a_size == 1)
    {
        return *a_strNumber - '0';
    }
    int agregatedNum = 10 * myAtoiRec2(a_strNumber, a_size - 1) + a_strNumber[a_size - 1] - '0';
    return agregatedNum;
}


int countOnes(int a_num)
{
     int counter = 0;
     int mask = 1;
     while(a_num > 0)
     {
          if(a_num & mask)
          {
               counter++;
          }
          a_num /= 2;
     }
     return counter;
}

void printNumbers(int a_num, int a_nCount)
{
     int counter = 0;
     int mask = 1;
     while(a_num > 0)
     {
          int firstDigit = a_num & mask;
          printf("%d", firstDigit);
          a_num /= 2;
          counter++;
     }
     while(a_nCount > counter)
     {
          counter++;
          printf("0");
     }
}

void findAllSequencesRec(int a_num, int a_sameNum, int a_nCount)
{
     if(a_num == 0)
     {
          printNumbers(a_num, a_nCount * 2);
          printf(" ");
          return;
     }
     findAllSequencesRec(a_num - 1, a_sameNum, a_nCount);
     for(int i = 0; i <= a_sameNum; i++)
     {
          if(countOnes(i) == countOnes(a_num))
          {
               printNumbers(a_num, a_nCount);
               printNumbers(i, a_nCount);
               printf(" ");
          }
     }
}

void findAllSequences(int a_num)
{
     if(a_num < 1)
     {
          return;
     }
     int maskedNumber = 1;
     for(int i = 0; i < a_num; i++)
     {
          maskedNumber *= 2;
     }
     maskedNumber -= 1;
     findAllSequencesRec(maskedNumber, maskedNumber, a_num);
}


int main()
{
     findAllSequences(2);
    return 0;
}