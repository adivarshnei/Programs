# First Come First Serve

import os


class Process:
    context_switch = 0

    def __init__(self):
        self.burst = 0
        self.time_left_to_exec = 0
        self.arrival = 0
        self.time_left_to_arrive = 0
        self.finish = 0
        self.tat = 0
        self.wait = 0

    def init_process(self):
        self.burst = int(input("Burst: "))
        self.arrival = int(input("Arrival: "))
        self.time_left_to_exec = self.burst
        self.time_left_to_arrive = self.arrival

    @staticmethod
    def init_constants():
        Process.context_switch = int(input("Context Switch Time: "))

    def print_process(self):
        print(f"{self.burst}\t", end="")
        print(f"{self.arrival}\t", end="")
        print(f"{self.finish}\t", end="")
        print(f"{self.tat}\t", end="")
        print(f"{self.wait}\t")


job_queue = list()
# Process.init_constants = staticmethod(Process.init_constants)


def init_processes():
    no_of_processes = int(input("Enter number of processes: "))

    for i in range(no_of_processes):
        print(f"Enter data for process {i + 1}: ")
        process = Process()
        process.init_process()

        job_queue.append(process)


def print_processes():
    print("Bur\tArr\tFin\tTAT\tWai")

    for _, process in enumerate(job_queue):
        process.print_process()


def execute_processes():
    time = 0
    executing = True
    index = 0

    while executing:
        time += 1

        if job_queue[index].time_left_to_arrive <= 0:
            job_queue[index].time_left_to_exec -= 1

            if job_queue[index].time_left_to_exec == 0:
                job_queue[index].finish = time
                index += 1
                time += Process.context_switch

        for _, process in enumerate(job_queue):
            process.time_left_to_arrive -= 1

        if index == len(job_queue):
            executing = not executing

    for _, process in enumerate(job_queue):
        process.tat = process.finish - process.arrival
        process.wait = process.tat - process.burst


def print_averages():
    avg_burst = 0
    avg_arrival = 0
    avg_finish = 0
    avg_tat = 0
    avg_wait = 0

    for _, process in enumerate(job_queue):
        avg_burst += process.burst
        avg_arrival += process.arrival
        avg_finish += process.finish
        avg_tat += process.tat
        avg_wait += process.wait

    avg_burst /= len(job_queue)
    avg_arrival /= len(job_queue)
    avg_finish /= len(job_queue)
    avg_tat /= len(job_queue)
    avg_wait /= len(job_queue)

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
    print_processes()
    print_averages()


if __name__ == "__main__":
    main()
