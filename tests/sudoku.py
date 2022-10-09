"""
Open Ended Experiment
Aim: To display backtracking programming technique via solving a sudoku game
"""


from __future__ import annotations
import typing
import copy
import math

import pygame
import pygame.freetype


class Setup(object):
    """
    Class defining the base parameters of the pygame window

    Attributes
    ----------
    `surface: pygame.surface.Surface`
        Reference to the surface object
    `num_font: pygame.Font`
        Reference to the font object used for numbers
    `aux_font: pygame.Font`
        Reference to the font object used for other dispalys

    Methods
    -------
    `return_surface()`
        Returns reference to the surface made
    `return_num_font()`
        Returns the font used to display the numbers
    `return_aux_font()`
        Returns the font used for other displays
    """

    def __init__(self, options: dict[str, typing.Any]) -> None:
        """Constructor Function for Setup Class

        Initializes the pygame module, defines the Surface, Caption, and fonts
        needed for displaying the game.

        Parameters
        ----------
        `options: dict[str, typing.Any]`
            Dictionary containing all basic parameters
            Dictionary Format:
                `"dims"`: 2 element list containing the dimensions of the array in width-height format
                `"bg"`: RGB(A) color tuple of background
                `"outline"`: RGB(A) color tuple of board outlines
                `"inline"`: RGB(A) color tuple of board inlines
                `"caption"`: String for window title
                `"active_text"`: RGB(A) color tuple of active text
                `"inactive_text"`: RGB(A) color tuple of inactive text
                `"active_num"`: Current number being highlighted
        """

        pygame.init()
        self.surface: pygame.surface.Surface = pygame.display.set_mode(
            size=options["dims"]
        )
        pygame.display.set_caption(title=options["title"])
        self.surface.fill(color=options["bg"])

        self.num_font: pygame.Font = pygame.freetype.SysFont(
            name="Consolas", size=40, bold=True
        )
        self.aux_font: pygame.Font = pygame.freetype.SysFont(
            name="Calibri", size=24, bold=False
        )

    # def return_surface(self) -> pygame.surface.Surface:
    #     return self.surface

    # def return_num_font(self) -> pygame.Font:
    #     return self.num_font

    # def return_aux_font(self) -> pygame.Font:
    #     return self.aux_font


