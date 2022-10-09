#include <iostream>
#include <Array.hpp>
#include <chrono>
#include <thread>

#define MAX_VAL 750

int main()
{
    {
        Array<std::string> a;
        std::cout << a.Size() << std::endl;
        std::cout << a.getArrPntr() << std::endl;
        std::cout << "---------------" << std::endl;

        int count = 5;
        Array<int> b(count);
        std::cout << b.Size() << std::endl;
        std::cout << b.getArrPntr() << std::endl;
        for (int i = 0; i < count; i++)
            b.getArrPntr()[i] = i + 1;
        for (int i = 0; i < count; i++)
            std::cout << i << " " << b.getArrPntr()[i] << std::endl;
        try {b[count] = 10;}
        catch(const std::exception& e){std::cerr << e.what() << '\n';}
        std::cout << b.getArrPntr()[count] << std::endl;
        std::cout << "---------------" << std::endl;

        Array<int> cp_b1;
        cp_b1 = b;
        for (int i = 0; i < count; i++)
            std::cout << i << " " << cp_b1.getArrPntr()[i] << std::endl;
        for (int i = 0; i < count; i++)
            cp_b1.getArrPntr()[i] = i + 2;
        std::cout << "+++" << std::endl;
        for (int i = 0; i < count; i++)
            std::cout << i << " " << cp_b1.getArrPntr()[i] << " - " << b.getArrPntr()[i] << std::endl;
        std::cout << "---------------" << std::endl;

        Array<int> cp_b2(b);
        for (int i = 0; i < count; i++)
            std::cout << i << " " << cp_b2.getArrPntr()[i] << std::endl;
        for (int i = 0; i < count; i++)
            cp_b2.getArrPntr()[i] = i + 3;
        std::cout << "+++" << std::endl;
        for (int i = 0; i < count; i++)
            std::cout << i << " " << cp_b2.getArrPntr()[i] << " - " << b.getArrPntr()[i] << std::endl;
        std::cout << "---------------" << std::endl;
        // std::this_thread::sleep_for(std::chrono::seconds(100));
    }
    
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;

        //  std::this_thread::sleep_for(std::chrono::seconds(100));
    }

    return 0;
}