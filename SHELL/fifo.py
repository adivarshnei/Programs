ref_string: list = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1]


def get_data() -> tuple(int, list):
    frames: int = int(input("Enter number of frames: "))
    ref_string: list(int) = list(map(int, input("Enter reference string: ").split()))
    return frames, ref_string


def print_page_stack(page_stack: list) -> None:
    for _, page in enumerate(page_stack):
        if page != -1:
            print(f"{page} ", end="")

    print()


def fifo(frames: int, ref_string: list) -> int:
    page_stack: list(int) = [-1 for _ in range(frames)]
    faults: int = 0
    replace_count: int = 0

    print("Page Stack Status: ")

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

        print(f"{page}: ", end="")
        print_page_stack(page_stack)

    return faults


def main() -> None:
    print(f"Reference String: ", end="")

    for _, page in enumerate(ref_string):
        print(f"{page} ", end="")

    print()

    for frames in range(3, 6):
        print(
            f"Faults caused by {frames} frames: "
            + f"{fifo(frames=frames, ref_string=ref_string)}\n"
        )


if __name__ == "__main__":
    main()
