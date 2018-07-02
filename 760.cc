#include <iostream>
#include <vector>
#include <stdexcept>
#include <unordered_map>

class Resolution {
public:
    void main(std::vector<int>& a, std::vector<int>& b, std::vector<int>& out)
    {
        int lengthA = a.size();
        int lengthB = b.size();

        if(lengthA != lengthB)
        {
            std::cerr << "not a anagram." << std::endl;
            return;
        }

        for(int index = 0; index < a.size(); index++)
        {
            int target = a.at(index);

            for(int j = 0; j<b.size(); j++)
            {
                if(target == b.at(j))
                {
                    out.push_back(j);
                }
            }
        }
    }

    std::vector<int> main(std::vector<int>& a, std::vector<int>& b)
    {
        std::unordered_map<int,int> mapB;
        std::vector<int> out;

        for(int j = 0; j<b.size(); ++j)
        {
             mapB[b[j]] = j; 
        }

        for(int i = 0; i < a.size(); ++i)
        {
            int target = a.at(i);
            int index = mapB[target];
            out.push_back(index);
        }

        return out;
    }
};

int main()
{
    std::vector<int> a{12,28,46,32,50};
    std::vector<int> b{50,12,32,46,28};
    std::vector<int> c;

    Resolution r;
    r.main(a,b,c);

    for(auto& _ : c)
    {
        std::cout << "c : " << _ << "\t";
    }

    std::cout << "\n";

    std::cout << "------------------------------------------------" << std::endl;

    std::vector<int> a_{12,28,46,32,50};
    std::vector<int> b_{50,12,32,46,28};
    std::vector<int> ret = r.main(a_, b_);
    for(auto& _ : ret)
    {
        std::cout << " " << _ << " " ;
    }

    std::cout << "\n";
}
