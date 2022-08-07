#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

class Process {
private:
   int burst;
   int arrival;
   int finish;
   int tat;
   int wait;
   int priority;

   int  timeLeftToExec;
   bool inReadyQueue;

public:
   static int contextSwitch;

   Process() {
      this->burst          = 0;
      this->arrival        = 0;
      this->finish         = 0;
      this->tat            = 0;
      this->wait           = 0;
      this->priority       = 0;
      this->timeLeftToExec = 0;
      this->inReadyQueue   = false;
   }

   static void initConstants() {
      std::cout << "Context Switch Time: ";
      std::cin >> contextSwitch;
   }

   void initProcess() {
      std::cout << "Burst: ";
      std::cin >> this->burst;

      std::cout << "Arrival: ";
      std::cin >> this->arrival;

      std::cout << "Priority: ";
      std::cin >> this->priority;

      this->timeLeftToExec = this->burst;
   }

   void printProcess() const {
      std::cout << this->burst << "\t";
      std::cout << this->arrival << "\t";
      std::cout << this->finish << "\t";
      // std::cout << this->priority << "\t";
      std::cout << this->tat << "\t";
      std::cout << this->wait << std::endl;
   }

   int getBurst() { return this->burst; }

   int getArrival() { return this->arrival; }

   int getFinish() { return this->finish; }

   void setFinish(int finish) { this->finish = finish; }

   int getTat() { return this->tat; }

   int getWait() { return this->wait; }

   int getPriority() { return this->priority; }

   int getTimeLeftToExec() { return this->timeLeftToExec; }

   void setTimeLeftToExec(int timeLeftToExec) {
      this->timeLeftToExec = timeLeftToExec;
   }

   bool getInReadyQueue() { return this->inReadyQueue; }

   void setInReadyQueue(bool inReadyQueue) {
      this->inReadyQueue = inReadyQueue;
   }

   void calcTatWait() {
      this->tat  = this->finish - this->arrival;
      this->wait = this->tat - this->burst;
   }
};

int Process::contextSwitch = 0;

std::vector< Process* > processes;
std::vector< Process* > jobQueue;
std::vector< Process* > readyQueue;

void
initProcesses() {
   int noOfProcesses;

   std::cout << "Enter number of processes: ";
   std::cin >> noOfProcesses;

   for ( int i = 0; i < noOfProcesses; i++ ) {
      Process* process;

      std::cout << "Enter data for process " << i + 1 << ": " << std::endl;
      process = new Process();
      process->initProcess();

      jobQueue.push_back(process);
      processes.push_back(process);
   }
}

void
printProcesses(std::vector< Process* > processList) {
   std::cout << "Bur\tArr\tFin\tTAT\tWai" << std::endl;

      for ( unsigned int i = 0; i < jobQueue.size(); i++ ) {
         processList.at(i)->printProcess();
      }
}

void
executeProcesses() {
   int      time             = 0;
   bool     executing        = true;
   Process* executingProcess = NULL;

      while ( executing ) {
            if ( readyQueue.size() == 0 || executingProcess != NULL ) {
            } else {
                  for ( unsigned int i = 0; i < readyQueue.size(); i++ ) {
                        if ( readyQueue.at(i)->getTimeLeftToExec() > 0 ) {
                           executingProcess = readyQueue.at(i);
                           break;
                     }
                  }
            }

            if ( executingProcess != NULL ) {
               executingProcess->setTimeLeftToExec(
                  executingProcess->getTimeLeftToExec() - 1);

                  if ( executingProcess->getTimeLeftToExec() <= 0 ) {
                     executingProcess->setFinish(time);
                     executingProcess = NULL;
                     time += Process::contextSwitch;
               }
         }

            for ( unsigned int i = 0; i < jobQueue.size(); i++ ) {
                  if ( jobQueue.at(i)->getArrival() - time <= 0 &&
                       ! jobQueue.at(i)->getInReadyQueue() ) {
                     readyQueue.push_back(jobQueue.at(i));
                     jobQueue.at(i)->setInReadyQueue(true);

                     std::sort(readyQueue.begin(), readyQueue.end(),
                               [](const auto& p1, const auto& p2) {
                                  return p1->getPriority() < p2->getPriority();
                               });
               }
            }

         bool flag = true;

            for ( unsigned int i = 0; i < jobQueue.size(); i++ ) {
                  if ( jobQueue.at(i)->getTimeLeftToExec() > 0 ) {
                     flag = false;
               }
            }

            if ( flag ) {
               executing = not executing;
         }

         time++;
      }

      for ( unsigned int i = 0; i < jobQueue.size(); i++ ) {
         jobQueue.at(i)->calcTatWait();
      }
}

void
printAverages() {
   float avgBurst   = 0;
   float avgArrival = 0;
   float avgFinish  = 0;
   float avgTat     = 0;
   float avgWait    = 0;

      for ( unsigned int i = 0; i < processes.size(); i++ ) {
         avgBurst += jobQueue.at(i)->getBurst();
         avgArrival += jobQueue.at(i)->getArrival();
         avgFinish += jobQueue.at(i)->getFinish();
         avgTat += jobQueue.at(i)->getTat();
         avgWait += jobQueue.at(i)->getWait();
      }

   avgBurst /= processes.size();
   avgArrival /= processes.size();
   avgFinish /= processes.size();
   avgTat /= processes.size();
   avgWait /= processes.size();

   std::cout << std::setprecision(2) << avgBurst << "\t";
   std::cout << std::setprecision(2) << avgArrival << "\t";
   std::cout << std::setprecision(2) << avgFinish << "\t";
   std::cout << std::setprecision(2) << avgTat << "\t";
   std::cout << std::setprecision(2) << avgWait << "\t";

   std::cout << std::endl << "Average TAT: " << avgTat << std::endl;
   std::cout << std::endl << "Avearage Wait: " << avgWait << std::endl;
}

int
main(int argc, char** argv) {
   system("cls");

   initProcesses();
   Process::initConstants();
   executeProcesses();
   printProcesses(processes);
   printAverages();

   return 0;
}
