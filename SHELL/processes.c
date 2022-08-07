// #include <stdio.h>
// #include <sys/resource.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include <stdlib.h>

// unsigned long int count = 0;

// int main() {
//    // struct rlimit rl;
//    unsigned long int i = 0;

//    // getrlimit(RLIMIT_NPROC, &rl);

//    // printf("%lu\n", rl.rlim_cur);

//    // for (i = 0; i < rl.rlim_cur; i++) {
//    // if (fork() == 0) {
//    // count += 1;
//    // printf("%lu\n", count);

//    // printf("[son] pid %d from [parent] pid %d\n", getpid(), getppid());
//    // exit(0);
//    // }
//    // printf("%d", i);
//    // }

//    // printf("%lu\n", i);

//    // for (int i = 0; i < 5; i++) {
//    // wait(NULL);
//    // }

//    while (fork() == 0) {
//       count += 1;

//       // FILE* fp = NULL;
//       // if (fp == NULL) {
//       //    fp = fopen("process.txt", "w");
//       // } else {
//       //    fp = freopen("process.txt", "w", fp);
//       // }

//       // fprintf(fp, "%lu\n", count);

//       // fclose(fp);

//       // system("clear");
//       // printf("%d", count);
//    }

//    printf("%d", count);

//    // system("cat process.txt");
// }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   int fd[2];
   int depth = 0;
   int i;

   pipe(fd);

   for(i=0;i<atoi(argv[1]);i++){
      if (fork() == 0) {
         write(fd[1], &i, 1);
	 depth+=1;
      }
   }

   close(fd[1]);

   if(depth==0){
      i = 0;
      while(read(fd[0], &depth, 1) != 0){
         i += 1;
      }

      printf("%d total processes spawned\n", i);
   }

   return 0;
}
