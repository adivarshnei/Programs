# Open Ended 2: Write a program to implement Floyd-Warshall's Algorithm

from __future__ import annotations

import os
import math
import subprocess
import typing

import pygame


class Options(typing.TypedDict):
    dims: list[int]
    title: str
    bg: tuple[int, int, int]
    font: str
    numfontsize: int
    auxfontsize: int
    fontbold: bool


def init(
    options: Options,
) -> tuple[pygame.surface.Surface, pygame.Font, pygame.Font]:
    pygame.init()
    surface = pygame.display.set_mode(size=options["dims"])
    pygame.display.set_caption(options["title"])
    surface.fill(color=options["bg"])

    num_font = pygame.freetype.SysFont(
        name=options["font"],
        size=options["numfontsize"],
        bold=options["fontbold"],
    )

    aux_font = pygame.freetype.SysFont(
        name=options["font"],
        size=options["auxfontsize"],
        bold=options["fontbold"],
    )

    return surface, num_font, aux_font


def get_outputs(filename: str) -> bytes:
    if not os.path.isfile(f"{os.path.splitext(p=filename)}.exe"):
        os.system(
            command=f"gcc {filename} -o {os.path.splitext(p=filename)[0]}"
        )

    process = subprocess.Popen(
        args=[f"{os.path.splitext(p=filename)[0]}"], stdout=subprocess.PIPE
    )
    (output, _) = process.communicate()

    return output


def tokenize(output: bytes) -> list[list[typing.Any]]:
    lines = output.decode().split(sep="\n")
    tokens = [line.split() for line in lines]
    tokens.pop()

    return tokens


def parse(
    tokens: list[list[str]],
) -> tuple[int, list[list[typing.Any]], list[list[str]], list[list[int]]]:
    length = int(tokens[0][0])
    del tokens[0]

    adj_temp = tokens[0:length]
    del tokens[0:length]

    adj: list[list[typing.Any]] = [
        [0 for _ in range(length)] for _ in range(length)
    ]

    distance = tokens[0:length]
    del tokens[0:length]

    parent_temp = tokens
    parent = [[0 for _ in range(length)] for _ in range(length)]

    for i in range(length):
        for j in range(length):
            if adj_temp[i][j] == "I":
                adj[i][j] = math.inf
            else:
                adj[i][j] = int(adj_temp[i][j])

            if parent_temp[i][j] == "N":
                parent[i][j] = 0
            else:
                parent[i][j] = int(parent_temp[i][j])

    return (length, adj, distance, parent)


def get_matrices() -> tuple[
    list[list[typing.Any]], list[list[int]], int, int, int
]:
    node_count, adj, _, parent = parse(
        tokens=tokenize(output=get_outputs(filename="floydwarshall.c"))
    )

    min_weight = min([min(row) for row in adj])
    max_weight = 0

    for i in range(node_count):
        for j in range(node_count):
            if adj[i][j] != math.inf and adj[i][j] > max_weight:
                max_weight = adj[i][j]

    return adj, parent, node_count, max_weight, min_weight


def draw_nodes(
    surface: pygame.surface.Surface,
    index: int,
    node_count: int,
    num_font: pygame.Font,
) -> None:
    pygame.draw.circle(
        surface=surface,
        color=(0, 0, 0),
        center=position_from_index(index=index, node_count=node_count),
        radius=40,
    )

    pygame.draw.circle(
        surface=surface,
        color=(255, 255, 255),
        center=position_from_index(index=index, node_count=node_count),
        radius=38,
    )

    num_font.render_to(
        surf=surface,
        dest=position_from_index(
            index=index, node_count=node_count, offsets=(-10, -12)
        ),
        text=str(index),
        fgcolor=(0, 0, 0),
    )


def draw_key_rect(
    surface: pygame.surface.Surface,
    min_weight: int,
    max_weight: int,
    font: pygame.Font,
) -> None:
    for i in range(100):
        col = (
            int((255 * i) / 100),
            0,
            255 - int((255 * i) / 100),
        )

        pos = (900 + (i * 5), 700, 5, 50)

        pygame.draw.rect(surface=surface, color=col, rect=pos)

    font.render_to(
        surf=surface,
        dest=(875, 717),
        text=str(min_weight),
        fgcolor=(0, 0, 0),
    )

    font.render_to(
        surf=surface,
        dest=(1405, 717),
        text=str(max_weight),
        fgcolor=(0, 0, 0),
    )

    font.render_to(
        surf=surface,
        dest=(1080, 675),
        text="Weight Key",
        fgcolor=(0, 0, 0),
    )


def draw_text(
    text: list[str], surface: pygame.surface.Surface, font: pygame.Font
) -> None:
    for i in range(len(text)):
        font.render_to(
            surf=surface,
            dest=(1000, 100 + 50 * i),
            text=text[i],
            fgcolor=(0, 0, 0),
        )


