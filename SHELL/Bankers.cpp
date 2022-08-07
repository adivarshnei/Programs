#include <iostream>
#include <cstring>

#define M 3
#define N 5

struct Constants {
   int process_no;
   int available[M];
   int request[M];
   int allocation[N][M];
   int max_matrix[N][M];
};

Constants constants ={
   .process_no = 1,
   .available  = {3, 3, 2},
   .request    = {1, 0, 2},
   .allocation = {{ 0, 1, 0 },
                  { 2, 0, 0 },
                  { 3, 0, 2 },
                  { 2, 1, 1 },
                  { 0, 0, 2 } },
   .max_matrix = {{ 7, 5, 3 },
                  { 3, 2, 2 },
                  { 9, 0, 2 },
                  { 2, 2, 2 },
                  { 4, 3, 3 } },
};

void add_arrays(int*, int*);

class Safety {
private:
   int  work[M];
   bool finish[N];
   int  safe_sequence[N];
   int  available[M];
   int  allocation[N][M];
   int  need[N][M];

public:
   Safety(int allocation[N][M], int available[M]) {
      memcpy(this->work, constants.available, sizeof constants.available);
      memcpy(this->available, constants.available, sizeof constants.available);
      memcpy(this->allocation, constants.allocation,
             sizeof constants.allocation);

      for ( int i = 0; i < N; i++ ) {
         this->finish[i] = false;
      }

      for ( int i = 0; i < N; i++ ) {
         for ( int j = 0; j < M; j++ ) {
            this->need[i][j] =
               constants.max_matrix[i][j] - constants.allocation[i][j];
         }
      }
   }

   bool need_work_comparison(int i) {
      for ( int j = 0; j < M; j++ ) {
         if ( this->need[i][j] > this->work[j] ) {
            return false;
         }
      }

      return true;
   }

   bool is_false_in_finish() {
      for ( int i = 0; i < N; i++ ) {
         if ( this->finish[i] == false ) {
            return true;
         }
      }

      return false;
   }

   void print_safe_sequence() const {
      for ( int i = 0; i < N; i++ ) {
         std::cout << this->safe_sequence[i] << "\t";
      }

      std::cout << std::endl;
   }

   bool execute_algorithm() {
      int  i               = 0;
      int  iteration_count = 0;
      int  safe_index      = 0;
      bool is_safe         = true;

      while ( true ) {
         if ( ! this->finish[i] && this->need_work_comparison(i) ) {
            add_arrays(this->work, this->allocation[i]);
            this->finish[i]                   = true;
            this->safe_sequence[safe_index++] = i;

            iteration_count -= 1;
         }

         i += 1;
         iteration_count += 1;

         if ( i == N && this->is_false_in_finish() ) {
            i = 0;
         }

         if ( ! this->is_false_in_finish() ) {
            break;
         }

         if ( iteration_count >= N ) {
            std::cout << "System is not in safe state" << std::endl;
            break;
         }
      }

      is_safe = true;

      if ( this->is_false_in_finish() ) {
         is_safe = false;
      }

      if ( is_safe ) {
         std::cout << "System is in safe state" << std::endl;
         this->print_safe_sequence();
      }

      return is_safe;
   }
};

class Request {
private:
   int allocation[N][M];
   int available[M];
   int request[M];
   int process_no;

public:
   Request(int allocation[N][M],
           int available[M],
           int request[M],
           int process_no)
      : process_no(process_no) {
      memcpy(this->allocation, constants.allocation,
             sizeof constants.allocation);
      memcpy(this->available, constants.available, sizeof constants.available);
      memcpy(this->request, constants.request, sizeof constants.request);
   }

   bool request_available_compare() {
      for ( int i = 0; i < M; i++ ) {
         if ( this->request[i] > this->available[i] ) {
            return false;
         }
      }

      return true;
   }

   bool execute_algorithm() {
      bool is_safe = true;

      if ( ! this->request_available_compare() ) {
         return false;
      }

      for ( int i = 0; i < M; i++ ) {
         // std::cout << available[i] << " " << request[i];
         this->available[i] -= this->request[i];
         this->allocation[this->process_no][i] += this->request[i];
         // std::cout << available[i] << " " << request[i];
      }

      Safety safety = Safety(this->allocation, this->available);
      is_safe       = safety.execute_algorithm();

      if ( is_safe ) {
         std::cout << "Approving request by adding it to allocation table"
                   << std::endl;

         memcpy(constants.allocation, this->allocation,
                sizeof this->allocation);
         memcpy(constants.available, this->available, sizeof this->available);
      } else {
         std::cout << "Request cannot be granted" << std::endl;
      }

      return is_safe;
   }
};

void
add_arrays(int array_one[M], int array_two[M]) {
   for ( int i = 0; i < M; i++ ) {
      array_one[i] += array_two[i];
   }
}

void
print_2d_matrix(int matrix[N][M]) {
   for ( int i = 0; i < N; i++ ) {
      for ( int j = 0; j < M; j++ ) {
         std::cout << matrix[i][j] << "\t";
      }

      std::cout << std::endl;
   }
}

void
print_data() {
   std::cout << std::endl << "Allocation Table:" << std::endl;
   print_2d_matrix(constants.allocation);
   std::cout << std::endl << "Max Table:" << std::endl;
   print_2d_matrix(constants.max_matrix);
   std::cout << std::endl << "Available Table: " << std::endl;

   for ( int i = 0; i < M; i++ ) {
      std::cout << constants.available[i] << "\t";
   }

   std::cout << std::endl;
}

int
main(void) {
   system("pause");
   Safety safety = Safety(constants.allocation, constants.available);
   safety.execute_algorithm();

   Request request = Request(constants.allocation, constants.available,
                             constants.request, constants.process_no);
   request.execute_algorithm();

   print_data();

   return 0;
}
