import random

SNO: "list[int]" = [
    12579,
    10070,
    18900,
    11500,
    14677,
    15739,
    11859,
    17967,
    19187,
    15525,
    19568,
    18021,
    11230,
    11048,
    17100,
    18643,
    19379,
    16518,
    19690,
    16240,
]

PNO: "list[int]" = [
    21837,
    27083,
    28631,
    26749,
    28842,
    26188,
    25025,
    29224,
    26383,
    25212,
    23187,
    29445,
    29609,
    21435,
    25203,
    20876,
    24396,
    28173,
    28326,
    29457,
]

JNO: "list[int]" = [
    35986,
    31438,
    39299,
    37650,
    35151,
    37114,
    37474,
    34872,
    33604,
    33104,
]

cities: "list[str]" = ["London", "Paris", "Berlin", "Madrid", "Vienna"]
colors: "list[str]" = ["Red", "Blue", "Green", "Yellow", "Black", "White"]

random.shuffle(SNO)
random.shuffle(PNO)
random.shuffle(JNO)

for i in range(20):
    print(f"{random.choice(JNO)}")
