#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3
#define N 5

enum Boolean {
    TRUE,
    FALSE
};

struct Constants {
    int max_matrix[N][M];
    int allocation[N][M];
    int available[M];
    int request[M];
    int process_no;
};

struct Constants constants = {
    .allocation = { { 0, 1, 0 },
                   { 2, 0, 0 },
                   { 3, 0, 2 },
                   { 2, 1, 1 },
                   { 0, 0, 2 } },
    .max_matrix = { { 7, 5, 3 },
                   { 3, 2, 2 },
                   { 9, 0, 2 },
                   { 2, 2, 2 },
                   { 4, 3, 3 } },
    .available  = { 3, 3, 2 },
    .request    = { 1, 0, 2 },
    .process_no = 1,
};

struct Safety {
    int          work[M];
    enum Boolean finish[N];
    int          safe_sequence[N];
    int          available[M];
    int          allocation[N][M];
    int          need[N][M];

    enum Boolean (*need_work_comparison)(struct Safety*, int);
    enum Boolean (*execute_algorithm)(struct Safety*);
};

enum Boolean
Safety_need_work_comparison(struct Safety* this, int i) {
    int j;

    for ( j = 0; j < M; j++ ) {
        if ( this->need[i][j] > this->work[j] ) {
            return FALSE;
        }
    }

    return TRUE;
}

enum Boolean
Safety_execute_algorithm(struct Safety* this) {
    int i               = 0;
    int time            = 0;
    int iteration_count = 0;
    int safe_index      = 0;

    enum Boolean is_false_in_finish(struct Safety*);

    while ( 1 ) {
        if ( this->finish[i] == FALSE &&
             this->need_work_comparison(this, i) == TRUE ) {
            int j;

            for ( j = 0; j < M; j++ ) {
                this->work[j] += this->allocation[i][j];
            }

            this->finish[i]                   = TRUE;
            this->safe_sequence[safe_index++] = i;
            iteration_count -= 1;
        }

        i += 1;
        iteration_count += 1;

        if ( i == N && is_false_in_finish(this) == TRUE ) {
            i = 0;
        }

        if ( is_false_in_finish(this) == FALSE ) {
            break;
        }

        if ( iteration_count >= N ) {
            fprintf(stdout, "System is not in safe state\n");
            break;
        }

        time++;
    }

    enum Boolean is_safe = TRUE;

    if ( is_false_in_finish(this) == TRUE ) {
        is_safe = FALSE;
    }

    return is_safe;
}

enum Boolean
is_false_in_finish(struct Safety* this) {
    int i;

    for ( i = 0; i < N; i++ ) {
        if ( this->finish[i] == FALSE ) {
            return TRUE;
        }
    }

    return FALSE;
}

struct Safety*
init_safety() {
    struct Safety* safety = ( struct Safety* ) malloc(sizeof(struct Safety));
    int            i;
    int            j;

    memcpy(safety->work, constants.available, sizeof(constants.available));
    memcpy(safety->available, constants.available, sizeof(constants.available));
    memcpy(safety->allocation, constants.allocation,
           sizeof(constants.allocation));

    for ( i = 0; i < N; i++ ) {
        safety->finish[i] = FALSE;
    }

    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < M; j++ ) {
            safety->need[i][j] =
                constants.max_matrix[i][j] - constants.allocation[i][j];
        }
    }

    safety->need_work_comparison = Safety_need_work_comparison;
    safety->execute_algorithm    = Safety_execute_algorithm;

    return safety;
}

struct Request {
    int allocation[N][M];
    int available[M];
    int request[M];
    int process_no;

    enum Boolean (*request_available_compare)(struct Request*);
    enum Boolean (*execute_algorithm)(struct Request*);
};

enum Boolean
Request_request_available_compare(struct Request* this) {
    int j;

    for ( j = 0; j < M; j++ ) {
        if ( this->request[j] > this->available[j] ) {
            return FALSE;
        }
    }

    return TRUE;
}

enum Boolean
Request_execute_algorithm(struct Request* this) {
    int j;

    if ( this->request_available_compare(this) == FALSE ) {
        return FALSE;
    }

    for ( j = 0; j < M; j++ ) {
        this->available[j] -= this->request[j];
        this->allocation[this->process_no][j] += this->request[j];
    }

    struct Safety* safety  = init_safety();
    enum Boolean   is_safe = safety->execute_algorithm(safety);

    if ( is_safe == TRUE ) {
        memcpy(constants.allocation, this->allocation,
               sizeof(this->allocation));
        memcpy(constants.available, this->available, sizeof(this->available));
    } else {
        fprintf(stdout, "Request cannot be granted\n");
    }

    return is_safe;
}

struct Request*
init_request() {
    struct Request* request =
        ( struct Request* ) malloc(sizeof(struct Request));

    memcpy(request->allocation, constants.allocation,
           sizeof(constants.allocation));
    memcpy(request->available, constants.available,
           sizeof(constants.available));
    memcpy(request->request, constants.request, sizeof(constants.request));

    request->process_no = constants.process_no;

    request->request_available_compare = Request_request_available_compare;
    request->execute_algorithm         = Request_execute_algorithm;

    return request;
}

void
print_data() {
    int i;
    int j;

    fprintf(stdout, "\nMax Table: \n");

    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < M; j++ ) {
            fprintf(stdout, "%d\t", constants.max_matrix[i][j]);
        }

        fprintf(stdout, "\n");
    }

    fprintf(stdout, "\nAllocation Table: \n");

    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < M; j++ ) {
            fprintf(stdout, "%d\t", constants.allocation[i][j]);
        }

        fprintf(stdout, "\n");
    }

    fprintf(stdout, "\nAvailable Table: \n");

    for ( i = 0; i < M; i++ ) {
        fprintf(stdout, "%d\t", constants.available[i]);
    }

    fprintf(stdout, "\n");
}

int
main(int argc, char** argv) {
    struct Safety* safety = init_safety();
    int            i;

    print_data();

    if ( safety->execute_algorithm(safety) == TRUE ) {
        fprintf(stdout, "\nSystem is in safe state\n");
    };

    fprintf(stdout, "Request: ");

    for ( i = 0; i < M; i++ ) {
        fprintf(stdout, "%d\t", constants.request[i]);
    }

    fprintf(stdout, "\n");

    struct Request* request = init_request();

    if ( request->execute_algorithm(request) == TRUE ) {
        fprintf(stdout, "Request is granted\n");
    };

    print_data();

    return 0;
}
