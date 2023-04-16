#include <iostream>
#include <cstring>
#include <Windows.h>

int mystrcmp(const char* str1, const char* str2)
{
    int result = 0;
    int index = 0;

    while (str1[index] && str2[index])
    {
        if (str1[index] != str2[index])
        {
            result = (str1[index] > str2[index]) ? 1 : -1;
            break;
        }

        index++;
    }

    if (result == 0)
    {
        if (str1[index])
            result = 1;
        else if (str2[index])
            result = -1;
    }

    return result;
}

char* NumberToString(int number)
{
    int num = number;
    int count = 0;

    if (num == 0)
        count = 1;
    else
    {
        while (num)
        {
            num /= 10;
            count++;
        }
    }

    char* str = new char[count + 1];
    str[count] = '\0';

    while (count > 0)
    {
        count--;
        str[count] = '0' + (number % 10);
        number /= 10;
    }

    return str;
}

char* Uppercase(char* str)
{
    int index = 0;

    while (str[index])
    {
        if (str[index] >= 'a' && str[index] <= 'z')
        {
            str[index] -= ('a' - 'A');
        }
        index++;
    }

    return str;
}

int main()
{
    const int MAX_SIZE = 100;
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    std::cout << "Enter the first line: ";
    std::cin.getline(str1, MAX_SIZE);

    std::cout << "Enter the second line: ";
    std::cin.getline(str2, MAX_SIZE);

    std::cout << "The result of string comparison: " << mystrcmp(str1, str2) << std::endl;

    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    char* str_number = NumberToString(number);
    std::cout << "The string obtained from the number: " << str_number << std::endl;

    delete[] str_number;

    char str[MAX_SIZE];
    std::cout << "Enter the string to convert to uppercase: ";
    std::cin.ignore();
    std::cin.getline(str, MAX_SIZE);

    char* uppercase_str = Uppercase(str);
    std::cout << "The string is in uppercase: " << uppercase_str << std::endl;

    delete[] uppercase_str;

    return 0;
}
