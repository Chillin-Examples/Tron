#ifndef _KS_MODELS_H_
#define _KS_MODELS_H_

#include <string>
#include <vector>
#include <map>
#include <array>


namespace ks
{

#ifndef _KS_OBJECT_
#define _KS_OBJECT_

class KSObject
{
public:
	static inline const std::string nameStatic() { return ""; }
	virtual inline const std::string name() const = 0;
	virtual std::string serialize() const = 0;
	virtual unsigned int deserialize(const std::string &, unsigned int = 0) = 0;
};

#endif // _KS_OBJECT_


namespace models
{

enum class ECell
{
	Empty = 0,
	AreaWall = 1,
	BlueWall = 2,
	YellowWall = 3,
};


enum class EDirection
{
	Up = 0,
	Right = 1,
	Down = 2,
	Left = 3,
};


class Constants : public KSObject
{

protected:

	int __maxCycles;
	float __wallCreationScoreCoefficient;
	int __areaWallCrashScore;
	int __myWallCrashScore;
	int __enemyWallCrashScore;

	bool __has_maxCycles;
	bool __has_wallCreationScoreCoefficient;
	bool __has_areaWallCrashScore;
	bool __has_myWallCrashScore;
	bool __has_enemyWallCrashScore;


public: // getters

	inline int maxCycles() const
	{
		return __maxCycles;
	}
	
	inline float wallCreationScoreCoefficient() const
	{
		return __wallCreationScoreCoefficient;
	}
	
	inline int areaWallCrashScore() const
	{
		return __areaWallCrashScore;
	}
	
	inline int myWallCrashScore() const
	{
		return __myWallCrashScore;
	}
	
	inline int enemyWallCrashScore() const
	{
		return __enemyWallCrashScore;
	}
	

public: // reference getters

	inline int &ref_maxCycles() const
	{
		return (int&) __maxCycles;
	}
	
	inline float &ref_wallCreationScoreCoefficient() const
	{
		return (float&) __wallCreationScoreCoefficient;
	}
	
	inline int &ref_areaWallCrashScore() const
	{
		return (int&) __areaWallCrashScore;
	}
	
	inline int &ref_myWallCrashScore() const
	{
		return (int&) __myWallCrashScore;
	}
	
	inline int &ref_enemyWallCrashScore() const
	{
		return (int&) __enemyWallCrashScore;
	}
	

public: // setters

	inline void maxCycles(const int &maxCycles)
	{
		__maxCycles = maxCycles;
		has_maxCycles(true);
	}
	
	inline void wallCreationScoreCoefficient(const float &wallCreationScoreCoefficient)
	{
		__wallCreationScoreCoefficient = wallCreationScoreCoefficient;
		has_wallCreationScoreCoefficient(true);
	}
	
	inline void areaWallCrashScore(const int &areaWallCrashScore)
	{
		__areaWallCrashScore = areaWallCrashScore;
		has_areaWallCrashScore(true);
	}
	
	inline void myWallCrashScore(const int &myWallCrashScore)
	{
		__myWallCrashScore = myWallCrashScore;
		has_myWallCrashScore(true);
	}
	
	inline void enemyWallCrashScore(const int &enemyWallCrashScore)
	{
		__enemyWallCrashScore = enemyWallCrashScore;
		has_enemyWallCrashScore(true);
	}
	

public: // has_attribute getters

	inline bool has_maxCycles() const
	{
		return __has_maxCycles;
	}
	
	inline bool has_wallCreationScoreCoefficient() const
	{
		return __has_wallCreationScoreCoefficient;
	}
	
	inline bool has_areaWallCrashScore() const
	{
		return __has_areaWallCrashScore;
	}
	
	inline bool has_myWallCrashScore() const
	{
		return __has_myWallCrashScore;
	}
	
	inline bool has_enemyWallCrashScore() const
	{
		return __has_enemyWallCrashScore;
	}
	

public: // has_attribute setters

	inline void has_maxCycles(const bool &has_maxCycles)
	{
		__has_maxCycles = has_maxCycles;
	}
	
	inline void has_wallCreationScoreCoefficient(const bool &has_wallCreationScoreCoefficient)
	{
		__has_wallCreationScoreCoefficient = has_wallCreationScoreCoefficient;
	}
	
	inline void has_areaWallCrashScore(const bool &has_areaWallCrashScore)
	{
		__has_areaWallCrashScore = has_areaWallCrashScore;
	}
	
