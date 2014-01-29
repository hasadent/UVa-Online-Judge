class big_num
{
    static const int BIG_NUM_SIZE = (1000000/4+1);
    int num[BIG_NUM_SIZE];
public:
    big_num();
    void operator= (const int);
    void operator= (const char *);
    big_num operator* (const int);
    big_num & operator+= (const big_num &);
    friend ostream& operator<<(ostream& os, const big_num& dt);
};

big_num::big_num()
{}

void big_num::operator=(const int i)
{
    memset(num, 0, sizeof(num));
    int j = i;

    num[BIG_NUM_SIZE-2] = j / 10000;
    num[BIG_NUM_SIZE-1] = j % 10000;
    j /= 10000;
    num[BIG_NUM_SIZE-3] = j / 10000;
    num[BIG_NUM_SIZE-2] = j % 10000;
}

void big_num::operator=(const char *p)
{
    memset(num, 0, sizeof(num));

    int x = BIG_NUM_SIZE-1;
    int len = strlen(p) - 1;
    for (; len >= 3; len -= 4, x--)
    {
        num[x] = (p[len] - '0') + (p[len-1] - '0') * 10 +
            (p[len-2] - '0') * 100 + (p[len-3] - '0') * 1000;
    }

    for (int i = 0; i <= len ; i++)
        num[x] = num[x] * 10 + (p[i] - '0');
}

big_num & big_num::operator+=(big_num const &rhs)
{
    for (int i = 0; i < BIG_NUM_SIZE; i++)
        num[i] += rhs.num[i];

    for (int i = BIG_NUM_SIZE - 1; i > 0; i--)
    {
        num[i-1] += num[i] / 10000;
        num[i]   =  num[i] % 10000;
    }

    return *this;
}

big_num & big_num::operator=(big_num const &rhs)
{
    for (int i = 0; i < BIG_NUM_SIZE; i++)
        num[i] += rhs.num[i];

    return *this;
}

big_num big_num::operator*(const int n)
{
    big_num r;

    for (int i = 0; i < BIG_NUM_SIZE; i++)
    {
        r.num[i] = num[i] * n;
    }

    for (int i = BIG_NUM_SIZE - 1; i > 0; i--)
    {
        r.num[i-1] += r.num[i] / 10000;
        r.num[i]   = r.num[i] % 10000;
    }

    return r;
}

ostream& operator<<(ostream& os, const big_num& bn)
{
    int i = 0;
    while (i < big_num::BIG_NUM_SIZE && bn.num[i] == 0) i++;

    if (i == big_num::BIG_NUM_SIZE)
    {
        os << "0";
    }
    else
    {
        os << bn.num[i];
        i++;
    }

    if (i < big_num::BIG_NUM_SIZE)
    {
        for (; i < big_num::BIG_NUM_SIZE; i++)
            os << setfill('0') << setw(4) << bn.num[i];
    }

    return os;
}
