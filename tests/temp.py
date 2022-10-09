def solve(s):
    st_arr = []

    for i in range(len(s) - 1, -1, -1):
        for j in range(len(st_arr)):
            st_arr.append(s[i] + st_arr[j])
        st_arr.append(s[i])
    return st_arr


def sort_len(s) -> list:
    for i in range(len(s)):
        for j in range(i, len(s)):
            if len(s[i]) > len(s[j]):
                s[i], s[j] = s[j], s[i]

    return s


# print(sort(solve("EFGHIJKLMN")))

elems = solve("EFGHIJKLMN")
elems.sort()

combs = sort_len(elems)

solns = [f"({comb})^+={{}}" for comb in combs]

for soln in solns:
    print(soln)
