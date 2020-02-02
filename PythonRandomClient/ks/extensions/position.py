# -*- coding: utf-8 -*-

# project imports
from ..models import Position


def __eq__(self, other):
    if isinstance(other, Position):
        return self.x == other.x and self.y == other.y
    return NotImplemented


def __ne__(self, other):
    r = self.__eq__(other)
    if r is not NotImplemented:
        return not r
    return NotImplemented


def __hash__(self):
    return hash(tuple(sorted(self.__dict__.items())))


def __add__(self, other):
    if isinstance(other, Position):
        return Position(self.x + other.x, self.y + other.y)
    return NotImplemented


def __sub__(self, other):
    if isinstance(other, Position):
        return Position(self.x - other.x, self.y - other.y)
    return NotImplemented


def __repr__(self):
    return "<x: %s, y: %s>" % (self.x, self.y)


Position.__eq__ = __eq__
Position.__ne__ = __ne__
Position.__hash__ = __hash__
Position.__add__ = __add__
Position.__sub__ = __sub__
Position.__repr__ = __repr__
