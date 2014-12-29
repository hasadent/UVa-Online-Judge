/****
 * 172 - Calculator Language
 */
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <stack>
using std::stack;

namespace inner_variable
{
    int variable[26] = {0};
    int vlast[26] = {0};
}/* namespace inner_variable */

int * variable = inner_variable::variable - 'A';
int * vlast = inner_variable::vlast - 'A';

void set_variable(int name, int value)
{
    variable[name] = value;
}

int get_variable(int name)
{
    return variable[name];
}

void print_result()
{
    int cc = 0;
    for (int i = 'A'; i <= 'Z'; i++)
        if (vlast[i] != variable[i])
        {
            vlast[i] = variable[i];
            if (cc != 0)
                printf(", ");
            printf("%c = %d", (char)i, variable[i]);
            cc++;
        }

    puts(cc == 0 ? "No Change" : "");
}

typedef struct node{
    enum OP_TYPE { NONE = 0,
        NEG = '_', PLUS = '+', MINUS = '-', MULT = '*', DIV = '/',
        ASSIGN = '=', VARIABLE ='x', VALUE = 'v' } type;
    char name;
    int  value;
    node * op0;
    node * op1;
} node;

void variable_to_value(node & x)
{
    if (x.type == node::VARIABLE)
    {
        x.type  = node::VALUE;
        x.value = get_variable(x.name);
    }
}

node * new_node()
{
    node * n = new node;
    n->type = node::NONE;
    n->op0  = n->op1 = 0;
    return n;
}

stack<char> symbol_st;
stack<node *> node_st;

void print_node(node *n)
{
    if (n == NULL)
        return;

    switch(n->type)
    {
    case node::VALUE:
        printf("%d", n->value);
        break;

    case node::VARIABLE:
        printf("%c", n->name);
        break;

    default:
        printf("(");
        printf("%c", (char)n->type);

        if (n->op0)
        {
            printf(" ");
            print_node(n->op0);
        }

        if (n->op1)
        {
            printf(" ");
            print_node(n->op1);
        }
        printf(")");
        break;
    }
}

void eval_node(node *n)
{
    switch(n->type)
    {
    case node::VALUE:
        break;

    case node::VARIABLE:
        variable_to_value(*n);
        break;

    case node::NEG:
        eval_node(n->op0);
        n->type  = node::VALUE;
        n->value = - n->op0->value;

        delete n->op0;
        n->op0 = NULL;
        break;

    case node::PLUS:
        eval_node(n->op1);
        eval_node(n->op0);


        n->type  = node::VALUE;
        n->value = n->op0->value + n->op1->value;

        delete n->op0;
        delete n->op1;
        n->op0 = n->op1 = NULL;
        break;

    case node::MINUS:
        eval_node(n->op1);
        eval_node(n->op0);

        n->type  = node::VALUE;
        n->value = n->op0->value - n->op1->value;

        delete n->op0;
        delete n->op1;
        n->op0 = n->op1 = NULL;
        break;

    case node::MULT:
        eval_node(n->op1);
        eval_node(n->op0);

        n->type  = node::VALUE;
        n->value = n->op0->value * n->op1->value;

        delete n->op0;
        delete n->op1;
        n->op0 = n->op1 = NULL;
        break;

    case node::DIV:
        eval_node(n->op1);
        eval_node(n->op0);

        n->type  = node::VALUE;
        n->value = n->op0->value / n->op1->value;

        delete n->op0;
        delete n->op1;
        n->op0 = n->op1 = NULL;
        break;

    case node::ASSIGN:
        eval_node(n->op1);

        set_variable(n->op0->name, n->op1->value);
        n->type  = node::VALUE;
        n->value = n->op1->value;

        delete n->op0;
        delete n->op1;
        n->op0 = n->op1 = NULL;
        break;

    default:
        break;
    }


}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    bool get_next_char = true;
    bool next_negative = false;
    char ch;

    for (;;)
    {
        ch = get_next_char ? getchar() : ch;
        get_next_char = true;

        switch (ch)
        {
        case '#':
            goto done;

        case ' ':
            break;

        case '+': case '-': case '*': case '/': case '(': case '=':
            symbol_st.push(ch);
            break;

        case '_':
            next_negative = true;
            break;

        case '\n':
        {
            char s;
            while (!symbol_st.empty())
            {
                s = symbol_st.top();
                symbol_st.pop();

                node * op1 = node_st.top(); node_st.pop();
                node * op0 = node_st.top(); node_st.pop();

                node * n = new_node();
                n->type = (node::OP_TYPE)s;
                n->op0 = op0;
                n->op1 = op1;

                node_st.push(n);
            }

            node * n = node_st.top();

            eval_node(n);

            print_result();
            break;
        }
        case ')':
        {
            char s;
            while ((s = symbol_st.top()) != '(')
            {
                symbol_st.pop();

                node * op1 = node_st.top(); node_st.pop();
                node * op0 = node_st.top(); node_st.pop();

                node * n = new_node();
                n->type = (node::OP_TYPE)s;
                n->op0 = op0;
                n->op1 = op1;

                node_st.push(n);
            }

            if (next_negative)
            {
                next_negative = false;

                node * neg = new_node();
                neg->type = node::NEG;
                neg->op0  = node_st.top();
                node_st.pop();
                node_st.push(neg);
            }

            symbol_st.pop(); // POP '('
            break;
        }
        default:
        {
            if ('A' <= ch && ch <= 'Z')
            {
                node * n = new_node();
                n->type  = node::VARIABLE;
                n->name  = ch;

                if (next_negative)
                {
                    next_negative = false;

                    node * neg = new_node();
                    neg->type = node::NEG;
                    neg->op0  = n;
                    n = neg;
                }

                node_st.push(n);
            }
            else if ('0' <= ch && ch <= '9')
            {
                int value = 0;
                while ('0' <= ch && ch <= '9')
                {
                    value = value * 10 + ch - '0';
                    ch = getchar();
                }

                node * n = new_node();
                n->type  = node::VALUE;
                n->value = value;

                if (next_negative)
                {
                    next_negative = false;

                    node * neg = new_node();
                    neg->type = node::NEG;
                    neg->op0  = n;
                    n = neg;
                }

                node_st.push(n);

                get_next_char = false;
            }
            else
            {
                 fprintf(stderr, "UC = %c(%d)\n", ch , (int)ch);
            }
        }
        } /* swtich (ch) */
    }
done:


#ifndef ONLINE_JUDGE
    //system("pause");
#endif
    return 0;
}
