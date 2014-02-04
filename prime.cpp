const int PRIME_MAX = 1000001;
const int PRIME_MAX_SQRT = 256;
int prime[PRIME_MAX];


memset(prime, 0, sizeof(prime));
prime[0] = prime[1] = 1;

for (int i = 2; i < PRIME_MAX_SQRT; i++)
  if (prime[i] == 0)
     for (int j = i*2; j < PRIME_MAX; j += i)
       prime[j] = 1;