class Sudoku(Setup):
    """
    Class defining the sudoku game.

    Attributes
    ----------
    `boards: list[list[list[int]]]`
        List of available sudoku boards
    `selected: int`
        Index of selected board
    `self.board: list[list[int]]`
        Current board
    `self.solved_board: list[list[int]]`
        Current solved board
    `self.entry_mode: bool`
        Whether in entry mode
    `self.solve_mode: bool`
        Whether in solve mode
    `self.position: dict[str, int]`
        Dictionary containing position of entry
        Dictionary Format:
            `"row"`: Index of row
            `"col"`: Index of column

    Methods
    -------


    """

    boards: list[list[list[int]]] = [
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

    selected: int = 0

    def __init__(self, options: dict[str, typing.Any]) -> None:
        """Constructor Function for Sudoku Class

        Calls the Setup constructor, gets the unsolved and solved boards, and
        variables to set the mode and position.

        Parameters
        ----------
        `options`: `dict[str, typing.Any]`
            Dictionary containing all basic parameters
            Dictionary Format:
                `"dims"`: 2 element list containing the dimensions of the array in width-height format
                `"bg"`: RGB(A) color tuple of background
                `"outline"`: RGB(A) color tuple of board outlines
                `"inline"`: RGB(A) color tuple of board inlines
                `"caption"`: String for window title
                `"active_text"`: RGB(A) color tuple of active text
                `"inactive_text"`: RGB(A) color tuple of inactive text
                `"active_num"`: Current number being highlighted
        """

        super().__init__(options=options)
        self.board: list[list[int]] = copy.deepcopy(
            x=Sudoku.boards[Sudoku.selected]
        )
        self.solved_board: list[list[int]] = copy.deepcopy(
            x=Sudoku.boards[Sudoku.selected]
        )

        self.init_solve()

        self.entry_mode: bool = False
        self.solve_mode: bool = False

        self.position: dict[str, int] = {"row": 0, "col": 0}

    def change_board(self, options: dict[str, typing.Any]) -> None:
        """
        Function to Change Board Being Used

        Args
        ----
        `options`: `dict[str, typing.Any]`
            Dictionary containing all basic parameters
            Dictionary Format:
                `"dims"`: 2 element list containing the dimensions of the array in width-height format
                `"bg"`: RGB(A) color tuple of background
                `"outline"`: RGB(A) color tuple of board outlines
                `"inline"`: RGB(A) color tuple of board inlines
                `"caption"`: String for window title
                `"active_text"`: RGB(A) color tuple of active text
                `"inactive_text"`: RGB(A) color tuple of inactive text
                `"active_num"`: Current number being highlighted
        """
        Sudoku.selected += 1
        Sudoku.selected %= len(Sudoku.boards)

        self.__init__(options=options)

    def reset(self) -> None:
        """"""
        self.board: list[list[int]] = copy.deepcopy(
            x=Sudoku.boards[Sudoku.selected]
        )

    def board_print(self) -> None:
        for row in self.board:
            print(row)

        print()

    def write_data(self, options: dict[str, typing.Any]) -> None:
        text_color: tuple[int, int, int] = options["active_text"]

        if self.entry_mode:
            data: list[str] = [
                "(1 - 9): Enter Number",
                "0: Clear Number",
                "Left Click: Navigation",
                "Bksp: Exit Entry Mode",
            ]
        elif self.solve_mode:
            data: list[str] = ["Solving"]
        else:
            data: list[str] = [
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
                dest=(950, 100 + index * 40),
                text=phrase,
                fgcolor=text_color,
            )

    def write_nums(
        self, options: dict[str, typing.Any], color: tuple[int, int, int]
    ) -> None:
        for i in range(len(self.board)):
            for j in range(len(self.board)):
                num: str = " "

                if options["active_num"] == 0:
                    text_color: tuple[int, int, int] = options["active_text"]
                else:
                    if self.board[j][i] == options["active_num"]:
                        text_color: tuple[int, int, int] = options[
                            "active_text"
                        ]
                    else:
                        text_color: tuple[int, int, int] = options[
                            "inactive_text"
                        ]

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
                    dest=(66 + (100 * i), 66 + (100 * j)),
                    text=num,
                    fgcolor=text_color,
                )

    def board_design(
        self, options: dict[str, typing.Any], color: tuple[int, int, int]
    ):
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
                        left=(100 * self.position["col"]) + 25,
                        top=(100 * self.position["row"]) + 25,
                        width=100,
                        height=100,
                    ),
                    width=7,
                )

    # TODO
    # def entry(self,options,color):

    def board_empty_check(self, init):
        if init:
            for i in range(len(self.board)):
                for j in range(len(self.board)):
                    if self.solved_board[i][j] == 0:
                        self.empty_cell[0] = i
                        self.empty_cell[1] = j

                        return True
        else:
            for i in range(len(self.board)):
                for j in range(len(self.board)):
                    if self.board[i][j] == 0:
                        self.empty_cell[0] = i
                        self.empty_cell[1] = j

                        return True

        return False

    def in_row(self, row, num, init):
        if init:
            for i in range(len(self.board)):
                if self.solved_board[row][i] == num:
                    return True
        else:
            for i in range(len(self.board)):
                if self.board[row][i] == num:
                    return True

        return False

    def in_col(self, col, num, init):
        if init:
            for i in range(len(self.board)):
                if self.solved_board[i][col] == num:
                    return True
        else:
            for i in range(len(self.board)):
                if self.board[i][col] == num:
                    return True

        return False

    def in_box(self, row, col, num, init):
        box_count = int(math.sqrt(len(self.board)))

        if init:
            for i in range(box_count):
                for j in range(box_count):
                    if self.solved_board[i + row][j + col] == num:
                        return True
        else:
            for i in range(box_count):
                for j in range(box_count):
                    if self.board[i + row][j + col] == num:
                        return True

        return False

    # def solve(self, options):...
    def init_solve(self):
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

    # TODO
    # def return_board(self):...


# TODO
def main():
    pass


if __name__ == "__main__":
    main()
