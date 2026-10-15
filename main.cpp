#include <iostream>
#include <deque>

using namespace std;

enum CommandType
{
	MoveLeft,
	MoveRight,
	MoveForward,
	MoveBackward
};

//your code
class RoboCommander
{
    std::deque<CommandType> deq;
    static void PrintCommand(CommandType comm)
    {
        switch (comm)
        {
        case MoveLeft:
            std::cout << "Moving Left\n";
            break;
        case MoveRight:
            std::cout << "Moving Right\n";
            break;
        case MoveForward:
            std::cout << "Moving Forward\n";
            break;
        case MoveBackward:
            std::cout << "Moving Backward\n";
            break;
        default:
            std::cout << "Ready\n";
            break;
        }
    }
    public:
    void AddCommand(CommandType CommType)
    {
        deq.push_back(CommType);
    }
    void UndoCommand()
    {
        if(deq.empty())
        {
            return;
        }
        deq.pop_back();
    }
    void Execute()
    {
        while(!deq.empty())
        {
            auto comm = deq.front();
            deq.pop_front();
            PrintCommand(comm);
        }
        std::cout << "Ready\n";
    }
};
int main()
{
	RoboCommander commander;
	commander.AddCommand(MoveLeft);
	commander.AddCommand(MoveRight);
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.AddCommand(MoveLeft);
	commander.AddCommand(MoveForward);
	commander.AddCommand(MoveLeft);
	commander.AddCommand(MoveForward);
	commander.AddCommand(MoveRight);
	commander.AddCommand(MoveBackward);
	commander.Execute();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.AddCommand(MoveForward);
	commander.Execute();
	return 0;
}
/*
Moving left
Moving forward
Moving left
Moving forward
Moving right
Moving backward
Ready
Moving left
Moving forward
Moving forward
Ready
*/