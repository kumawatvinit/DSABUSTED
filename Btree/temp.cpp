#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Generates a random prime number in the range from 2 to n (inclusive)
int randomPrime(int n) {
  // Seed the random number generator
  std::srand(std::time(nullptr));

  while (true) {
    // Generate a random number in the range [0, RAND_MAX]
    int candidate = std::rand();

    // Scale and shift the random number to the range [2, n]
    candidate = (candidate % (n - 2 + 1)) + 2;

    // Check if the number is prime
    bool isPrime = true;
    for (int i = 2; i * i <= candidate; i++) {
      if (candidate % i == 0) {
        isPrime = false;
        break;
      }
    }

    // If the number is prime, return it
    if (isPrime) return candidate;
  }
}





int main()
{
    int prime = randomPrime(100000); // Generates a random prime number in the range [2, 100]
    cout << prime << endl;
    
    return 0;
}