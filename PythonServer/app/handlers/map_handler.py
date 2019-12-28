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
        pass


    def _fill_constants(self, world, board_info):
        pass


    def _fill_agents(self, world, board_info):
        pass


    def load_map(self, config):
        with open((config['map_path']), 'r') as map_file:
            map_info = json.loads(map_file.read())

        world = World()
        world.scores = {side: 0 for side in self._sides}

        self._fill_board(world, map_info['board'])
        self._fill_constants(world, map_info['constants'])
        self._fill_agents(world, map_info['agents'])

        return world
