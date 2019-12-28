[ECell]
_def = enum <byte>
    {
        Empty,
        AreaWall,
        BlueWall,
        YellowWall
    }


[EDirection]
_def = enum <byte>
    {
        Up,
        Right,
        Down,
        Left
    }


[Constants]
_def = class
max_cycles = int
wall_creation_score_coefficient = float
area_wall_death_score = int
my_wall_death_score = int
enemy_wall_death_score = int


[Position]
_def = class
x = int
y = int


[Agent]
_def = class
position = Position
direction = EDirection


[World]
_def = class
board = list<list<ECell>>
agents = map<string, Agent>
scores = map<string, float>
constants = Constants
