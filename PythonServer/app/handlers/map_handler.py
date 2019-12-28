# -*- coding: utf-8 -*-

# python imports
import os
import json

# project imports
from ..ks.models import *


class MapHandler:

    def __init__(self, sides):
        self._sides = sides


    def _fill_board(self, world, board_info):
        width = board_info['width']
        height = board_info['height']

        world.board = [
            [
                ECell.AreaWall if (x == 0 or x == width-1 or y == 0 or y == height-1) else ECell.Empty 
                for x in range(width)
            ]
            for y in range(height)
        ]

        for wall_info in board_info['walls']:
            tl_x = wall_info['top_left']['x']
            tl_y = wall_info['top_left']['y']
            br_x = wall_info['bottom_right']['x']
            br_y = wall_info['bottom_right']['y']

            for y in range(tl_y, br_y + 1):
                for x in range(tl_x, br_x + 1):
                    world.board[y][x] = ECell.AreaWall


    def _fill_constants(self, world, constants_info):
        world.constants = Constants(
            max_cycles = constants_info['max_cycles'],
            wall_creation_score_coefficient = constants_info['wall_creation_score_coefficient'],
            area_wall_death_score = constants_info['area_wall_death_score'],
            my_wall_death_score = constants_info['my_wall_death_score'],
            enemy_wall_death_score = constants_info['enemy_wall_death_score']
        )


    def _fill_agents(self, world, agents_info):
        world.agents = {}
        for side, agent_info in agents_info.items():
            agent = Agent(
                position = Position(agent_info['position']['x'], agent_info['position']['y']),
                direction = EDirection[agent_info['direction']]
            )
            world.agents[side] = agent


    def load_map(self, config):
        with open((config['map_path']), 'r') as map_file:
            map_info = json.loads(map_file.read())

        world = World()
        world.scores = {side: 0. for side in self._sides}

        self._fill_board(world, map_info['board'])
        self._fill_constants(world, map_info['constants'])
        self._fill_agents(world, map_info['agents'])

        return world