	inline void has_myWallCrashScore(const bool &has_myWallCrashScore)
	{
		__has_myWallCrashScore = has_myWallCrashScore;
	}
	
	inline void has_enemyWallCrashScore(const bool &has_enemyWallCrashScore)
	{
		__has_enemyWallCrashScore = has_enemyWallCrashScore;
	}
	

public:

	Constants()
	{
		has_maxCycles(false);
		has_wallCreationScoreCoefficient(false);
		has_areaWallCrashScore(false);
		has_myWallCrashScore(false);
		has_enemyWallCrashScore(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "Constants";
	}
	
	virtual inline const std::string name() const
	{
		return "Constants";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize maxCycles
		s += __has_maxCycles;
		if (__has_maxCycles)
		{
			int tmp1 = __maxCycles;
			auto tmp2 = reinterpret_cast<char*>(&tmp1);
			s += std::string(tmp2, sizeof(int));
		}
		
		// serialize wallCreationScoreCoefficient
		s += __has_wallCreationScoreCoefficient;
		if (__has_wallCreationScoreCoefficient)
		{
			float tmp4 = __wallCreationScoreCoefficient;
			auto tmp5 = reinterpret_cast<char*>(&tmp4);
			s += std::string(tmp5, sizeof(float));
		}
		
		// serialize areaWallCrashScore
		s += __has_areaWallCrashScore;
		if (__has_areaWallCrashScore)
		{
			int tmp7 = __areaWallCrashScore;
			auto tmp8 = reinterpret_cast<char*>(&tmp7);
			s += std::string(tmp8, sizeof(int));
		}
		
		// serialize myWallCrashScore
		s += __has_myWallCrashScore;
		if (__has_myWallCrashScore)
		{
			int tmp10 = __myWallCrashScore;
			auto tmp11 = reinterpret_cast<char*>(&tmp10);
			s += std::string(tmp11, sizeof(int));
		}
		
		// serialize enemyWallCrashScore
		s += __has_enemyWallCrashScore;
		if (__has_enemyWallCrashScore)
		{
			int tmp13 = __enemyWallCrashScore;
			auto tmp14 = reinterpret_cast<char*>(&tmp13);
			s += std::string(tmp14, sizeof(int));
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize maxCycles
		__has_maxCycles = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_maxCycles)
		{
			__maxCycles = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize wallCreationScoreCoefficient
		__has_wallCreationScoreCoefficient = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_wallCreationScoreCoefficient)
		{
			__wallCreationScoreCoefficient = *((float*) (&s[offset]));
			offset += sizeof(float);
		}
		
		// deserialize areaWallCrashScore
		__has_areaWallCrashScore = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_areaWallCrashScore)
		{
			__areaWallCrashScore = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize myWallCrashScore
		__has_myWallCrashScore = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_myWallCrashScore)
		{
			__myWallCrashScore = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize enemyWallCrashScore
		__has_enemyWallCrashScore = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_enemyWallCrashScore)
		{
			__enemyWallCrashScore = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		return offset;
	}
};


class Position : public KSObject
{

protected:

	int __x;
	int __y;

	bool __has_x;
	bool __has_y;


public: // getters

	inline int x() const
	{
		return __x;
	}
	
	inline int y() const
	{
		return __y;
	}
	

public: // reference getters

	inline int &ref_x() const
	{
		return (int&) __x;
	}
	
	inline int &ref_y() const
	{
		return (int&) __y;
	}
	

public: // setters

	inline void x(const int &x)
	{
		__x = x;
		has_x(true);
	}
	
	inline void y(const int &y)
	{
		__y = y;
		has_y(true);
	}
	

public: // has_attribute getters

	inline bool has_x() const
	{
		return __has_x;
	}
	
	inline bool has_y() const
	{
		return __has_y;
	}
	

public: // has_attribute setters

	inline void has_x(const bool &has_x)
	{
		__has_x = has_x;
	}
	
	inline void has_y(const bool &has_y)
	{
		__has_y = has_y;
	}
	

public:

