#include <iostream>
#include <vector>
#include <algorithm>
// What does the std::remove() algorithm do? It just mark the iterators inside the vector to be remove.
// Write code that eliminates all values equal to 3 from a vector<int>
int main()
{
    std::vector<int> nums={1,3,4,5,3,4,3};
    nums.erase(std::remove(nums.begin(),nums.end(),3),nums.end());
    for(auto it = nums.begin(); it != nums.end(); ++it)
    {
        std::cout << *it;
        if((it+1) != nums.end())
        {
            std::cout << ", ";
        }
    }
    return 0;
}