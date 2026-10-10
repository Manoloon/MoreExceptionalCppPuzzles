#include <vector>
#include <iostream>
#include <algorithm>

// este predicado retorna false mientras la suma de sus items no sobrepase el target,
// cuando esto sucede , la suma se resetea y vuelve a empezar con los items restantes.
template<typename T>
class SumIsGreaterThan
{
    int sum = 0;
    int target = 0;
    public:
    SumIsGreaterThan(T value):target(value)
    {
        std::cout << "the target is : " << target << std::endl;
    }
    bool operator()(const T& n)
    {
        //if(n > target) return true;
        sum += n;
        std::cout << sum << ", ";
        return sum > target;
    }
};

int main()
{
    std::vector<int> nums = {1,23,2,345,320,6678,34,6,2337,6};
    const int target = 1100;
    SumIsGreaterThan pred(target);
    auto it = std::find_if(nums.begin(),nums.end(),pred);
    std::cout << "\nfirst item that validate the predicate : " << *it << std::endl;
    // el problema aqui es que los algoritmos de la stl generalmente trabajan con copias,
    // por ende ese num dentro del predicado no acumularia, de todos modos esta funcionando con 15.2
    std::cout << "before the predicate is applied\n";
    for(int n : nums)
    {
        std::cout << n << ", ";
    }
    std::cout << "\nthe sum is ";
    // se van a remover los items que dada la suma de sus predecesores con el incluido sobrepasen el target
    // cuando esto sucede, el predicado resetea la suma.
    nums.erase(std::remove_if(nums.begin(),nums.end(),pred),nums.end());
    std::cout << "\nafter the predicates has been applied\n";
    for(auto n : nums)
    {
        std::cout << n << ", ";
    }
}