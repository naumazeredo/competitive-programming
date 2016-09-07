// Sieve of Erasthotenes
for (ll i = 2; i <= N; ++i) if (!p[i]) {
  for (ll j = i*i; j <= N; j+=i) p[j]=1;
  primes.pb(i);
}
