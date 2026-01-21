import curses
import sys
import random
from functools import partial
from pydantic import BaseModel, model_validator, Field
from typing import Optional
from maze_generator import MazeGenerator, Direction, Cell


class MazeData(BaseModel):
    """
    Docstring for MazeData
    """

    width: int = Field(..., gt=3, lt=100)
    height: int = Field(..., gt=3, lt=100)
    entry: tuple[int, int]
    exit: tuple[int, int]
    perfect: bool
    output_file: str
    seed: Optional[int] = None
    algorithm: Optional[str] = None

    @model_validator(mode='after')
    def Validate_data(self):
        if self.entry == self.exit:
            raise ValueError("ERROR: ENTRY and EXIT should be "
                             "diffrent points")

        if self.entry[0] >= self.width or self.entry[0] < 0:
            raise ValueError("ERROR: ENTRY must be inside the maze")
        if self.entry[1] >= self.height or self.entry[1] < 0:
            raise ValueError("ERROR: ENTRY must be inside the maze")

        if self.exit[0] >= self.width or self.exit[0] < 0:
            raise ValueError("ERROR: EXIT must be inside the maze")
        if self.exit[1] >= self.height or self.exit[1] < 0:
            raise ValueError("ERROR: EXIT must be inside the maze")
        return self


def get_maze_data(config_file: str) -> MazeData:
    valid_keys: set = {'WIDTH', 'HEIGHT', 'ENTRY', 'EXIT',
                       'OUTPUT_FILE', 'PERFECT', 'SEED',
                       'ALGORITHM', 'DISPLAY_MODE'}
    config: dict = {}

    try:
        with open(config_file, 'r') as fd:
            for line in fd:
                if line.strip().split('=')[0] in valid_keys:
                    key, value = line.strip().split('=')
                    if key in {'ENTRY', 'EXIT'}:
                        x, y = value.split(',')
                        config[key.lower()] = (x, y)
                    else:
                        config[key.lower()] = value
        return MazeData(**config)
    except FileNotFoundError:
        import sys
        print("The config file is missing. check README")
        sys.exit()


