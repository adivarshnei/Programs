# Open Ended 1: Write a program to solve a sudoku puzzle using Backtracking
# Approach

from __future__ import annotations
from typing import TypedDict
from typing_extensions import Self
import copy
import math
import sys

import pygame
import pygame.freetype


class Options(TypedDict):
    dims: list[int]
    bg: tuple[int, int, int]
    outline: tuple[int, int, int]
    inline: tuple[int, int, int]
    title: str
    active_text: tuple[int, int, int]
    inactive_text: tuple[int, int, int]
    active_num: int


def key_to_number(event_key: int) -> int:
    key_list = [
        pygame.K_1,
        pygame.K_2,
        pygame.K_3,
        pygame.K_4,
        pygame.K_5,
        pygame.K_6,
        pygame.K_7,
        pygame.K_8,
        pygame.K_9,
    ]

    if event_key in key_list:
        return key_list.index(event_key) + 1
    else:
        return 0


class Setup(object):
    def __init__(self: Self, options: Options) -> None:
        pygame.init()
        self.surface = pygame.display.set_mode(size=options["dims"])
        pygame.display.set_caption(options["title"])
        self.surface.fill(color=options["bg"])

        self.num_font = pygame.freetype.SysFont(
            name="Consolas", size=40, bold=True
        )
        self.aux_font = pygame.freetype.SysFont(
            name="Calibri", size=24, bold=False
        )


