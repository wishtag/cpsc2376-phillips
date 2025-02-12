#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<std::string> tasks;
    int choice = 0;
    while (choice != 4) 
    {
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Show Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        while (std::cin.fail() || choice > 4 || choice < 1)
        {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> choice;
        }

        std::cin.ignore(256, '\n');

        switch (choice)
        {
        case 1:
        {
            std::string task;
            std::cout << "Enter task: ";
            std::getline(std::cin, task);
            tasks.push_back(task);
            std::cout << "Task added!\n";
            break;
        }
        case 2:
        {
            if (tasks.empty())
            {
                std::cout << "No tasks to remove!\n";
            }
            else
            {
                std::cout << "Enter task number to remove: ";
                int taskNum;
                std::cin >> taskNum;

                while (taskNum < 1 || taskNum > tasks.size() || std::cin.fail())
                {
                    std::cout << "Invalid task number. Please try again: ";
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    std::cin >> taskNum;
                }

                auto it = tasks.begin();
                std::advance(it, taskNum - 1);
                tasks.erase(it);
                std::cout << "Task removed!\n";
            }
            break;
        }
        case 3:
        {
            if (tasks.empty())
            {
                std::cout << "No tasks available.\n";
            }
            else
            {
                std::cout << "Tasks:\n";
                int taskNum = 1;
                for (const auto& task : tasks)
                {
                    std::cout << taskNum++ << ". " << task << '\n';
                }
            }
            break;
        }
        case 4:
        {
            std::cout << "Exiting...\n";
            break;
        }
        default:
        {
            break;
        }
        }
        std::cout << "\n";
    }

    return 0;
}
