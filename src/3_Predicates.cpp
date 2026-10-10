#include <vector>
#include <iostream>
#include <algorithm>

class SumIsEven
{
    int num = 0;
    public:
    bool operator()(int n)
    {
        num += n;
        return num % 2 == 0;
    }
};

int main()
{
    std::vector<int> nums = {1,23,2,345,232,6678,34,2337,6};
    SumIsEven pred;
    auto it = std::find_if(nums.begin(),nums.end(),pred);
    std::cout << *it << std::endl;
    // el problema aqui es que los algoritmos de la stl generalmente trabajan con copias,
    // por ende ese num dentro del predicado no acumularia, de todos modos esta funcionando con 15.2
    nums.erase(std::remove_if(nums.begin(),nums.end(),pred),nums.end());
    for(auto n : nums)
    {
        std::cout << n << ", ";
    }
}