	Position()
	{
		has_x(false);
		has_y(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "Position";
	}
	
	virtual inline const std::string name() const
	{
		return "Position";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize x
		s += __has_x;
		if (__has_x)
		{
			int tmp16 = __x;
			auto tmp17 = reinterpret_cast<char*>(&tmp16);
			s += std::string(tmp17, sizeof(int));
		}
		
		// serialize y
		s += __has_y;
		if (__has_y)
		{
			int tmp19 = __y;
			auto tmp20 = reinterpret_cast<char*>(&tmp19);
			s += std::string(tmp20, sizeof(int));
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize x
		__has_x = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_x)
		{
			__x = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		// deserialize y
		__has_y = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_y)
		{
			__y = *((int*) (&s[offset]));
			offset += sizeof(int);
		}
		
		return offset;
	}
};


class Agent : public KSObject
{

protected:

	Position __position;
	EDirection __direction;

	bool __has_position;
	bool __has_direction;


public: // getters

	inline Position position() const
	{
		return __position;
	}
	
	inline EDirection direction() const
	{
		return __direction;
	}
	

public: // reference getters

	inline Position &ref_position() const
	{
		return (Position&) __position;
	}
	
	inline EDirection &ref_direction() const
	{
		return (EDirection&) __direction;
	}
	

public: // setters

	inline void position(const Position &position)
	{
		__position = position;
		has_position(true);
	}
	
	inline void direction(const EDirection &direction)
	{
		__direction = direction;
		has_direction(true);
	}
	

public: // has_attribute getters

	inline bool has_position() const
	{
		return __has_position;
	}
	
	inline bool has_direction() const
	{
		return __has_direction;
	}
	

public: // has_attribute setters

	inline void has_position(const bool &has_position)
	{
		__has_position = has_position;
	}
	
	inline void has_direction(const bool &has_direction)
	{
		__has_direction = has_direction;
	}
	

public:

	Agent()
	{
		has_position(false);
		has_direction(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "Agent";
	}
	
	virtual inline const std::string name() const
	{
		return "Agent";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize position
		s += __has_position;
		if (__has_position)
		{
			s += __position.serialize();
		}
		
		// serialize direction
		s += __has_direction;
		if (__has_direction)
		{
			char tmp22 = (char) __direction;
			auto tmp23 = reinterpret_cast<char*>(&tmp22);
			s += std::string(tmp23, sizeof(char));
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize position
		__has_position = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_position)
		{
			offset = __position.deserialize(s, offset);
		}
		
		// deserialize direction
		__has_direction = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_direction)
		{
			char tmp24;
			tmp24 = *((char*) (&s[offset]));
			offset += sizeof(char);
			__direction = (EDirection) tmp24;
		}
		
		return offset;
	}
};


class World : public KSObject
{

protected:

	std::vector<std::vector<ECell>> __board;
	std::map<std::string, Agent> __agents;
	std::map<std::string, float> __scores;
	Constants __constants;

	bool __has_board;
	bool __has_agents;
	bool __has_scores;
	bool __has_constants;


public: // getters

	inline std::vector<std::vector<ECell>> board() const
	{
		return __board;
	}
	
	inline std::map<std::string, Agent> agents() const
	{
		return __agents;
	}
	
	inline std::map<std::string, float> scores() const
	{
		return __scores;
	}
	
	inline Constants constants() const
	{
		return __constants;
	}
	

public: // reference getters

	inline std::vector<std::vector<ECell>> &ref_board() const
	{
		return (std::vector<std::vector<ECell>>&) __board;
	}
	
	inline std::map<std::string, Agent> &ref_agents() const
	{
		return (std::map<std::string, Agent>&) __agents;
	}
	
	inline std::map<std::string, float> &ref_scores() const
	{
		return (std::map<std::string, float>&) __scores;
	}
	
	inline Constants &ref_constants() const
	{
		return (Constants&) __constants;
	}
	

public: // setters

	inline void board(const std::vector<std::vector<ECell>> &board)
	{
		__board = board;
		has_board(true);
	}
	
	inline void agents(const std::map<std::string, Agent> &agents)
	{
		__agents = agents;
		has_agents(true);
	}
	
	inline void scores(const std::map<std::string, float> &scores)
	{
		__scores = scores;
		has_scores(true);
	}
	
	inline void constants(const Constants &constants)
	{
		__constants = constants;
		has_constants(true);
	}
	

public: // has_attribute getters

	inline bool has_board() const
	{
		return __has_board;
	}
	
	inline bool has_agents() const
	{
		return __has_agents;
	}
	
	inline bool has_scores() const
	{
		return __has_scores;
	}
	
	inline bool has_constants() const
	{
		return __has_constants;
	}
	

public: // has_attribute setters

	inline void has_board(const bool &has_board)
	{
		__has_board = has_board;
	}
	
