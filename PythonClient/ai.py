# -*- coding: utf-8 -*-

# python imports
import random

# chillin imports
from chillin_client import RealtimeAI

# project imports
from ks.models import ECell, EDirection, Position
from ks.commands import ChangeDirection, ActivateWallBreaker


class AI(RealtimeAI):

    def __init__(self, world):
        super(AI, self).__init__(world)


    def initialize(self):
        print('initialize')

        self.DIR_TO_POSITION = {
            EDirection.Up: Position(x=0, y=-1),
            EDirection.Right: Position(x=1, y=0),
            EDirection.Down: Position(x=0, y=1),
            EDirection.Left: Position(x=-1, y=0),
        }

        self.OPPOSITE_DIR = {
            EDirection.Up: EDirection.Down,
            EDirection.Down: EDirection.Up,
            EDirection.Right: EDirection.Left,
            EDirection.Left: EDirection.Right,
        }


    def decide(self):
        print('decide')

        empty_neighbors = self._get_neighbors(cell_type=[ECell.Empty])
        if len(empty_neighbors) > 0:
            self.send_command(ChangeDirection(random.choice(list(empty_neighbors.keys()))))
        else:
            if self.world.agents[self.my_side].wall_breaker_cooldown == 0:
                self.send_command(ActivateWallBreaker())

            enemy_walls = self._get_neighbors(cell_type=[ECell['{}Wall'.format(self.other_side)]])
            if len(enemy_walls) > 0:
                self.send_command(ChangeDirection(random.choice(list(enemy_walls.keys()))))
            else:
                my_walls = self._get_neighbors(cell_type=[ECell['{}Wall'.format(self.my_side)]])
                if len(my_walls) > 0:
                    self.send_command(ChangeDirection(random.choice(list(my_walls.keys()))))


    def _get_neighbors(self, cell_type=None):
        neighbors = {}

        for direction in EDirection:
            if direction == self.OPPOSITE_DIR[self.world.agents[self.my_side].direction]:
                continue

            neighbor_pos = self.world.agents[self.my_side].position + self.DIR_TO_POSITION[direction]
            if (0 <= neighbor_pos.x < len(self.world.board[0]) and 0 <= neighbor_pos.x < len(self.world.board[0]) and
                cell_type == None or self.world.board[neighbor_pos.y][neighbor_pos.x] in cell_type):
                neighbors[direction] = neighbor_pos

        return neighbors
