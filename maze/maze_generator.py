from enum import Enum
import random
import time
from typing import Optional, Dict, List, Callable


class Direction(Enum):
    UP = 'up'
    DOWN = 'down'
    LEFT = 'left'
    RIGHT = 'right'


class Cell:
    def __init__(self, width: int, height: int) -> None:
        self.width: int = width  # Horizontal
        self.height: int = height  # Vertival
        self.is_reserved = False
        self.is_start = False
        self.is_end = False
        self.is_visited = False
        self.is_path = False
        self.direction: dict[Direction, bool] = {
            Direction.UP: True,
            Direction.RIGHT: True,
            Direction.DOWN: True,
            Direction.LEFT: True}
        self.nighbors: dict[Direction, Optional[Cell]] = {
            Direction.UP: None,
            Direction.RIGHT: None,
            Direction.DOWN: None,
            Direction.LEFT: None}
        self.liked_to: set = set()

    def get_location(self) -> tuple[int, int]:
        """
        Docstring for get_location

        :return: return coardinations of a cell (width, height)
            width bieng the height (Horizontal)
            height being the width (Vertical)
        :rtype: tuple[int, int]
        """
        return (self.width, self.height)

    def reserve_cell(self):
        self.is_visited = True
        self.is_reserved = True

    def get_binary_walls(self) -> str:
        walls: str = ''
        walls += '1' if self.direction[Direction.LEFT] else '0'
        walls += '1' if self.direction[Direction.DOWN] else '0'
        walls += '1' if self.direction[Direction.RIGHT] else '0'
        walls += '1' if self.direction[Direction.UP] else '0'
        return walls

    def destroy_wall(self, wall: Direction):
        opposite_wall: Dict[Direction, Direction] = {
            Direction.UP: Direction.DOWN,
            Direction.RIGHT: Direction.LEFT,
            Direction.DOWN: Direction.UP,
            Direction.LEFT: Direction.RIGHT
        }

        cell = self.nighbors[wall]
        if cell and cell.is_reserved is False:
            self.direction[wall] = False
            cell.direction[opposite_wall[wall]] = False
            self.liked_to.add(cell)


