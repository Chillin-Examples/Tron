# -*- coding: utf-8 -*-

# python imports
from __future__ import division
import math

# chillin imports
from chillin_server.gui import GuiTools, scene_actions
from chillin_server.gui.reference_manager import default_reference_manager as drm

# project imports
# from ..ks.models import
from ..gui_events import GuiEventType


class GuiHandler:

    def __init__(self, world, scene):
        self._world = world
        self._scene = scene


    def initialize(self, config):
        self._configure(config)
        self._init_camera()
        self._init_sounds()
        self._init_board()

        self._scene.add_action(scene_actions.EndCycle())


    def _configure(self, config):
        pass  # TODO: fill function


    def _init_camera(self):
        pass  # TODO: fill function


    def _init_sounds(self):
        pass  # TODO: fill function


    def _init_board(self):
        pass  # TODO: fill function


    def update(self, current_cycle, events):
        # Manage events
        for event in events:
            pass #  TODO: Manage events
