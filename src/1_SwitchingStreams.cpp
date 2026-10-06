#include <fstream>
#include <iostream>
template<typename C=char,typename T=std::char_traits<C>>
void Process(std::basic_istream<C,T>& inFile, std::basic_ostream<C,T>& outFile)
{
    
}

int main(int argc, char* argv[])
{
    std::fstream inFile;
    std::fstream outFile;
    if(argc > 1)
    {
        inFile.open(argv[1],std::ios::in | std::ios::binary);
    }
    if (argc > 2)
    {
        outFile.open(argv[2],std::ios::in | std::ios::binary);
    }
    Process(inFile.is_open() ? inFile : std::cin,outFile.is_open()? outFile : std::cout);
    return 0;
}