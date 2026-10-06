#include <fstream>
#include <iostream>
void Process(std::fstream in, std::fstream out)
{
    
}

int main(int argc, char* argv[])
{
    std::fstream in;
    std::fstream out;
    if(argc > 1)
    {
        in.open(argv[1],ios::in || ios::binary);
    }
    if (argc > 2)
    {
        out.open(argv[2],ios::in || ios::binary);
    }
    Process(in.is_open() ? in : std::cin,out.is_open()? out : std::cout);
    return 0;
}