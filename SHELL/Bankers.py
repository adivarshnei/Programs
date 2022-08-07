# Banker's Algorithm

import copy

allocation = [
    [0, 1, 0],
    [2, 0, 0],
    [3, 0, 2],
    [2, 1, 1],
    [0, 0, 2],
]

max_matrix = [
    [7, 5, 3],
    [3, 2, 2],
    [9, 0, 2],
    [2, 2, 2],
    [4, 3, 3],
]

available = [3, 3, 2]

m = len(allocation[0])
n = len(allocation)

request = [1, 0, 2]


class Safety:
    def __init__(self, allocation: list, available: list) -> None:
        self.work = copy.deepcopy(available)
        self.finish = [False for _ in range(n)]
        self.safe_sequence = list()

        self.available = copy.deepcopy(available)
        self.allocation = copy.deepcopy(allocation)

        self.need = [
            [(max_matrix[i][j] - allocation[i][j]) for j in range(m)]
            for i in range(n)
        ]

    def need_work_comparison(self, i: int) -> bool:
        for j in range(m):
            if self.need[i][j] > self.work[j]:
                return False

        return True

    def execute_algorithm(self) -> bool:
        i = 0
        time = 0
        iteration_count = 0

        while True:
            if not self.finish[i] and self.need_work_comparison(i):
                self.work = add_lists(self.work, self.allocation[i])
                self.finish[i] = True
                self.safe_sequence.append(i)

                iteration_count -= 1

            i += 1
            iteration_count += 1

            if i == n and False in self.finish:
                i = 0

            if not False in self.finish:
                break

            if iteration_count >= n:
                print("System is not in safe state")
                break

            time += 1

        is_safe = True

        if False in self.finish:
            is_safe = False

        if is_safe:
            print("System is in safe state")
            print(self.safe_sequence)

        return is_safe


class Request:
    def __init__(
        self, allocation: list, available: list, request: list, process_no: int
    ) -> None:
        self.allocation = copy.deepcopy(allocation)
        self.available = copy.deepcopy(available)
        self.request = copy.deepcopy(request)
        self.process_no = process_no

    def request_available_compare(self) -> bool:
        for j in range(m):
            if self.request[j] > self.available[j]:
                return False

        return True

    def execute_algorithm(self) -> bool:
        if not self.request_available_compare():
            return False

        for j in range(m):
            self.available[j] -= self.request[j]
            self.allocation[self.process_no][j] += self.request[j]

        print("If the Request is granted, ", end="")

        is_safe = Safety(
            allocation=self.allocation, available=self.available
        ).execute_algorithm()

        if is_safe:
            print("Approving request by adding it to allocation table")

            global allocation
            allocation = copy.deepcopy(self.allocation)

            global available
            available = copy.deepcopy(self.available)
        else:
            print("Request cannot be granted")

        return is_safe


def add_lists(input_list_one: list, input_list_two: list) -> list:
    result = list()

    for i in range(len(input_list_one)):
        result.append(input_list_one[i] + input_list_two[i])

    return result


def print_2d_matrix(matrix: list) -> None:
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            print(f"{matrix[i][j]}\t", end="")

        print()


def print_data() -> None:
    print(f"\nAllocation Table:")
    print_2d_matrix(allocation)
    print(f"\nMax Table:")
    print_2d_matrix(max_matrix)
    print(f"\nAvailable Table:")

    for i in range(len(available)):
        print(f"{available[i]}\t", end="")


def main() -> None:
    Safety(allocation=allocation, available=available).execute_algorithm()

    Request(
        allocation=allocation,
        available=available,
        request=request,
        process_no=1,
    ).execute_algorithm()

    print_data()


if __name__ == "__main__":
    main()
