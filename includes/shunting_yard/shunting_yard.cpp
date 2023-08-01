#include "shunting_yard.h"

Queue<Token *> ShuntingYard::postfix()
{
    Stack<Token *> operator_stack;
    Queue<Token *> result_queue;

    Token* trig_token;


    while (!infix_queue.empty())
    {
        Token *token = infix_queue.pop();

        if (token->TypeOf() == INTEGER)
        {
            result_queue.push(token);
        }
        else if (token->TypeOf() == LEFTPAREN)
        {
            operator_stack.push(token);
        }
        else if (token->TypeOf() == RIGHTPAREN)
        {
           while (operator_stack.top()->TypeOf() != LEFTPAREN)
            {
                result_queue.push(operator_stack.pop());
            }
            operator_stack.pop();

            if(trig_token != nullptr)
            {
                result_queue.push(trig_token);
                trig_token = nullptr;
            }
        }
        else if (token->TypeOf() == FUNCTION)
        {
        if(token->get_value() == "x")
            result_queue.push(token);
            else
            {
                trig_token = token;
            }        
        }
        else if (token->TypeOf() == OPERATOR)
        {

            if (operator_stack.empty())
            {
                operator_stack.push(token);
            }
            else if (operator_stack.top()->TypeOf() == LEFTPAREN)
            {
                operator_stack.push(token);
            }
            else
            {
                if (static_cast<Operator *>(operator_stack.top())->get_prec() < static_cast<Operator *>(token)->get_prec())
                {
                    operator_stack.push(token);
                }
                else if (static_cast<Operator *>(operator_stack.top())->get_prec() == static_cast<Operator *>(token)->get_prec() &&
                         static_cast<Operator *>(operator_stack.top())->get_operator() != "^" && operator_stack.top()->TypeOf() != LEFTPAREN)
                {
                    result_queue.push(operator_stack.pop());
                    operator_stack.push(token);
                }
                else if (static_cast<Operator *>(operator_stack.top())->get_prec() == static_cast<Operator *>(token)->get_prec() &&
                         static_cast<Operator *>(operator_stack.top())->get_operator() == "^")
                {
                    operator_stack.push(token);
                }
                else if (static_cast<Operator *>(operator_stack.top())->get_prec() > static_cast<Operator *>(token)->get_prec() &&
                         operator_stack.top()->TypeOf() != LEFTPAREN)
                {

                    result_queue.push(operator_stack.pop());
                    operator_stack.push(token);
                }
            }
        }
    }
    while (!operator_stack.empty())
    {
        result_queue.push(operator_stack.pop());
    }

    return result_queue;
}

Queue<Token *> ShuntingYard::postfix(Queue<Token *> infix)
{
    Stack<Token *> operator_stack;
    Queue<Token *> result_queue;

    Token* trig_token;

    while (!infix.empty())
    {
        Token *token = infix.pop();


        if (token->TypeOf() == INTEGER)
        {
            result_queue.push(token);
        }
        else if (token->TypeOf() == LEFTPAREN)
        {
            operator_stack.push(token);
        }
        else if (token->TypeOf() == RIGHTPAREN)
        {
            while (operator_stack.top()->TypeOf() != LEFTPAREN)
            {
                result_queue.push(operator_stack.pop());
            }
            operator_stack.pop();

            if(trig_token != nullptr)
            {
                result_queue.push(trig_token);
                trig_token = nullptr;
            }
        }
        else if (token->TypeOf() == FUNCTION)
        {
            if(token->get_value() == "x")
            result_queue.push(token);
            else
            {
                trig_token = token;
            }
            
        }
        else if (token->TypeOf() == OPERATOR)
        {

            if (operator_stack.empty())
            {
                operator_stack.push(token);
            }
            else
            {
                if (static_cast<Operator *>(operator_stack.top())->get_prec() < static_cast<Operator *>(token)->get_prec())
                {
                    operator_stack.push(token);
                }
                else if (static_cast<Operator *>(operator_stack.top())->get_prec() == static_cast<Operator *>(token)->get_prec() &&
                         static_cast<Operator *>(operator_stack.top())->get_operator() != "^" && operator_stack.top()->TypeOf() != LEFTPAREN)
                {
                    /*error here*/
                    result_queue.push(operator_stack.pop());
                    operator_stack.push(token);
                }
                else if (static_cast<Operator *>(operator_stack.top())->get_prec() == static_cast<Operator *>(token)->get_prec() &&
                         static_cast<Operator *>(operator_stack.top())->get_operator() == "^")
                {
                    operator_stack.push(token);
                }
                else if (static_cast<Operator *>(operator_stack.top())->get_prec() > static_cast<Operator *>(token)->get_prec() &&
                         operator_stack.top()->TypeOf() != LEFTPAREN)
                {

                    result_queue.push(operator_stack.pop());
                    operator_stack.push(token);
                }
                else if (operator_stack.top()->TypeOf() == LEFTPAREN)
                {
                    operator_stack.push(token);
                }
            }
        }
    }
    while (!operator_stack.empty())
    {
        
        result_queue.push(operator_stack.pop());
    }

    result_queue.print_pointers();
    return result_queue;
}