const int PRIME_MAX = 1000001;
const int PRIME_MAX_SQRT = 1001;
int prime[PRIME_MAX] = {0};

void init_prime()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < PRIME_MAX_SQRT; i++)
        if (prime[i] == 0)
            for (int j = i*2; j < PRIME_MAX; j += i)
                prime[j] = 1;
}

