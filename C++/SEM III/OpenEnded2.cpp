// Long ago there was a beautiful kingdom in the island of Sona, the golden
// island, deep inside Africa. The trees in Sona Island are made of gold and
// farmers are the richest group of people and are also heavy tax payers. As you
// know that price of gold increases every year, the minister of Sona has
// proposed the following tax policy.

// Pay initial 2 Tax units of gold in the first year.

// In each of the next slot1 years, pay one unit of gold more than the previous
// year.

// In each of the next slot2 years, pay double the units of gold of the previous
// year.

// In each of the following years, pay number of gold units equal to the product
// of the number of units paid in K recent years.

// Design a system using C++ that will help minister of Sona for tax assessment.

#include <iostream>
#include <stdlib.h>
#include <math.h>

const long long int MOD = pow(10, 8) + 7;
#define MAX_N 101

using namespace std;

class Data {
private:
   int initTax;
   int slot1;
   int slot2;
   int K;
   long long int N;

   long long int* Tax;

public:
   void getData() {
      cin >> this->initTax >> this->slot1 >> this->slot2 >> this->K >> this->N;

      this->Tax = (long long int*) malloc(sizeof(long long int) * MAX_N);

      for (int i = 0; i < MAX_N; i++) {
         Tax[i] = 0;
      }
   }

   void showData() const { cout << Tax[this->N - 1] % MOD; }

   void calc() {
      int temp = 1;
      int index = 0;
      long long int product;

      this->Tax[index] = this->initTax;
      index++;

      while (temp <= this->slot1) {
         this->Tax[index] = this->Tax[index - 1] + 1;
         index++;
         temp++;
      }

      while (temp <= this->slot1 + this->slot2) {
         this->Tax[index] = this->Tax[index - 1] * 2;
         index++;
         temp++;
      }

      while (temp < this->N + 1) {
         int i = 0;
         product = 1;

         while (i < this->K) {
            product *= (this->Tax[index - this->K + i]) % MOD;
            i++;

            product %= MOD;
         }

         this->Tax[index] = product;
         index++;
         temp++;
      }
   }
};

int shouldRepeat;

int main(void) {
   int t;
   cin >> t;

   while (t--) {
      Data data;

      data.getData();
      data.calc();
      data.showData();
   }

   return 0;
}
