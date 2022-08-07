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
#include <ctype.h>

#define NON_DIGIT_INPUT_ERR -1

#define MAX_K(a, b) a + b + 1

using namespace std;

const long long int MOD = pow(10, 8) + 7;
const int SLOT_LIM[2] = {1, 50};
const long long int YEAR_LIM[2] = {1, (long long int) pow(10, 9)};

template <typename Type>
inline void limitValue(Type& value,
                       const Type lowerLimit,
                       const Type upperLimit) {
   value = (value > upperLimit) ? upperLimit : value;
   value = (value < lowerLimit) ? lowerLimit : value;
}

class Data {
private:
   int initTax;
   int slot1;
   int slot2;
   int K;
   long long int N;

   long long int* Tax;

public:
   Data() : initTax(2), slot1(0), slot2(0), K(0), N(0) { }
   ~Data() { }

   void limitValues() {
      limitValue<int>(this->slot1, SLOT_LIM[0], SLOT_LIM[1]);
      limitValue<int>(this->slot2, SLOT_LIM[0], SLOT_LIM[1]);
      limitValue<int>(this->K, SLOT_LIM[0], MAX_K(this->slot1, this->slot2));
      limitValue<long long int>(this->N, YEAR_LIM[0], YEAR_LIM[1]);
   }

   void getData() {
      long long int taxArrayLim;
      int inputChk[] = {0, 0, 0, 0};

      cout << "Enter Data: " << endl;

      try {
         cout << "Enter time period of Slot 1 (Between 1 and 50): ";
         inputChk[0] = scanf("%d", &this->slot1);
         cout << "Enter time period of Slot 2 (Between 1 and 50): ";
         inputChk[1] = scanf("%d", &this->slot2);
         cout << "Enter value of parameter K (Between 1 and slot1 + slot2 + "
                 "1)): ";
         inputChk[2] = scanf("%d", &this->K);
         cout << "Enter value of parameter N (Between 1 and 10 ^ 9): ";
         inputChk[3] = scanf("%lld", &this->N);

         if (inputChk[0] == 0 || inputChk[1] == 0 || inputChk[2] == 0 ||
             inputChk[3] == 0) {
            throw NON_DIGIT_INPUT_ERR;
         }
      } catch (int errCode) {
         if (errCode == NON_DIGIT_INPUT_ERR) {
            cerr << endl << endl << "Non Digit Entry" << endl;
            exit(1);
         }
      }

      this->limitValues();

      taxArrayLim = (this->N > MAX_K(this->slot1, this->slot2))
                        ? this->N
                        : MAX_K(this->slot1, this->slot2);

      this->Tax = new long long int[taxArrayLim];

      for (int i = 0; i < taxArrayLim; i++) {
         this->Tax[i] = 0;
      }
   }

   void showData() const {
      cout << endl << "Values being used: " << endl;
      cout << "Initial Tax Amount: " << this->initTax << endl;
      cout << "Years in Slot 1: " << this->slot1 << endl;
      cout << "Years in Slot 2: " << this->slot2 << endl;
      cout << "Parameter K: " << this->K << endl;
      cout << "Parameter N: " << this->N << endl;

      cout << endl
           << "Tax in year " << this->N << " (mod " << MOD
           << ") = " << this->Tax[this->N - 1] % MOD;
   }

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
   system("cls");

   while (1) {
      Data* data = new Data();

      data->getData();
      data->calc();
      data->showData();

      delete data;

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;
      cin.ignore(256, '\n');

      if (shouldRepeat == 1) {
         continue;
      } else {
         cout << endl << "END" << endl;
         break;
      }
   }

   system("pause");
   return 0;
}
