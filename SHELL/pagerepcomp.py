from matplotlib import pyplot as plt
import copy

frames = 5
ref_string = [1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6]
max_frames = len(ref_string)
fifo_fault_string = list()
optimal_fault_string = list()
lru_fault_string = list()


def get_data() -> tuple:
    frames = int(input("Enter number of frames: "))
    ref_string = list(map(int, input("Enter reference string: ").split()))
    return frames, ref_string


def fifo(frames: int, ref_string: list) -> int:
    page_stack = [-1 for _ in range(frames)]
    faults = 0
    replace_count = 0

    for _, page in enumerate(ref_string):
        try:
            page_stack.index(page)
        except ValueError:
            faults += 1

            if page_stack.count(-1) > 0:
                page_stack[page_stack.index(-1)] = page
            else:
                page_stack[replace_count] = page
                replace_count = (replace_count + 1) % frames

        # print(page_stack)
    fifo_fault_string.append(faults)
    # print(faults)
    return faults


def optimal(frames: int, ref_string: list) -> int:
    page_stack = [-1 for _ in range(frames)]
    faults = 0
    replace_count = 0

    for i, page in enumerate(ref_string):
        try:
            page_stack.index(page)
        except ValueError:
            faults += 1

            if page_stack.count(-1) > 0:
                page_stack[page_stack.index(-1)] = page
            else:
                page_stack_copy = copy.deepcopy(page_stack)
                # print(page_stack_copy)

                # print(i, ref_string[i])

                j = i + 1

                while j < len(ref_string):
                    # print(f"\t\t\t{i}")
                    # print(f"\t\t{page}")
                    # print(ref_string[j], j)
                    if len(page_stack_copy) == 1:
                        # print(page_stack.index(page_stack_copy[0]))
                        page_stack[page_stack.index(page_stack_copy[0])] = page
                        break
                    elif page_stack_copy.count(ref_string[j]) > 0:
                        page_stack_copy.remove(ref_string[j])
                        # print(ref_string[j], page_stack_copy)

                    # print(ref_string[j])

                    # print(page_stack_copy)
                    j += 1

                if not len(page_stack_copy) == 1:
                    page_stack[page_stack.index(page_stack_copy[0])] = page

        # print(f"\n{page_stack}\n")

    optimal_fault_string.append(faults)
    # print(faults)
    return 0


def lru(frames: int, ref_string: list) -> int:
    page_stack = [-1 for _ in range(frames)]
    faults = 0
    replace_count = 0

    for i, page in enumerate(ref_string):
        try:
            page_stack.index(page)
        except ValueError:
            faults += 1

            if page_stack.count(-1) > 0:
                page_stack[page_stack.index(-1)] = page
            else:
                page_stack_copy = copy.deepcopy(page_stack)
                # print(page_stack_copy)

                # print(i, ref_string[i])

                j = i

                while j >= 0:
                    # print(f"{i}, {j}")
                    # print(f"\t\t{page}")
                    # print(ref_string[j], j)
                    if len(page_stack_copy) == 1:
                        # print(len(page_stack_copy))
                        # print(page_stack.index(page_stack_copy[0]))
                        page_stack[page_stack.index(page_stack_copy[0])] = page
                        break
                    elif page_stack_copy.count(ref_string[j]) > 0:
                        page_stack_copy.remove(ref_string[j])
                        # print(ref_string[j], page_stack_copy)

                    # print(ref_string[j])

                    # print(page_stack_copy)
                    j -= 1

                if not len(page_stack_copy) == 1:
                    page_stack[page_stack.index(page_stack_copy[0])] = page

        # print(f"\n{page_stack}\n")

    lru_fault_string.append(faults)
    # print(faults)
    return 0


def main() -> None:
    # frames, ref_string = get_data()
    for frames in range(1, max_frames):
        fifo(frames=frames, ref_string=ref_string)
        optimal(frames=frames, ref_string=ref_string)
        lru(frames=frames, ref_string=ref_string)

    plt.plot(fifo_fault_string, label="FIFO")
    plt.plot(optimal_fault_string, label="Optimal")
    plt.plot(lru_fault_string, label="LRU")
    plt.legend(loc="upper right")
    plt.grid()
    plt.show()


if __name__ == "__main__":
    main()
