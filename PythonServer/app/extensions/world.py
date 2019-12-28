# -*- coding: utf-8 -*-

# project imports
from ..ks.models import World
from ..gui_events import GuiEvent, GuiEventType


def apply_commands(self, commands):
    gui_events = []

    for side in commands:
        for command in commands[side].values():
            pass

    return gui_events


def tick(self):
    gui_events = []
    return gui_events


def check_end_game(self, current_cycle):
    return False


def get_winner(self):
    return None


World.apply_commands = apply_commands
World.tick = tick
World.check_end_game = check_end_game
World.get_winner = get_winner
