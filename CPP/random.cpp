const int minRand = 1;
const int maxRand = 100;

default_random_engine generator;
uniform_int_distribution<ll> distribution(minRand, maxRand);

int someRand = distribution(generator);
