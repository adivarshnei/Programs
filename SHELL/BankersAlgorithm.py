# import copy


# # Resource Types
# m = 3  # Input
# n = 5  # Input

# initial_available = [0 for _ in range(m)]  # Input
# # available = [0 for _ in range(m)]
# # max = [[0 for _ in range(m)] for _ in range(n)]
# # allocation = [[0 for _ in range(m)] for _ in range(n)]
# max_matrix = [
#     # [0, 0, 1, 2],
#     # [2, 7, 5, 0],
#     # [6, 6, 5, 6],
#     # [4, 3, 5, 4],
#     # [0, 6, 5, 2],
#     [0, 1, 0],
#     [2, 0, 0],
#     [3, 0, 2],
#     [2, 1, 1],
#     [0, 0, 2],
# ]

# allocation = [
#     # [0, 0, 1, 2],
#     # [2, 0, 0, 0],
#     # [0, 0, 3, 4],
#     # [2, 3, 5, 4],
#     # [0, 3, 3, 2],
#     [7, 5, 3],
#     [3, 2, 2],
#     [9, 0, 2],
#     [2, 2, 2],
#     [4, 3, 3],
# ]

# # available = [2, 1, 0, 0]
# available = [3, 3, 2]

# need = [
#     [(max_matrix[i][j] - allocation[i][j]) for j in range(m)] for i in range(n)
# ]


# def print_2d_list(input_list: list) -> None:
#     for i in range(len(input_list)):
#         for j in range(len(input_list[0])):
#             print(f"{input_list[i][j]}\t", end="")
#         print()


# def add_lists(input_list_one: list, input_list_two: list) -> list:
#     result = list()

#     for i in range(len(input_list_one)):
#         result.append(input_list_one[i] + input_list_two[i])

#     return result


# class Safety:
#     def __init__(self):
#         self.work = copy.deepcopy(available)
#         self.finish = [False for _ in range(n)]
#         self.safe_sequence = list()

#     def need_work_comparison(self, i):
#         print(f"{self.work}")
#         for j in range(m):
#             if need[i][j] > self.work[j]:
#                 return False

#             return True

#     def execute_algorithm(self):
#         i = 0

#         while i < n:
#             if not self.finish[i] and self.need_work_comparison(i):
#                 self.work = add_lists(self.work, allocation[i])
#                 self.finish[i] = True
#                 self.safe_sequence.append(i + 1)
#                 i = -1
#             i += 1

#         is_safe = True

#         for i in range(n):
#             if self.finish[i] == False:
#                 is_safe = False

#         print(self.safe_sequence)

#         return is_safe

#     def print_safe_sequence(self):
#         print(f"Safe Sequence: {self.safe_sequence}")


# # class Request:
# #     def __init__(self):


# def main() -> None:
#     safety_algorithm = Safety()

#     print(safety_algorithm.execute_algorithm())


# if __name__ == "__main__":
#     main()

# # 1) If Requesti <= Needi
# # Goto step (2) ; otherwise, raise an error condition, since the process has exceeded its maximum claim.
# # 2) If Requesti <= Available
# # Goto step (3); otherwise, Pi must wait, since the resources are not available.
# # 3) Have the system pretend to have allocated the requested resources to process Pi by modifying the state as
# # follows:
# # Available = Available – Requesti
# # Allocationi = Allocationi + Requesti
# # Needi = Needi– Requesti
