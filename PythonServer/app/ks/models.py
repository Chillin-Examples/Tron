# -*- coding: utf-8 -*-

# python imports
import sys
import struct
from enum import Enum

PY3 = sys.version_info > (3,)


class ECell(Enum):
	Empty = 0
	AreaWall = 1
	BlueWall = 2
	YellowWall = 3


class EDirection(Enum):
	Up = 0
	Right = 1
	Down = 2
	Left = 3


class Constants(object):

	@staticmethod
	def name():
		return 'Constants'


	def __init__(self, max_cycles=None, wall_creation_score_coefficient=None, area_wall_death_score=None, my_wall_death_score=None, enemy_wall_death_score=None):
		self.initialize(max_cycles, wall_creation_score_coefficient, area_wall_death_score, my_wall_death_score, enemy_wall_death_score)
	

	def initialize(self, max_cycles=None, wall_creation_score_coefficient=None, area_wall_death_score=None, my_wall_death_score=None, enemy_wall_death_score=None):
		self.max_cycles = max_cycles
		self.wall_creation_score_coefficient = wall_creation_score_coefficient
		self.area_wall_death_score = area_wall_death_score
		self.my_wall_death_score = my_wall_death_score
		self.enemy_wall_death_score = enemy_wall_death_score
	

	def serialize(self):
		s = b''
		
		# serialize self.max_cycles
		s += b'\x00' if self.max_cycles is None else b'\x01'
		if self.max_cycles is not None:
			s += struct.pack('i', self.max_cycles)
		
		# serialize self.wall_creation_score_coefficient
		s += b'\x00' if self.wall_creation_score_coefficient is None else b'\x01'
		if self.wall_creation_score_coefficient is not None:
			s += struct.pack('f', self.wall_creation_score_coefficient)
		
		# serialize self.area_wall_death_score
		s += b'\x00' if self.area_wall_death_score is None else b'\x01'
		if self.area_wall_death_score is not None:
			s += struct.pack('i', self.area_wall_death_score)
		
		# serialize self.my_wall_death_score
		s += b'\x00' if self.my_wall_death_score is None else b'\x01'
		if self.my_wall_death_score is not None:
			s += struct.pack('i', self.my_wall_death_score)
		
		# serialize self.enemy_wall_death_score
		s += b'\x00' if self.enemy_wall_death_score is None else b'\x01'
		if self.enemy_wall_death_score is not None:
			s += struct.pack('i', self.enemy_wall_death_score)
		
		return s
	

	def deserialize(self, s, offset=0):
		# deserialize self.max_cycles
		tmp0 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp0:
			self.max_cycles = struct.unpack('i', s[offset:offset + 4])[0]
			offset += 4
		else:
			self.max_cycles = None
		
		# deserialize self.wall_creation_score_coefficient
		tmp1 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp1:
			self.wall_creation_score_coefficient = struct.unpack('f', s[offset:offset + 4])[0]
			offset += 4
		else:
			self.wall_creation_score_coefficient = None
		
		# deserialize self.area_wall_death_score
		tmp2 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp2:
			self.area_wall_death_score = struct.unpack('i', s[offset:offset + 4])[0]
			offset += 4
		else:
			self.area_wall_death_score = None
		
		# deserialize self.my_wall_death_score
		tmp3 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp3:
			self.my_wall_death_score = struct.unpack('i', s[offset:offset + 4])[0]
			offset += 4
		else:
			self.my_wall_death_score = None
		
		# deserialize self.enemy_wall_death_score
		tmp4 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp4:
			self.enemy_wall_death_score = struct.unpack('i', s[offset:offset + 4])[0]
			offset += 4
		else:
			self.enemy_wall_death_score = None
		
		return offset


class Position(object):

	@staticmethod
	def name():
		return 'Position'


	def __init__(self, x=None, y=None):
		self.initialize(x, y)
	

	def initialize(self, x=None, y=None):
		self.x = x
		self.y = y
	

	def serialize(self):
		s = b''
		
		# serialize self.x
		s += b'\x00' if self.x is None else b'\x01'
		if self.x is not None:
			s += struct.pack('i', self.x)
		
		# serialize self.y
		s += b'\x00' if self.y is None else b'\x01'
		if self.y is not None:
			s += struct.pack('i', self.y)
		
		return s
	

	def deserialize(self, s, offset=0):
		# deserialize self.x
		tmp5 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp5:
			self.x = struct.unpack('i', s[offset:offset + 4])[0]
			offset += 4
		else:
			self.x = None
		
		# deserialize self.y
		tmp6 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp6:
			self.y = struct.unpack('i', s[offset:offset + 4])[0]
			offset += 4
		else:
			self.y = None
		
		return offset


