#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iterator>
#include <algorithm>

class Resolution {
public:
    void printBinary(int n)
    {
        std::stringstream ss;
        while(n)
        {
            if(n & 1)
            {
                ss << "1";
            }
            else
            {
                ss << "0";
            }

            n = n >> 1;
        }
        
        std::string str = ss.str();
        std::reverse(str.begin(), str.end());
        std::cout << "binary : " << str << std::endl;
    }
    bool isPrime(int c)
    {
        if(c == 1)
        {
            return false;
        }

        for(int i=2; i<c; ++i)
        {
            if(c % i == 0)
                return false;
        }

        return true;
    }
    void main(int left, int right)
    {
        if(left > right)
        {
            std::cerr << "error input" << std::endl;
            return;
        }
            
        int n = right - left + 1;
        std::cout << "n : " << n << std::endl;
        while(n)
        {
            int p = left;
            std::cout << "current : " << left << std::endl;
            unsigned int c = 0;
            while(p)
            {
                if(p & 1)
                {
                    ++c;
                }

                p = p >> 1;
            }

            printBinary(left);
            //if c is a prime?
            if(isPrime(c))
            {
                std::cout << "c is " << c << " and is a prime" << std::endl;
            }
            else
            {
                std::cout << c << " is not a prime" << std::endl;
            }

            n--;
            left++;
        }
    }
};

int main()
{
    Resolution r;
    r.main(6, 10);
}
