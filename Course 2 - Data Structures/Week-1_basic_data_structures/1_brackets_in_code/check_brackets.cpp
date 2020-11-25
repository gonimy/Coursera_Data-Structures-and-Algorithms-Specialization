//here is my solution for check_brackets problem

#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct Bracket
{
    Bracket(char type, int position) : type(type),
                                       position(position)
    {
    }

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()
{
    std::string text;
    int posErr = -1;
    getline(std::cin, text);

    std::stack<Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            // Process opening bracket, write your code here

            Bracket *b = new Bracket(next, position + 1);
            opening_brackets_stack.push(*b);
        }

        if (next == ')' || next == ']' || next == '}')
        {
            // Process closing bracket, write your code here

            if (opening_brackets_stack.size() == 0)
            {
                posErr = position + 1;
                break;
            }
            else if (opening_brackets_stack.top().Matchc(next))
            {
                opening_brackets_stack.pop();
            }
            else
            {
                posErr = position + 1;
                break;
            }
        }
    }

    // Printing answer, write your code here

    if (opening_brackets_stack.size() == 0 && posErr == -1)
    {
        cout << "Success" << endl;
    }
    else
    {
        /* code */
        if(opening_brackets_stack.size()&&posErr==-1){
            posErr=opening_brackets_stack.top().position;
        }
        cout << posErr << endl;
    }

    return 0;
}