class Agent(object):

	@staticmethod
	def name():
		return 'Agent'


	def __init__(self, position=None, direction=None):
		self.initialize(position, direction)
	

	def initialize(self, position=None, direction=None):
		self.position = position
		self.direction = direction
	

	def serialize(self):
		s = b''
		
		# serialize self.position
		s += b'\x00' if self.position is None else b'\x01'
		if self.position is not None:
			s += self.position.serialize()
		
		# serialize self.direction
		s += b'\x00' if self.direction is None else b'\x01'
		if self.direction is not None:
			s += struct.pack('b', self.direction.value)
		
		return s
	

	def deserialize(self, s, offset=0):
		# deserialize self.position
		tmp7 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp7:
			self.position = Position()
			offset = self.position.deserialize(s, offset)
		else:
			self.position = None
		
		# deserialize self.direction
		tmp8 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp8:
			tmp9 = struct.unpack('b', s[offset:offset + 1])[0]
			offset += 1
			self.direction = EDirection(tmp9)
		else:
			self.direction = None
		
		return offset


class World(object):

	@staticmethod
	def name():
		return 'World'


	def __init__(self, board=None, agents=None, scores=None, constants=None):
		self.initialize(board, agents, scores, constants)
	

	def initialize(self, board=None, agents=None, scores=None, constants=None):
		self.board = board
		self.agents = agents
		self.scores = scores
		self.constants = constants
	

	def serialize(self):
		s = b''
		
		# serialize self.board
		s += b'\x00' if self.board is None else b'\x01'
		if self.board is not None:
			tmp10 = b''
			tmp10 += struct.pack('I', len(self.board))
			while len(tmp10) and tmp10[-1] == b'\x00'[0]:
				tmp10 = tmp10[:-1]
			s += struct.pack('B', len(tmp10))
			s += tmp10
			
			for tmp11 in self.board:
				s += b'\x00' if tmp11 is None else b'\x01'
				if tmp11 is not None:
					tmp12 = b''
					tmp12 += struct.pack('I', len(tmp11))
					while len(tmp12) and tmp12[-1] == b'\x00'[0]:
						tmp12 = tmp12[:-1]
					s += struct.pack('B', len(tmp12))
					s += tmp12
					
					for tmp13 in tmp11:
						s += b'\x00' if tmp13 is None else b'\x01'
						if tmp13 is not None:
							s += struct.pack('b', tmp13.value)
		
		# serialize self.agents
		s += b'\x00' if self.agents is None else b'\x01'
		if self.agents is not None:
			tmp14 = b''
			tmp14 += struct.pack('I', len(self.agents))
			while len(tmp14) and tmp14[-1] == b'\x00'[0]:
				tmp14 = tmp14[:-1]
			s += struct.pack('B', len(tmp14))
			s += tmp14
			
			for tmp15 in self.agents:
				s += b'\x00' if tmp15 is None else b'\x01'
				if tmp15 is not None:
					tmp16 = b''
					tmp16 += struct.pack('I', len(tmp15))
					while len(tmp16) and tmp16[-1] == b'\x00'[0]:
						tmp16 = tmp16[:-1]
					s += struct.pack('B', len(tmp16))
					s += tmp16
					
					s += tmp15.encode('ISO-8859-1') if PY3 else tmp15
				s += b'\x00' if self.agents[tmp15] is None else b'\x01'
				if self.agents[tmp15] is not None:
					s += self.agents[tmp15].serialize()
		
		# serialize self.scores
		s += b'\x00' if self.scores is None else b'\x01'
		if self.scores is not None:
			tmp17 = b''
			tmp17 += struct.pack('I', len(self.scores))
			while len(tmp17) and tmp17[-1] == b'\x00'[0]:
				tmp17 = tmp17[:-1]
			s += struct.pack('B', len(tmp17))
			s += tmp17
			
			for tmp18 in self.scores:
				s += b'\x00' if tmp18 is None else b'\x01'
				if tmp18 is not None:
					tmp19 = b''
					tmp19 += struct.pack('I', len(tmp18))
					while len(tmp19) and tmp19[-1] == b'\x00'[0]:
						tmp19 = tmp19[:-1]
					s += struct.pack('B', len(tmp19))
					s += tmp19
					
					s += tmp18.encode('ISO-8859-1') if PY3 else tmp18
				s += b'\x00' if self.scores[tmp18] is None else b'\x01'
				if self.scores[tmp18] is not None:
					s += struct.pack('f', self.scores[tmp18])
		
		# serialize self.constants
		s += b'\x00' if self.constants is None else b'\x01'
		if self.constants is not None:
			s += self.constants.serialize()
		
		return s
	

	def deserialize(self, s, offset=0):
		# deserialize self.board
		tmp20 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp20:
			tmp21 = struct.unpack('B', s[offset:offset + 1])[0]
			offset += 1
			tmp22 = s[offset:offset + tmp21]
			offset += tmp21
			tmp22 += b'\x00' * (4 - tmp21)
			tmp23 = struct.unpack('I', tmp22)[0]
			
			self.board = []
			for tmp24 in range(tmp23):
				tmp26 = struct.unpack('B', s[offset:offset + 1])[0]
				offset += 1
				if tmp26:
					tmp27 = struct.unpack('B', s[offset:offset + 1])[0]
					offset += 1
					tmp28 = s[offset:offset + tmp27]
					offset += tmp27
					tmp28 += b'\x00' * (4 - tmp27)
					tmp29 = struct.unpack('I', tmp28)[0]
					
					tmp25 = []
					for tmp30 in range(tmp29):
						tmp32 = struct.unpack('B', s[offset:offset + 1])[0]
						offset += 1
						if tmp32:
							tmp33 = struct.unpack('b', s[offset:offset + 1])[0]
							offset += 1
							tmp31 = ECell(tmp33)
						else:
							tmp31 = None
						tmp25.append(tmp31)
				else:
					tmp25 = None
				self.board.append(tmp25)
		else:
			self.board = None
		
		# deserialize self.agents
		tmp34 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp34:
			tmp35 = struct.unpack('B', s[offset:offset + 1])[0]
			offset += 1
			tmp36 = s[offset:offset + tmp35]
			offset += tmp35
			tmp36 += b'\x00' * (4 - tmp35)
			tmp37 = struct.unpack('I', tmp36)[0]
			
			self.agents = {}
			for tmp38 in range(tmp37):
				tmp41 = struct.unpack('B', s[offset:offset + 1])[0]
				offset += 1
				if tmp41:
					tmp42 = struct.unpack('B', s[offset:offset + 1])[0]
					offset += 1
					tmp43 = s[offset:offset + tmp42]
					offset += tmp42
					tmp43 += b'\x00' * (4 - tmp42)
					tmp44 = struct.unpack('I', tmp43)[0]
					
					tmp39 = s[offset:offset + tmp44].decode('ISO-8859-1') if PY3 else s[offset:offset + tmp44]
					offset += tmp44
				else:
					tmp39 = None
				tmp45 = struct.unpack('B', s[offset:offset + 1])[0]
				offset += 1
				if tmp45:
					tmp40 = Agent()
					offset = tmp40.deserialize(s, offset)
				else:
					tmp40 = None
				self.agents[tmp39] = tmp40
		else:
			self.agents = None
		
		# deserialize self.scores
		tmp46 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp46:
			tmp47 = struct.unpack('B', s[offset:offset + 1])[0]
			offset += 1
			tmp48 = s[offset:offset + tmp47]
			offset += tmp47
			tmp48 += b'\x00' * (4 - tmp47)
			tmp49 = struct.unpack('I', tmp48)[0]
			
			self.scores = {}
			for tmp50 in range(tmp49):
				tmp53 = struct.unpack('B', s[offset:offset + 1])[0]
				offset += 1
				if tmp53:
					tmp54 = struct.unpack('B', s[offset:offset + 1])[0]
					offset += 1
					tmp55 = s[offset:offset + tmp54]
					offset += tmp54
					tmp55 += b'\x00' * (4 - tmp54)
					tmp56 = struct.unpack('I', tmp55)[0]
					
					tmp51 = s[offset:offset + tmp56].decode('ISO-8859-1') if PY3 else s[offset:offset + tmp56]
					offset += tmp56
				else:
					tmp51 = None
				tmp57 = struct.unpack('B', s[offset:offset + 1])[0]
				offset += 1
				if tmp57:
					tmp52 = struct.unpack('f', s[offset:offset + 4])[0]
					offset += 4
				else:
					tmp52 = None
				self.scores[tmp51] = tmp52
		else:
			self.scores = None
		
		# deserialize self.constants
		tmp58 = struct.unpack('B', s[offset:offset + 1])[0]
		offset += 1
		if tmp58:
			self.constants = Constants()
			offset = self.constants.deserialize(s, offset)
		else:
			self.constants = None
		
		return offset
