# Round Robin

import os


class Process:
    time_quantum = 0
    context_switch = 0

    def __init__(self):
        self.burst = 0
        self.time_left_to_exec = 0
        self.arrival = 0
        self.finish = 0
        self.tat = 0
        self.wait = 0
        self.in_ready_queue = False

    @staticmethod
    def init_constants():
        Process.time_quantum = int(input("Time Quantum: "))
        Process.context_switch = int(input("Context Switch Time: "))

    def init_process(self):
        self.burst = int(input("Burst: "))
        self.arrival = int(input("Arrival: "))
        self.time_left_to_exec = self.burst

    def print_process(self):
        print(f"{self.burst}\t", end="")
        print(f"{self.arrival}\t", end="")
        print(f"{self.finish}\t", end="")
        print(f"{self.tat}\t", end="")
        print(f"{self.wait}\t")


processes = list()
job_queue = list()
ready_queue = list()
# Process.init_constants = staticmethod(Process.init_constants)


def init_processes():
    no_of_processes = int(input("Enter number of processes: "))

    for i in range(no_of_processes):
        print(f"Enter data for process {i + 1}: ")
        process = Process()
        process.init_process()

        job_queue.append(process)
        processes.append(process)


def print_processes(process_list):
    print(f"Quantum: {Process.time_quantum}")
    print("Bur\tArr\tFin\tTAT\tWai")

    for _, process in enumerate(process_list):
        process.print_process()


def execute_processes():
    time = 0
    executing = True
    executing_process = None

    quantum_time_left = Process.time_quantum

    while executing:
        if len(ready_queue) == 0 or executing_process != None:
            pass
        else:
            for _, process in enumerate(ready_queue):
                if process.time_left_to_exec > 0:
                    executing_process = process
                    break
            print()

        if executing_process is not None:
            executing_process.time_left_to_exec -= 1
            quantum_time_left -= 1

            if executing_process.time_left_to_exec <= 0:
                temp = executing_process

                executing_process.finish = time
                quantum_time_left = Process.time_quantum

                for i, _ in enumerate(job_queue):
                    if job_queue[i] == executing_process:
                        executing_process = job_queue[(i + 1) % len(job_queue)]
                        time += Process.context_switch
                        break

                ready_queue.remove(temp)
                job_queue.remove(temp)

            if quantum_time_left <= 0:
                quantum_time_left = Process.time_quantum

                for i, _ in enumerate(job_queue):
                    if job_queue[i] == executing_process:
                        executing_process = job_queue[(i + 1) % len(job_queue)]
                        time += Process.context_switch
                        break

        if not job_queue:
            executing = not executing

        for _, process in enumerate(job_queue):
            if process.arrival - time <= 0 and not process.in_ready_queue:
                ready_queue.append(process)
                process.in_ready_queue = True

        time += 1

    for _, process in enumerate(processes):
        process.tat = process.finish - process.arrival
        process.wait = process.tat - process.burst


def print_averages():
    avg_burst = 0
    avg_arrival = 0
    avg_finish = 0
    avg_tat = 0
    avg_wait = 0

    for _, process in enumerate(processes):
        avg_burst += process.burst
        avg_arrival += process.arrival
        avg_finish += process.finish
        avg_tat += process.tat
        avg_wait += process.wait

    avg_burst /= len(processes)
    avg_arrival /= len(processes)
    avg_finish /= len(processes)
    avg_tat /= len(processes)
    avg_wait /= len(processes)

    print(f"{avg_burst:.2f}\t", end="")
    print(f"{avg_arrival:.2f}\t", end="")
    print(f"{avg_finish:.2f}\t", end="")
    print(f"{avg_tat:.2f}\t", end="")
    print(f"{avg_wait:.2f}\t", end="")

    print(f"\nAverage TAT: {avg_tat:.2f}")
    print(f"\nAverage Wait: {avg_wait:.2f}")


def main():
    os.system("cls")

    init_processes()
    Process.init_constants()
    execute_processes()
    print_processes(process_list=processes)
    print_averages()


if __name__ == "__main__":
    main()