def position_from_index(
    index: int, node_count: int, offsets: tuple[int, int] = (0, 0)
) -> tuple[float, float]:
    return (
        400 - 350 * math.sin(2 * math.pi * index / node_count) + offsets[0],
        400 - 350 * math.cos(2 * math.pi * index / node_count) + offsets[1],
    )


def color_from_weight(
    weight: int, min_weight: int, max_weight: int
) -> tuple[int, int, int]:
    return (
        int(255 * (weight - min_weight) / (max_weight - min_weight)),
        int(0),
        int(255 - (255 * (weight - min_weight) / (max_weight - min_weight))),
    )


def path_from_parent(
    parent: list[list[int]], path: list[int], node1: int, node2: int
) -> None:
    if node1 == node2:
        path.append(node2)
    elif parent[node1][node2] == 0:
        pass
    else:
        path_from_parent(parent, path, node1, parent[node1][node2] - 1)
        path.append(node2)


def main() -> None:
    options: Options = {
        "dims": [1600, 800],
        "title": "All-Pairs Shortest Path",
        "bg": (255, 255, 255),
        "font": "Consolas",
        "numfontsize": 40,
        "auxfontsize": 24,
        "fontbold": False,
    }

    surface, num_font, aux_font = init(options=options)
    adj, parent, node_count, max_weight, min_weight = get_matrices()

    running = True
    first_node = None
    second_node = None
    path = []
    display_text = [
        "All-Pairs Shortest Path",
        "Floyd-Warshall Algorithm",
        "Click a node to set it as source",
        "Press ESC to exit",
    ]

    while running:
        nodes = []

        surface.fill(color=options["bg"])

        draw_text(text=display_text, surface=surface, font=aux_font)

        for i in range(node_count):
            for j in range(node_count):
                if adj[i][j] != 0 and adj[i][j] < math.inf:
                    if first_node is not None and second_node is not None:
                        for k in range(len(path) - 1):
                            pygame.draw.line(
                                surface=surface,
                                color=(0, 255, 0),
                                start_pos=position_from_index(
                                    index=path[k], node_count=node_count
                                ),
                                end_pos=position_from_index(
                                    index=path[k + 1], node_count=node_count
                                ),
                                width=3,
                            )
                    else:
                        pygame.draw.line(
                            surface=surface,
                            color=color_from_weight(
                                weight=adj[i][j],
                                min_weight=min_weight,
                                max_weight=max_weight,
                            ),
                            start_pos=position_from_index(
                                index=i, node_count=node_count
                            ),
                            end_pos=position_from_index(
                                index=j, node_count=node_count
                            ),
                            width=3,
                        )

        for i in range(node_count):
            draw_nodes(
                surface=surface,
                index=i,
                node_count=node_count,
                num_font=num_font,
            )

            nodes.append(position_from_index(index=i, node_count=node_count))

        draw_key_rect(
            surface=surface,
            min_weight=min_weight,
            max_weight=max_weight,
            font=aux_font,
        )

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = not running

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = not running

                if event.key == pygame.K_r:
                    first_node = None
                    second_node = None
                    display_text = [
                        "All-Pairs Shortest Path",
                        "Floyd-Warshall Algorithm",
                        "Click a node to set it as source",
                        "Press ESC to exit",
                    ]

            if event.type == pygame.MOUSEBUTTONUP:
                mouse_position = pygame.mouse.get_pos()

                x_mouse, y_mouse = mouse_position[0], mouse_position[1]

                for i in range(len(nodes)):
                    if (
                        x_mouse >= nodes[i][0] - 40
                        and x_mouse <= nodes[i][0] + 40
                        and y_mouse >= nodes[i][1] - 40
                        and y_mouse <= nodes[i][1] + 40
                    ):
                        if first_node is None:
                            first_node = (nodes[i], i)
                            display_text = [
                                f"First Node: {first_node[1]}",
                                "Click another node to set it as destination",
                            ]
                        elif first_node[0] != nodes[i] and second_node is None:
                            second_node = (nodes[i], i)
                            display_text.pop()
                            display_text.append(
                                f"Second Node: {second_node[1]}"
                            )
                        else:
                            second_node = None
                            first_node = (nodes[i], i)
                            path = []
                            display_text = [
                                f"First Node: {first_node[1]}",
                                "Click another node to set it as destination",
                            ]

                        if first_node is not None and second_node is not None:
                            path = []

                            path_from_parent(
                                parent=parent,
                                path=path,
                                node1=first_node[1],
                                node2=second_node[1],
                            )

                            if len(path) == 0:
                                display_text.append("No path is possible")
                            else:
                                path_text = f"{first_node[1]}"

                                for i in range(1, len(path)):
                                    path_text += f" -> {path[i]}"

                                display_text.append(f"Path: {path_text}")

                            display_text.append("Press R to reset")
                            display_text.append(
                                "Click any node to select it as source"
                            )

        pygame.display.update()

    pygame.quit()


if __name__ == "__main__":
    main()