class Sudoku(Setup):
    boards = [
        [
            [0, 6, 0, 3, 0, 0, 8, 0, 4],
            [5, 3, 7, 0, 9, 0, 0, 0, 0],
            [0, 4, 0, 0, 0, 6, 3, 0, 7],
            [0, 9, 0, 0, 5, 1, 2, 3, 8],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [7, 1, 3, 6, 2, 0, 0, 4, 0],
            [3, 0, 6, 4, 0, 0, 0, 1, 0],
            [0, 0, 0, 0, 6, 0, 5, 2, 3],
            [1, 0, 2, 0, 0, 9, 0, 8, 0],
        ],
        [
            [3, 0, 6, 5, 0, 8, 4, 0, 0],
            [5, 2, 0, 0, 0, 0, 0, 0, 0],
            [0, 8, 7, 0, 0, 0, 0, 3, 1],
            [0, 0, 3, 0, 1, 0, 0, 8, 0],
            [9, 0, 0, 8, 6, 3, 0, 0, 5],
            [0, 5, 0, 0, 9, 0, 6, 0, 0],
            [1, 3, 0, 0, 0, 0, 2, 5, 0],
            [0, 0, 0, 0, 0, 0, 0, 7, 4],
            [0, 0, 5, 2, 0, 6, 3, 0, 0],
        ],
        [
            [1, 2, 3, 4, 5, 6, 7, 8, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 1],
            [0, 0, 0, 0, 0, 0, 0, 0, 2],
            [0, 0, 0, 0, 0, 0, 0, 0, 3],
            [0, 0, 0, 0, 0, 0, 0, 0, 4],
            [0, 0, 0, 0, 0, 0, 0, 0, 5],
            [0, 0, 0, 0, 0, 0, 0, 0, 6],
            [0, 0, 0, 0, 0, 0, 0, 0, 7],
            [0, 0, 0, 0, 0, 0, 0, 0, 8],
        ],
    ]

    selected = 0

    def __init__(self: Self, options: Options) -> None:
        super().__init__(options=options)
        self.board = copy.deepcopy(x=Sudoku.boards[Sudoku.selected])
        self.solved_board = copy.deepcopy(x=Sudoku.boards[Sudoku.selected])

        self.empty_cell = [0, 0]

        self.init_solve()

        self.entry_mode = False
        self.solve_mode = False

        self.position = {"row": 0, "col": 0}

    def change_board(self: Self, options: Options) -> None:
        Sudoku.selected += 1
        Sudoku.selected %= len(Sudoku.boards)

        self.__init__(options=options)

    def reset(self: Self) -> None:
        self.board = copy.deepcopy(x=Sudoku.boards[Sudoku.selected])

    def board_print(self: Self) -> None:
        for row in self.board:
            print(row)

        print()

    def write_data(self: Self, options: Options) -> None:
        text_color = options["active_text"]

        if self.entry_mode:
            data = [
                "(1 - 9): Enter Number",
                "0: Clear Number",
                "Left Click: Navigation",
                "Bksp: Exit Entry Mode",
            ]
        elif self.solve_mode:
            data = ["Solving"]
        else:
            data = [
                "(1 - 9): Highlight Number",
                "0: Remove Hightlights",
                "E: Entry Mode",
                "S: Solve Mode",
                "R: Reset Board",
                "C: Change Board",
                "Esc: Exit",
            ]

        for index, phrase in enumerate(iterable=data):
            self.aux_font.render_to(
                surf=self.surface,
                dest=[950, 100 + index * 40],
                text=phrase,
                fgcolor=text_color,
            )

    def write_nums(
        self: Self, options: Options, color: tuple[int, int, int]
    ) -> None:
        for i in range(len(self.board)):
            for j in range(len(self.board)):
                num = " "
                text_color = options["active_text"]

                if options["active_num"] == 0:
                    text_color = options["active_text"]
                else:
                    if self.board[j][i] == options["active_num"]:
                        text_color = options["active_text"]
                    else:
                        text_color = options["inactive_text"]

                if self.board[j][i] != 0:
                    num = str(object=self.board[j][i])

                if self.board_empty_check(init=False):
                    if self.boards[self.selected][j][i] != self.board[j][i]:
                        text_color = color

                    if not self.solve_mode:
                        if self.boards[self.selected][j][i] == 0:
                            if self.board[j][i] == self.solved_board[j][i]:
                                text_color = (0, 200, 0)
                                text_color = (200, 0, 0)

                if not self.board_empty_check(init=False):
                    if options["active_num"] == 0:
                        text_color = options["active_text"]
                    else:
                        if self.board[j][i] == options["active_num"]:
                            text_color = options["active_text"]
                        else:
                            text_color = options["inactive_text"]

                self.num_font.render_to(
                    surf=self.surface,
                    dest=[66 + (100 * i), 66 + (100 * j)],
                    text=num,
                    fgcolor=text_color,
                )

    def board_design(
        self: Self, options: Options, color: tuple[int, int, int]
    ) -> None:
        self.surface.fill(color=options["bg"])

        for i in range(len(self.board) + 1):
            if i % 3 == 0:
                line_color = options["outline"]
            else:
                line_color = options["inline"]

            pygame.draw.line(
                surface=self.surface,
                color=line_color,
                start_pos=(25, (100 * i + 25)),
                end_pos=(925, (100 * i + 25)),
                width=7,
            )

            pygame.draw.line(
                surface=self.surface,
                color=line_color,
                start_pos=((100 * i + 25), 25),
                end_pos=((100 * i + 25), 925),
                width=7,
            )

            self.write_nums(options=options, color=color)
            self.write_data(options=options)

            if self.entry_mode:
                pygame.draw.rect(
                    surface=self.surface,
                    color=(136, 192, 208),
                    rect=pygame.Rect(
                        (100 * self.position["col"]) + 25,
                        (100 * self.position["row"]) + 25,
                        100,
                        100,
                    ),
                    width=7,
                )

    def entry(
        self: Self, options: Options, color: tuple[int, int, int]
    ) -> None:
        self.entry_mode = True

        for i in range(0, 9):
            for j in range(0, 9):
                if self.board[i][j] == 0:
                    self.position["row"], self.position["col"] = i, j
                    break
                else:
                    continue

            break

        while self.entry_mode:
            for event in pygame.event.get():
                if event.type == pygame.MOUSEBUTTONUP:
                    mouse_position = pygame.mouse.get_pos()

                    row_mouse_position = math.floor(mouse_position[0] / 100)
                    col_mouse_position = math.floor(mouse_position[1] / 100)

                    if (
                        self.boards[self.selected][col_mouse_position][
                            row_mouse_position
                        ]
                        == 0
                    ):
                        self.position["col"], self.position["row"] = (
                            row_mouse_position,
                            col_mouse_position,
                        )

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_BACKSPACE:
                        self.entry_mode = not self.entry_mode
                    if event.key == pygame.K_ESCAPE:
                        sys.exit(0)

                    self.board[self.position["row"]][
                        self.position["col"]
                    ] = key_to_number(event_key=event.key)

            self.board_design(options=options, color=color)

            pygame.display.update()

    def board_empty_check(self: Self, init: bool) -> bool:
        board_to_check = self.solved_board if init else self.board

        for i in range(len(self.board)):
            for j in range(len(self.board)):
                if board_to_check[i][j] == 0:
                    self.empty_cell[0] = i
                    self.empty_cell[1] = j
                    return True

        return False

    def in_row(self: Self, row: int, num: int, init: bool) -> bool:
        board_to_check = self.solved_board if init else self.board

        for i in range(len(self.board)):
            if board_to_check[row][i] == num:
                return True

        return False

    def in_col(self: Self, col: int, num: int, init: bool) -> bool:
        board_to_check = self.solved_board if init else self.board

        for i in range(len(self.board)):
            if board_to_check[i][col] == num:
                return True

        return False

    def in_box(self: Self, row: int, col: int, num: int, init: bool) -> bool:
        box_count = int(math.sqrt(len(self.board)))
        board_to_check = self.solved_board if init else self.board

        for i in range(box_count):
            for j in range(box_count):
                if board_to_check[i + row][j + col] == num:
                    return True

        return False

    def solve(self: Self, options: Options) -> bool:
        self.solve_mode = True

        if not self.board_empty_check(init=False):
            self.solve_mode = False
            return True

        pygame.event.get()

        r, c = self.empty_cell[0], self.empty_cell[1]

        for i in range(1, 10):
            if (
                not self.in_row(row=r, num=i, init=False)
                and not self.in_col(col=c, num=i, init=False)
                and not self.in_box(
                    row=(r - r % 3), col=(c - c % 3), num=i, init=False
                )
            ):
                keys = pygame.key.get_pressed()

                if keys[pygame.K_ESCAPE]:
                    sys.exit(0)

                self.board[r][c] = i

                self.board_design(options=options, color=(0, 200, 0))
                pygame.time.delay(40)
                pygame.display.update()

                if self.solve(options=options):
                    return True

                self.board_design(options=options, color=(200, 0, 0))
                pygame.time.delay(40)
                pygame.display.update()

                self.board[r][c] = 0

        return False

    def init_solve(self: Self) -> bool:
        if not self.board_empty_check(init=True):
            return True

        r, c = self.empty_cell[0], self.empty_cell[1]

        for i in range(1, len(self.board) + 1):
            if (
                not self.in_row(row=r, num=i, init=True)
                and not self.in_col(col=c, num=i, init=True)
                and not self.in_box(
                    row=r - r % 3, col=c - c % 3, num=i, init=True
                )
            ):
                self.solved_board[r][c] = i

                if self.init_solve():
                    return True

                self.solved_board[r][c] = 0

        return False

    def return_board(self: Self) -> list[list[int]]:
        return self.board


def main() -> None:
    options: Options = {
        "dims": [1200, 950],
        "bg": (255, 255, 255),
        "outline": (75, 75, 75),
        "inline": (135, 135, 135),
        "title": "Sudoku",
        "active_text": (55, 55, 55),
        "inactive_text": (155, 155, 155),
        "active_num": 0,
    }

    running = True

    s1 = Sudoku(options=options)

    while running:
        s1.board_design(options=options, color=(0, 0, 0))

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = not running

                options["active_num"] = key_to_number(event_key=event.key)

                if event.key == pygame.K_s:
                    s1.reset()
                    s1.solve(options=options)

                if event.key == pygame.K_e:
                    s1.entry(options=options, color=(136, 192, 208))

                if event.key == pygame.K_r:
                    s1.reset()

                if event.key == pygame.K_c:
                    s1.change_board(options=options)

        pygame.display.update()

    pygame.quit()


if __name__ == "__main__":
    main()
