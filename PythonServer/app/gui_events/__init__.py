# -*- coding: utf-8 -*-

# python imports
from enum import Enum


class GuiEventType(Enum):
    ChangeDirection = 0
    CrashAreaWall = 1
    CrashMyWall = 2
    CrashEnemyWall = 3
    CaptureArea = 4



class GuiEvent(object):

    def __init__(self, type, **kwargs):
        self.type = type
        self.__dict__.update(kwargs)