def show_maze(window: curses.window, colors: list, maze: MazeGenerator,
              choice: Optional[str] = None):
    curses.start_color()
    curses.use_default_colors()

    curses.init_pair(1, colors[0], curses.COLOR_BLACK)  # Direction
    curses.init_pair(2, colors[1], curses.COLOR_BLACK)   # Start
    curses.init_pair(3, colors[2], curses.COLOR_BLACK)  # End
    curses.init_pair(4, colors[3], curses.COLOR_BLACK)  # Solution
    curses.init_pair(5, colors[4], curses.COLOR_BLACK)  # 42
    window.clear()
    for row in range(maze.height):
        for cell in range(maze.width):
            w_row, w_col = row * 2, cell * 3
            current_cell: Cell = maze.grid[row][cell]
            left_cell: Cell = current_cell.nighbors[Direction.LEFT]
            upper_cell: Cell = current_cell.nighbors[Direction.UP]
            # right_cell: Cell = current_cell.nighbors[Direction.RIGHT]

            # Draw North Wall
            if current_cell.direction[Direction.UP]:
                window.addstr(w_row, w_col, "███", curses.color_pair(1))
            else:
                window.addstr(w_row, w_col, "█", curses.color_pair(1))
                if left_cell and upper_cell:
                    if (left_cell.direction[Direction.UP] is False and
                            current_cell.direction[Direction.LEFT] is False and
                            upper_cell.direction[Direction.LEFT] is False):
                        window.addstr(w_row, w_col, " ")
                if (getattr(current_cell, 'is_path', False) and
                        upper_cell.is_path and
                        (current_cell.order + 1 == upper_cell.order or
                         current_cell.order == upper_cell.order + 1)):
                    window.addstr(w_row, w_col + 1, "██", curses.color_pair(4))

            if current_cell.direction[Direction.LEFT]:
                window.addstr(w_row + 1, w_col, "█", curses.color_pair(1))
            else:
                window.addstr(w_row + 1, w_col, " ")
                if (getattr(current_cell, 'is_path', False) and
                        left_cell.is_path and
                        (current_cell.order + 1 == left_cell.order or
                         current_cell.order == left_cell.order + 1)):
                    window.addstr(w_row + 1, w_col, "█", curses.color_pair(4))

            if getattr(current_cell, 'is_start', False):
                window.addstr(w_row + 1, w_col + 1, "███",
                              curses.color_pair(2))
            elif getattr(current_cell, 'is_end', False):
                window.addstr(w_row + 1, w_col + 1, "███",
                              curses.color_pair(3))
            elif getattr(current_cell, 'is_path', False):
                window.addstr(w_row + 1, w_col + 1, "███",
                              curses.color_pair(4))
            elif getattr(current_cell, 'is_reserved', False):
                window.addstr(w_row + 1, w_col + 1, "███")
    # Draw the final far-right and bottom boundary
    for r in range(maze.height * 2):
        window.addstr(r, maze.width * 3, "█", curses.color_pair(1))
    window.addstr(
        maze.height * 2, 0, "█" * (maze.width * 3 + 1), curses.color_pair(1))

    window.addstr(
        maze.height * 2 + 1, 0, "=== A-Maze-ing ===")
    window.addstr(
        maze.height * 2 + 2, 0, "1. Re-gerate a new maze")
    window.addstr(
        maze.height * 2 + 3, 0, "2. Re-gerate a new maze with animation")
    window.addstr(
        maze.height * 2 + 4, 0, "3. Show/Hide path from entry to exit")
    window.addstr(
        maze.height * 2 + 5, 0, "4. Show/Hide path from entry to exit with animation")
    window.addstr(
        maze.height * 2 + 6, 0, "5. Rotate maze colors")
    window.addstr(
        maze.height * 2 + 7, 0, "6. Save maze to file")
    window.addstr(
        maze.height * 2 + 8, 0, "7. Quit")
    window.addstr(
        maze.height * 2 + 9, 0, "Choice? (1-7): ")
    if choice:
        window.addstr(
            maze.height * 2 + 10, 16, choice)

    window.refresh()


def main(window: curses.window):
    data: MazeData = get_maze_data(sys.argv[1])

    colors: list = [curses.COLOR_WHITE, curses.COLOR_RED, curses.COLOR_GREEN,
                    curses.COLOR_YELLOW, curses.COLOR_BLUE, curses.COLOR_CYAN,
                    curses.COLOR_MAGENTA]
    display: callable = partial(show_maze, window, colors)

    maze: MazeGenerator = MazeGenerator(data.width, data.height,
                                        data.entry, data.exit,
                                        data.perfect,
                                        data.seed)
    maze.break_dead_end()

    solution = False
    while True:
        display(maze)
        choice = window.getkey()
        if choice == '1' or choice == '2':
            maze: MazeGenerator = MazeGenerator(
                data.width, data.height,
                data.entry, data.exit,
                data.perfect,
                data.seed)
            if choice == '1':
                maze.break_dead_end()
            else:
                maze.break_dead_end(display)
            solution = False
        elif choice == '3' or choice == '4':
            if solution is False:
                solution = True
                if choice == '3':
                    maze.show_solution()
                else:
                    maze.show_solution(display)
            else:
                solution = False
                maze.hide_solution()
        elif choice == '5':
            random.shuffle(colors)
            display = partial(show_maze, window, colors)
        elif choice == '6':
            maze.generate_file(data.output_file, True)
        elif choice == '7':
            break
        
    # maze.generate_file(data.output_file)

# def old_render():
#     data: MazeData = get_maze_data(sys.argv[1])
#     maze: MazeGenerator = MazeGenerator(data.width, data.height,
#                                         data.entry, data.exit,
#                                         data.perfect)
#     # grid_details(maze)
#     maze.depth_search(display)
#     # maze.show_solution(display)
#     # print(maze.solution)


if __name__ == '__main__':
    curses.wrapper(main)
    # old_render()