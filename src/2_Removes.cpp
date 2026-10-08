#include <iostream>
#include <vector>
#include <algorithm>
#include <string_view>
#include <charconv>
#include <exception>

// What does the std::remove() algorithm do? It just a predicate that marks the iterators inside the vector to be erase.
// Write code that eliminates all values equal to 3 from a vector<int>
void EliminateTheThrees()
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
}
// write a special-purpose remove_nth algorithm
template<typename FwdIter>
FwdIter remove_nth(FwdIter first, FwdIter last, size_t n)
{
    if(std::distance(first,last) < n || n == 0)
    {
        throw std::out_of_range("parameter is out of range, should it be less than 7 and greater than 0");
    }
    int count =0;
    for(auto it = first; it != last;++it)
    {
        count++;
        if(n == count)
        {
            return it;
        }
    }
    return FwdIter(); 
}
// Write a function obj which returns true if nth time its applied, and use that as a predicate for remove_if
class FlagNth
{
    public:
        FlagNth(size_t n):current_(0),n_(n)
        {

        }
        template<typename T>
        bool operator()(const T&){return ++current_ == n_;}

    private:
        size_t current_;
        const size_t n_;
};
int main(int argc,char* argv[])
{
    if(argc < 2)
    {
        return 1;
    }
    std::string_view arg = argv[1];
    int nth=0;
    std::vector<int> nums={1,3,4,5,3,4,3};
    std::from_chars(arg.data(),arg.data() + arg.size(),nth);   
    nums.erase(remove_nth(nums.begin(),nums.end(),nth));
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