	inline void has_agents(const bool &has_agents)
	{
		__has_agents = has_agents;
	}
	
	inline void has_scores(const bool &has_scores)
	{
		__has_scores = has_scores;
	}
	
	inline void has_constants(const bool &has_constants)
	{
		__has_constants = has_constants;
	}
	

public:

	World()
	{
		has_board(false);
		has_agents(false);
		has_scores(false);
		has_constants(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "World";
	}
	
	virtual inline const std::string name() const
	{
		return "World";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize board
		s += __has_board;
		if (__has_board)
		{
			std::string tmp25 = "";
			unsigned int tmp27 = __board.size();
			auto tmp28 = reinterpret_cast<char*>(&tmp27);
			tmp25 += std::string(tmp28, sizeof(unsigned int));
			while (tmp25.size() && tmp25.back() == 0)
				tmp25.pop_back();
			unsigned char tmp30 = tmp25.size();
			auto tmp31 = reinterpret_cast<char*>(&tmp30);
			s += std::string(tmp31, sizeof(unsigned char));
			s += tmp25;
			
			for (auto &tmp32 : __board)
			{
				s += '\x01';
				std::string tmp33 = "";
				unsigned int tmp35 = tmp32.size();
				auto tmp36 = reinterpret_cast<char*>(&tmp35);
				tmp33 += std::string(tmp36, sizeof(unsigned int));
				while (tmp33.size() && tmp33.back() == 0)
					tmp33.pop_back();
				unsigned char tmp38 = tmp33.size();
				auto tmp39 = reinterpret_cast<char*>(&tmp38);
				s += std::string(tmp39, sizeof(unsigned char));
				s += tmp33;
				
				for (auto &tmp40 : tmp32)
				{
					s += '\x01';
					char tmp42 = (char) tmp40;
					auto tmp43 = reinterpret_cast<char*>(&tmp42);
					s += std::string(tmp43, sizeof(char));
				}
			}
		}
		
		// serialize agents
		s += __has_agents;
		if (__has_agents)
		{
			std::string tmp44 = "";
			unsigned int tmp46 = __agents.size();
			auto tmp47 = reinterpret_cast<char*>(&tmp46);
			tmp44 += std::string(tmp47, sizeof(unsigned int));
			while (tmp44.size() && tmp44.back() == 0)
				tmp44.pop_back();
			unsigned char tmp49 = tmp44.size();
			auto tmp50 = reinterpret_cast<char*>(&tmp49);
			s += std::string(tmp50, sizeof(unsigned char));
			s += tmp44;
			
			for (auto &tmp51 : __agents)
			{
				s += '\x01';
				std::string tmp52 = "";
				unsigned int tmp54 = tmp51.first.size();
				auto tmp55 = reinterpret_cast<char*>(&tmp54);
				tmp52 += std::string(tmp55, sizeof(unsigned int));
				while (tmp52.size() && tmp52.back() == 0)
					tmp52.pop_back();
				unsigned char tmp57 = tmp52.size();
				auto tmp58 = reinterpret_cast<char*>(&tmp57);
				s += std::string(tmp58, sizeof(unsigned char));
				s += tmp52;
				
				s += tmp51.first;
				
				s += '\x01';
				s += tmp51.second.serialize();
			}
		}
		
		// serialize scores
		s += __has_scores;
		if (__has_scores)
		{
			std::string tmp59 = "";
			unsigned int tmp61 = __scores.size();
			auto tmp62 = reinterpret_cast<char*>(&tmp61);
			tmp59 += std::string(tmp62, sizeof(unsigned int));
			while (tmp59.size() && tmp59.back() == 0)
				tmp59.pop_back();
			unsigned char tmp64 = tmp59.size();
			auto tmp65 = reinterpret_cast<char*>(&tmp64);
			s += std::string(tmp65, sizeof(unsigned char));
			s += tmp59;
			
			for (auto &tmp66 : __scores)
			{
				s += '\x01';
				std::string tmp67 = "";
				unsigned int tmp69 = tmp66.first.size();
				auto tmp70 = reinterpret_cast<char*>(&tmp69);
				tmp67 += std::string(tmp70, sizeof(unsigned int));
				while (tmp67.size() && tmp67.back() == 0)
					tmp67.pop_back();
				unsigned char tmp72 = tmp67.size();
				auto tmp73 = reinterpret_cast<char*>(&tmp72);
				s += std::string(tmp73, sizeof(unsigned char));
				s += tmp67;
				
				s += tmp66.first;
				
				s += '\x01';
				float tmp75 = tmp66.second;
				auto tmp76 = reinterpret_cast<char*>(&tmp75);
				s += std::string(tmp76, sizeof(float));
			}
		}
		
		// serialize constants
		s += __has_constants;
		if (__has_constants)
		{
			s += __constants.serialize();
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize board
		__has_board = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_board)
		{
			unsigned char tmp77;
			tmp77 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp78 = std::string(&s[offset], tmp77);
			offset += tmp77;
			while (tmp78.size() < sizeof(unsigned int))
				tmp78 += '\x00';
			unsigned int tmp79;
			tmp79 = *((unsigned int*) (&tmp78[0]));
			
			__board.clear();
			for (unsigned int tmp80 = 0; tmp80 < tmp79; tmp80++)
			{
				std::vector<ECell> tmp81;
				offset++;
				unsigned char tmp82;
				tmp82 = *((unsigned char*) (&s[offset]));
				offset += sizeof(unsigned char);
				std::string tmp83 = std::string(&s[offset], tmp82);
				offset += tmp82;
				while (tmp83.size() < sizeof(unsigned int))
					tmp83 += '\x00';
				unsigned int tmp84;
				tmp84 = *((unsigned int*) (&tmp83[0]));
				
				tmp81.clear();
				for (unsigned int tmp85 = 0; tmp85 < tmp84; tmp85++)
				{
					ECell tmp86;
					offset++;
					char tmp87;
					tmp87 = *((char*) (&s[offset]));
					offset += sizeof(char);
					tmp86 = (ECell) tmp87;
					tmp81.push_back(tmp86);
				}
				__board.push_back(tmp81);
			}
		}
		
		// deserialize agents
		__has_agents = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_agents)
		{
			unsigned char tmp88;
			tmp88 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp89 = std::string(&s[offset], tmp88);
			offset += tmp88;
			while (tmp89.size() < sizeof(unsigned int))
				tmp89 += '\x00';
			unsigned int tmp90;
			tmp90 = *((unsigned int*) (&tmp89[0]));
			
			__agents.clear();
			for (unsigned int tmp91 = 0; tmp91 < tmp90; tmp91++)
			{
				std::string tmp92;
				offset++;
				unsigned char tmp94;
				tmp94 = *((unsigned char*) (&s[offset]));
				offset += sizeof(unsigned char);
				std::string tmp95 = std::string(&s[offset], tmp94);
				offset += tmp94;
				while (tmp95.size() < sizeof(unsigned int))
					tmp95 += '\x00';
				unsigned int tmp96;
				tmp96 = *((unsigned int*) (&tmp95[0]));
				
				tmp92 = s.substr(offset, tmp96);
				offset += tmp96;
				
				Agent tmp93;
				offset++;
				offset = tmp93.deserialize(s, offset);
				
				__agents[tmp92] = tmp93;
			}
		}
		
		// deserialize scores
		__has_scores = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_scores)
		{
			unsigned char tmp97;
			tmp97 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp98 = std::string(&s[offset], tmp97);
			offset += tmp97;
			while (tmp98.size() < sizeof(unsigned int))
				tmp98 += '\x00';
			unsigned int tmp99;
			tmp99 = *((unsigned int*) (&tmp98[0]));
			
			__scores.clear();
			for (unsigned int tmp100 = 0; tmp100 < tmp99; tmp100++)
			{
				std::string tmp101;
				offset++;
				unsigned char tmp103;
				tmp103 = *((unsigned char*) (&s[offset]));
				offset += sizeof(unsigned char);
				std::string tmp104 = std::string(&s[offset], tmp103);
				offset += tmp103;
				while (tmp104.size() < sizeof(unsigned int))
					tmp104 += '\x00';
				unsigned int tmp105;
				tmp105 = *((unsigned int*) (&tmp104[0]));
				
				tmp101 = s.substr(offset, tmp105);
				offset += tmp105;
				
				float tmp102;
				offset++;
				tmp102 = *((float*) (&s[offset]));
				offset += sizeof(float);
				
				__scores[tmp101] = tmp102;
			}
		}
		
		// deserialize constants
		__has_constants = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_constants)
		{
			offset = __constants.deserialize(s, offset);
		}
		
		return offset;
	}
};

} // namespace models

} // namespace ks

#endif // _KS_MODELS_H_
