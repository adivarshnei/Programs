#include <iostream>
#include <vector>
#include <algorithm>

class Process {
private:
   int burst;
   int arrival;
   int finish;
   int tat;
   int wait;
   int timeLeftToExec;
   bool inReadyQueue;  
 
public:
   static int contextSwitch;
   
   Process() {
      this->burst = 0;
      this->arrival = 0;
      this->finish = 0;
      this->tat = 0;
      this->wait = 0;
      this->timeLeftToExec = 0;
      this->inReadyQueue = false;
   }
   
   void initProcess() {
      std::cout << "Burst: ";
      std::cin >> this->burst;
      
      std::cout << "Arrival: ";
      std::cin >> this->arrival;
      
      this->timeLeftToExec = this->burst;
   }
   
   static void initConstants() {
      std::cout << "Context Switch: ";
      std::cin >> Process::contextSwitch;
   }
   
   void printProcess() const {
      std::cout << this->burst << "\t";
      std::cout << this->arrival << "\t";
      std::cout << this->finish << "\t";
      std::cout << this->tat << "\t";
      std::cout << this->wait << "\n";
   }
   
   void calcTatWait() {
      this->tat = this->finish - this->arrival;
      this->wait = this->tat - this->burst;
   }
   
   int getBurst() {
      return this->burst;
   }
   
   int getArrival() {
      return this->arrival;
   }
   
   int getFinish() {
      return this->finish;
   }
   
   int getTat() {
      return this->tat;
   }
   
   int getWait() {
      return this->wait;
   }
   
   bool getInReadyQueue() {
      return this->inReadyQueue;
   }
   
   int getTimeLeftToExec() {
      return this->timeLeftToExec;
   }
   
   void setFinish(int finish) {
      this->finish = finish;
   }
   
   void setInReadyQueue(bool inReadyQueue) {
      this->inReadyQueue = inReadyQueue;
   }
   
   void setTimeLeftToExec(int timeLeftToExec) {
      this->timeLeftToExec = timeLeftToExec;
   }
   
};

int Process::contextSwitch = 0;

std::vector<Process*> jobQueue;
std::vector<Process*> readyQueue;

void initProcesses() {
   int noOfProcesses;
   
   std::cout << "Enter number of processes: ";
   std::cin >> noOfProcesses;
   
   for (int i = 0; i < noOfProcesses; i++) {
      std::cout << "Enter data for processes " << (i + 1) << std::endl;
      
      Process process = Process();
      process.initProcess();
      
      jobQueue.push_back(&process);      
   }
}

void printProcesses(std::vector<Process*> processList) {
   std::cout << "Bur\tArr\tFin\tTAT\tWai" << std::endl;
   
   for (Process *process : processList) {
      process->printProcess();
   }
}

void executeProcesses() {
   int time = 0;
   bool executing = true;
   Process *executingProcess = NULL;
   
   while (executing) {
      if (!(readyQueue.size() == 0 || executingProcess != NULL)) {
         for (Process *process : readyQueue) {
            if (process->getTimeLeftToExec() > 0) {
               executingProcess = process;
               break;
            }
         }
      }
      
      if (executingProcess != NULL) {
         executingProcess->setTimeLeftToExec(executingProcess->getTimeLeftToExec() - 1);
         
         if (executingProcess->getTimeLeftToExec() <= 0) {
            executingProcess->setFinish(time);
            executingProcess = NULL;
            time += Process::contextSwitch;
         }
      }
      
      for (Process *process : jobQueue) {
         if(process->getArrival() - time <= 0 && !process->getInReadyQueue()) {
            readyQueue.push_back(process);
            process->setInReadyQueue(true);
            
            std::sort(readyQueue.begin(), readyQueue.end(), [](const auto& p1, const auto& p2) {
               return p1->getBurst() > p2->getBurst();
            });
         }
      }
      
      bool flag = true;
      
      for (Process *process : jobQueue) {
         if (process->getTimeLeftToExec() > 0) {
            flag = false;
         }
      }
      
      if (flag) {
         executing = !executing;
      }
      
      time++;
   }
   
   for (Process *process : jobQueue) {
      process->calcTatWait();
   }
}

void printAverages() {
   float avgBurst = 0;
   float avgArrival = 0;
   float avgFinish = 0;
   float avgTat = 0;
   float avgWait = 0;
   
   for (Process *process : jobQueue) {
      avgBurst += process->getBurst();
      avgArrival += process->getArrival();
      avgFinish += process->getFinish();
      avgTat += process->getTat();
      avgWait += process->getWait();
   }
   
   avgBurst /= (float) jobQueue.size();
   avgArrival /= (float) jobQueue.size();
   avgFinish /= (float) jobQueue.size();
   avgTat /= (float) jobQueue.size();
   avgWait /= (float) jobQueue.size();
   
   std::cout << avgBurst << "\t";
   std::cout << avgArrival << "\t";
   std::cout << avgFinish << "\t";
   std::cout << avgTat << "\t";
   std::cout << avgWait << "\t";
}

int main(int argc, char ** argv) {
   initProcesses();
   Process::initConstants();
   executeProcesses();
   printProcesses(jobQueue);
   printAverages();
}