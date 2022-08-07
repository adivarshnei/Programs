// Runtime Err

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

struct Problem {
   // std::string code;
   char     code[8];
   long int solutions;
};

int
main(void) {
   int T;
   long int N;

   std::cin >> T;

   for ( int i = 0; i < T; i++ ) {
      std::cin >> N;

      std::vector<Problem>     problems;
      std::vector<std::string> codes;

      for ( int n = 0; n < 3; n++ ) {
         for ( long int j = 0; j < N; j++ ) {
            Problem problem;

            // std::getline(std::cin, problem.code, ' ');
            std::cin >> problem.code;
            std::cin >> problem.solutions;

            problems.push_back(problem);
            codes.push_back(problem.code);
         }
      }

      std::vector<long int> counts;

      std::sort(codes.begin(), codes.end());
      int no_of_codes = std::unique(codes.begin(), codes.end()) - codes.begin();

      for ( int k = 0; k < no_of_codes; k++ ) {
         long int count = 0;

         // std::string test_code = problems.back().code;
         char test_code[8];
         strcpy(test_code, problems.back().code);

         for ( int l = problems.size() - 1; l >= 0; l-- ) {
            // if ( test_code == problems.at(l).code ) {
            if ( strcmp(test_code, problems.at(l).code) == 0 ) {
               count += problems.at(l).solutions;
               problems.erase(problems.begin() + l);
            }
         }

         counts.push_back(count);
      }

      std::sort(counts.begin(), counts.end(),
                [](const int& a, const int& b) -> bool {
                   return a < b;
                });

      for ( int m = 0; m < counts.size(); m++ ) {
         std::cout << counts.at(m) << " ";
      }

      std::cout << std::endl;
   }

   return 0;
}
