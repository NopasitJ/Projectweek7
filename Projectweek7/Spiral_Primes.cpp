#include <stdio.h>
#include <stdint.h>

#define N 1000000

int8_t sieve[N];
void init_sieve()
{
	int i, j;
	for (i = 0; i < N; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;
	for (i = 2; i < N; ++i)
		if (sieve[i])
			for (j = 2 * i; j < N; j += i)
				sieve[j] = 0;
}

int is_prime(int n)
{
	int p;
	if (n < N)
		return sieve[n];
	for (p = 2; p * p <= n; ++p)
		if (sieve[p] && n % p == 0)
			return 0;
	return 1;
}

int num_primes_corners(int len)
{
	int i, n;
	i = 0;
	n = len * len;
	n -= (len - 1);  
	if (is_prime(n))
		++i;
	n -= (len - 1); 
	if (is_prime(n))
		++i;
	n -= (len - 1); 
	if (is_prime(n))
		++i;

	return i;
}

int main()
{
	int i, total_primes = 0;
	float ratio;

	init_sieve();
	for (i = 3; ; i += 2)
	{
		total_primes += num_primes_corners(i);
		ratio = total_primes / (float)(2 * i - 1);
		if (ratio < 0.10f)
			break;
	}

	printf("%d", i);
	return 0;
}