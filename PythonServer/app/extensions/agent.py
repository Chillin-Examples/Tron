# -*- coding: utf-8 -*-

# project imports
from ..ks.models import Agent, Position, ECell
from ..gui_events import GuiEvent, GuiEventType


def change_direction(self, world, side, direction):
    if self.direction in [direction, direction.opposite()] :
        return []

    self.direction = direction
    return [GuiEvent(GuiEventType.ChangeDirection, side=side, agent=self)]


def construct_wall(self, world, side):
    my_cell_name = side + "Wall"
    my_cell_type = ECell[my_cell_name]
    world.board[self.position.y][self.position.x] = my_cell_type
    return [GuiEvent(GuiEventType.ConstructWall, position=self.position)]


def move(self, world, side):
    self._prev_position = self.position
    self.position += Position.dir_to_pos(self.direction)
    return []


def check_crash_wall(self, world, side):
    if world.board[self.position.y][self.position.x] != ECell.Empty:
        return True


def check_crash_agent(self, world, side):
    agents = list(world.agents.values())

    if (agents[0]._prev_position == agents[1].position and
        agents[1]._prev_position == agents[0].position):
        return True

    return agents[0].position == agents[1].position


def handle_crash(self, world, side):
    # CrashEnemyAgent
    if self.check_crash_agent(world, side):
        return [GuiEvent(GuiEventType.CrashEnemyAgent)]

    # CrashAreaWall
    if world.board[self.position.y][self.position.x] == ECell.AreaWall:
        world.scores[side] += world.constants.area_wall_crash_score
        return [GuiEvent(GuiEventType.CrashAreaWall, side=side, agent=self)]

    # CrashMyWall
    my_cell_name = side + "Wall"
    my_cell_type = ECell[my_cell_name]

    if world.board[self.position.y][self.position.x] == my_cell_type:
        world.scores[side] += world.constants.my_wall_crash_score
        return [GuiEvent(GuiEventType.CrashMyWall, side=side, agent=self)]

    # CrashEnemyWall
    enemy_side = [s for s in world.agents.keys() if s != side][0]
    enemy_cell_name = enemy_side + "Wall"
    enemy_cell_type = ECell[enemy_cell_name]

    if world.board[self.position.y][self.position.x] == enemy_cell_type:
        world.scores[side] += world.constants.enemy_wall_crash_score
        return [GuiEvent(GuiEventType.CrashEnemyWall, side=side, agent=self)]

    return []


Agent.change_direction = change_direction
Agent.construct_wall = construct_wall
Agent.move = move
Agent.check_crash_wall = check_crash_wall
Agent.check_crash_agent = check_crash_agent
Agent.handle_crash = handle_crash
