#include <vector>
#include <iostream>
#include <algorithm>
template<typename T>
class SumIsGreaterThan
{
    int sum = 0;
    int target = 0;
    public:
    SumIsGreaterThan(T value):target(value){}
    bool operator()(const T& n)
    {
        sum += n;
        return sum > target;
    }
};

int main()
{
    std::vector<int> nums = {1,23,2,345,232,6678,34,2337,6};
    SumIsGreaterThan pred(1020);
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