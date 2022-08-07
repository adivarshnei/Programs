#include <stdio.h>
#include <stdlib.h>

enum Boolean {
	TRUE,
	FALSE
};

struct Process {
	int burst;
	int arrival;
	int finish;
	int tat;
	int wait;
	int priority;
	int time_left_to_exec;
	enum Boolean in_ready_queue;
	struct Process * (*init_process) (struct Process *);
	void (*print_process) (struct Process *);
	void (*calc_tat_wait) (struct Process *);
};

struct Node {
	struct Process process;
	struct Node * next;
	struct Node * prev;
};

int context_switch = 0;
struct Node* processes = NULL;
struct Node* job_queue = NULL;
struct Node* ready_queue = NULL;

void display(struct Node* list) {
	struct Node* temp = list;

	if (temp == NULL) {
      printf("\nNo Elements in list\n");
   } else if (temp->next == NULL) {
      printf("\nElements start to end: ");
      printf("\n%d", temp->process.burst);
      printf("\nElements end to start: ");
      printf("\n%d", temp->process.burst);
      printf("\n");
   } else {
      printf("\nElements start to end: ");
      printf("\n%d", temp->process.burst);

      while (temp->next != NULL) {
         temp = temp->next;
         printf("->%d", temp->process.burst);
      }

      printf("\nElements end to start: ");
      printf("\n%d", temp->process.burst);

      while (temp->prev != NULL) {
         temp = temp->prev;
         printf("->%d", temp->process.burst);
      }

      printf("\n");
   }
}

void insert_at_end(struct Node* list, struct Process process) {
	struct Node* new_node;
	struct Node* temp = list;

	new_node = (struct Node * )malloc(sizeof(struct Node));

	new_node->process = process;
	new_node->next=NULL;
   new_node->prev= NULL;

   if(temp==NULL){
		temp = new_node;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}

		temp->next=new_node;
		new_node->prev=temp;
	}
}

int list_size(struct Node * list) 
{
	int size = 0;
	struct Node* temp = list;

	while (temp != NULL) {
		size++;
		temp=temp->next;
	}

	return size;
}

struct Process get_element(struct Node* list, int index) {
	struct Node*temp=list;
	int i=0;

	while(temp!=NULL){
		if(i==index){
			return (temp->process);
		}

		i++;
		list=list->next;
	}
}

void sort_list(struct Node * list){
   struct Node * temp = list;
   struct Node* index = NULL;
   struct Process temp_process;

   if(list==NULL){
      return;
   }else{
      while(temp!=NULL){
         index = temp->next;

         while(index!=NULL) {
            if(temp->process.priority>index->process.priority){
               temp_process = temp->process;
               temp->process = index->process;
               index->process = temp_process;
            }

            index= index->next;
         }

         temp=temp->next;
      }
   }
}

struct Process * Process_init_process(struct Process * this) {
	fprintf(stdout, "Burst: ");
	fscanf(stdin, "%d", &this->burst);

	fprintf(stdout, "Arrival: ");
	fscanf(stdin, "%d", &this->arrival);

	fprintf(stdout, "Priority: ");
	fscanf(stdin, "%d", &this->priority);

	this->time_left_to_exec = this->burst;
}

void Process_print_process(struct Process * this) {
	fprintf(stdout, "%d\t", this->burst);
	fprintf(stdout, "%d\t", this->arrival);
   fprintf(stdout, "%d\t", this->priority);
	fprintf(stdout, "%d\t", this->finish);
	fprintf(stdout, "%d\t", this->tat);
	fprintf(stdout, "%d\n", this->wait);
}

void Process_calc_tat_wait(struct Process * this) {
	this->tat = this->finish - this->arrival;
	this->wait = this->tat - this->burst;
}

struct Process* Process_new() {
	struct Process * process = (struct Process *) malloc(sizeof(struct Process));

	process->burst          = 0;
   process->arrival        = 0;
   process->finish         = 0;
   process->tat            = 0;
   process->wait           = 0;
   process->priority       = 0;
   process->time_left_to_exec = 0;
   process->in_ready_queue   = FALSE;

   process->init_process = Process_init_process;
   process->print_process = Process_print_process;
   process->calc_tat_wait = Process_calc_tat_wait;

   return process;
}

void init_constants() {
	fprintf(stdout, "Context Switch Time: ");
	fscanf(stdin, "%d", &context_switch);
}

void init_processes() {
	int no_of_processes;
	int i;

	fprintf(stdout, "Enter number of processes: ");
	fscanf(stdin, "%d", &no_of_processes);

	for (i = 0; i < no_of_processes; i++) {
		struct Process *process = Process_new();
      struct Process temp = *process;

		fprintf(stdout,  "Enter data for process %d: \n", (i+1));
		process->init_process(process);

      display(job_queue);

		insert_at_end(job_queue, *process);
   // display(job_queue);
      
		// insert_at_end(processes, *process);
	}

   // display(processes);
}

void print_processes(struct Node* list) {
	int i = 0;

	fprintf(stdout, "Bur\tArr\tPri\tFin\tTAT\tWai\n");

   printf("%d", list_size(list));

	for(i = 0; i < list_size(list); i++) {
      struct Process process = get_element(list, i);
		process.print_process(&process);
	}
}

void execute_processes() {
   int time = 0;
   enum Boolean executing = TRUE;
   struct Process* executing_process = NULL;
   int i;

   while(executing == TRUE) {
      int i= 0;

      if(list_size(ready_queue)==0 || executing_process!=NULL){

      }else{
      	int i;

         for(int i = 0; i < list_size(ready_queue); i++) {
         	if(get_element(ready_queue, i).time_left_to_exec > 0) {
               struct Process process = get_element(ready_queue, i);
               executing_process = &process;

               break;
            }
         }
      }

      if(executing_process != NULL){
         executing_process->time_left_to_exec--;

         if(executing_process->time_left_to_exec<=0){
            executing_process->finish=time;
            executing_process=NULL;
            time+=context_switch;
         }
      }

      for(i = 0; i < list_size(job_queue); i++) {
         if(get_element(job_queue, i).arrival - time <= 0 && get_element(job_queue, i).in_ready_queue == FALSE){
            struct Process temp = get_element(job_queue, i);
            insert_at_end(ready_queue, temp);

            temp = get_element(job_queue, i);
            temp.in_ready_queue=TRUE;

            sort_list(ready_queue);
         }
      }

      enum Boolean flag = TRUE;

      for(i = 0; i<list_size(job_queue);i++){
         if(get_element(job_queue,i).time_left_to_exec>0){
            flag=FALSE;
         }
      }

      if(flag==TRUE){
         executing=(executing==TRUE)?FALSE:TRUE;
      }

      time++;
   }

   for(i=0;i<list_size(job_queue);i++){
      struct Process temp = get_element(job_queue, i);
      temp.calc_tat_wait(&temp);
   }
}

int main(int argc, char ** argv) {
	system("cls");

   init_processes();
	init_constants();
   execute_processes();
   print_processes(processes);

   return 0;
}