class MazeGenerator:
    def __init__(self,
                 width: int,
                 height: int,
                 entry: tuple[int, int],
                 exit: tuple[int, int],
                 perfect: bool,
                 seed: Optional[int] = None):

        self.width: int = width
        self.height: int = height
        self.entry: tuple[int, int] = entry
        self.exit: tuple[int, int] = exit
        self.perfect: bool = perfect
        self.seed: Optional[int] = seed
        self.grid: List[List[Cell]] = self.generate_grid()
        self.set_seed()

    def set_seed(self):
        if self.seed is None:
            self.seed = random.randint(0, 10**6)

    def generate_grid(self) -> List[List[Cell]]:
        grid: List = []
        for y in range(self.height):
            lst_col: List = []
            for x in range(self.width):
                lst_col.append(Cell(x, y))
            grid.append(lst_col)

        self.introduce_nighbors(grid)
        entry_cell: Cell = grid[self.entry[1]][self.entry[0]]
        entry_cell.is_start = True
        exit_cell: Cell = grid[self.exit[1]][self.exit[0]]
        exit_cell.is_end = True
        self.mark_reserved_cells(grid)
        return grid

    def introduce_nighbors(self, grid: List[List[Cell]]) -> None:
        for row in grid:
            for cell in row:
                width, height = cell.get_location()
                if cell.height != 0:
                    cell.nighbors[Direction.UP] = grid[height - 1][width]

                if cell.width != 0:
                    cell.nighbors[Direction.LEFT] = grid[height][width - 1]

                if cell.width < self.width - 1:
                    cell.nighbors[Direction.RIGHT] = grid[height][width + 1]

                if cell.height < self.height - 1:
                    cell.nighbors[Direction.DOWN] = grid[height + 1][width]

    def mark_reserved_cells(self, grid: List[List[Cell]]):
        if self.height < 8 or self.width < 10:
            return

        mid_height: int = self.height // 2
        mid_width: int = self.width // 2

        #  reserve number four
        # ---
        grid[mid_height][mid_width - 1].reserve_cell()
        grid[mid_height][mid_width - 2].reserve_cell()
        grid[mid_height][mid_width - 3].reserve_cell()
        # |--
        grid[mid_height - 1][mid_width - 3].reserve_cell()
        grid[mid_height - 2][mid_width - 3].reserve_cell()
        #  --|
        grid[mid_height + 1][mid_width - 1].reserve_cell()
        grid[mid_height + 2][mid_width - 1].reserve_cell()

        #  reserve number two
        #  ---
        grid[mid_height][mid_width + 1].reserve_cell()
        grid[mid_height][mid_width + 2].reserve_cell()
        grid[mid_height][mid_width + 3].reserve_cell()

        # |
        grid[mid_height - 1][mid_width + 3].reserve_cell()
        grid[mid_height - 2][mid_width + 3].reserve_cell()
        grid[mid_height - 2][mid_width + 2].reserve_cell()
        grid[mid_height - 2][mid_width + 1].reserve_cell()

        # --
        grid[mid_height + 1][mid_width + 1].reserve_cell()
        grid[mid_height + 2][mid_width + 1].reserve_cell()

        grid[mid_height + 2][mid_width + 2].reserve_cell()
        grid[mid_height + 2][mid_width + 3].reserve_cell()

    def test(self, staring_cell: Cell, display: Optional[Callable] = None):
        random.seed(self.seed)
        width, height = self.entry
        staring_cell.is_visited = True
        stack: List[Cell] = [staring_cell, ]
        while stack:
            cell: Cell = stack[-1]
            width, height = cell.get_location()
            unvisited_cells: List[tuple[Cell, Direction]] = []
            if cell.is_end and staring_cell.is_start:
                self.solution: List = stack.copy()

            if height != 0 and self.grid[height - 1][width]:
                if self.grid[height - 1][width].is_visited is False:
                    unvisited_cells.append((self.grid[height - 1][width],
                                            Direction.DOWN))

            if height != self.height - 1 and self.grid[height + 1][width]:
                if self.grid[height + 1][width].is_visited is False:
                    unvisited_cells.append((self.grid[height + 1][width],
                                            Direction.UP))

            if width != 0 and self.grid[height][width - 1]:
                if self.grid[height][width - 1].is_visited is False:
                    unvisited_cells.append((self.grid[height][width - 1],
                                            Direction.RIGHT))

            if width != self.width - 1 and self.grid[height][width + 1]:
                if self.grid[height][width + 1].is_visited is False:
                    unvisited_cells.append((self.grid[height][width + 1],
                                            Direction.LEFT))

            if unvisited_cells:
                x_cell, wall = unvisited_cells.pop(
                    random.randint(0, len(unvisited_cells) - 1))
                x_cell.is_visited = True
                x_cell.destroy_wall(wall)
                stack.append(x_cell)
                if display:
                    display(self)
                    time.sleep(0.04)
                yield False
            else:
                stack.pop()
        yield True

    def reset_grid(self):
        for row in self.grid:
            for cell in row:
                cell.is_visited = False

    def two_way(self, display: Optional[Callable] = None):
        self.depth_first_search(display)
        self.reset_grid()
        self.mark_reserved_cells(self.grid)
        self.depth_first_search(display)

    def break_dead_end(self, display: Optional[Callable] = None):
        self.depth_first_search()
        for row in self.grid:
            for cell in row:
                if cell.is_reserved:
                    continue
                lst: List = [key for key, wall in cell.direction.items()
                             if wall is True]
                if len(lst) >= 3:
                    cell.destroy_wall(random.choice(lst))
                if display:
                    display(self)
                    time.sleep(0.04)

    def depth_first_search(self, display: Optional[Callable] = None) -> None:
        random.seed(self.seed)
        width, height = self.entry
        staring_cell: Cell = self.grid[height][width]
        staring_cell.is_visited = True
        stack: List[Cell] = [staring_cell, ]
        while stack:
            cell: Cell = stack[-1]
            width, height = cell.get_location()
            unvisited_cells: List[tuple[Cell, Direction]] = []
            if cell.is_end:
                self.solution: List = stack.copy()

            if height != 0 and self.grid[height - 1][width]:
                if self.grid[height - 1][width].is_visited is False:
                    unvisited_cells.append((self.grid[height - 1][width],
                                            Direction.DOWN))

            if height != self.height - 1 and self.grid[height + 1][width]:
                if self.grid[height + 1][width].is_visited is False:
                    unvisited_cells.append((self.grid[height + 1][width],
                                            Direction.UP))

            if width != 0 and self.grid[height][width - 1]:
                if self.grid[height][width - 1].is_visited is False:
                    unvisited_cells.append((self.grid[height][width - 1],
                                            Direction.RIGHT))

            if width != self.width - 1 and self.grid[height][width + 1]:
                if self.grid[height][width + 1].is_visited is False:
                    unvisited_cells.append((self.grid[height][width + 1],
                                            Direction.LEFT))

            if unvisited_cells:
                x_cell, wall = unvisited_cells.pop(
                    random.randint(0, len(unvisited_cells) - 1))
                x_cell.is_visited = True
                x_cell.destroy_wall(wall)
                stack.append(x_cell)
                if display:
                    display(self)
                    time.sleep(0.04)
            else:
                stack.pop()

    def show_solution(self, display: Optional[Callable] = None) -> None:
        i = 0
        for cell in self.solution:
            cell.is_path = True
            cell.order = i
            i += 1
            if display:
                display(self)
                time.sleep(0.06)

    def hide_solution(self, display: Optional[Callable] = None) -> None:
        for cell in self.solution:
            cell.is_path = False
            if display:
                display(self)
                time.sleep(0.06)

    def solution_to_directions(self) -> str:
        res: List = []
        for i in range(len(self.solution) - 1):
            i2 = i + 1
            cell: Cell = self.solution[i]
            cell2: Cell = self.solution[i2]
            if cell.nighbors[Direction.UP] == cell2:
                res.append('N')
            elif cell.nighbors[Direction.RIGHT] == cell2:
                res.append('E')
            elif cell.nighbors[Direction.DOWN] == cell2:
                res.append('S')
            elif cell.nighbors[Direction.LEFT] == cell2:
                res.append('W')
        res.append('\n')
        return ''.join(res)

    def generate_file(self, filename: str, include_seed: bool = False):
        with open(filename, 'w') as fd:
            for row in self.grid:
                line: str = ''
                for cell in row:
                    line += hex(int(cell.get_binary_walls(), 2))[2:]
                fd.write(line.upper() + '\n')
            fd.write("\n")
            fd.write(f"{self.entry[0]},{self.entry[1]}\n")
            fd.write(f"{self.exit[0]},{self.exit[1]}\n")
            fd.write(self.solution_to_directions())
            if include_seed:
                fd.write(f"\nSeed: {self.seed}\n")

    def generate_maze(self, algorithm: Optional[str] = None):
        if algorithm == 'DFS':
            self.depth_first_search()
        elif algorithm == 'Mouis':
            self.mouis()


if __name__ == "__main__":
    #  create a maze object
    maze: MazeGenerator = MazeGenerator(
        width=20, height=15, entry=(0, 0),
        exit=(19, 14), perfect=True)
    # now maze has a grid but its not a maze yet

    # let's turn it into a maze
    maze.generate_maze()