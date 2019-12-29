using System;
using System.Linq;
using System.Collections.Generic;

namespace KS.Models
{
	public enum ECell
	{
		Empty = 0,
		AreaWall = 1,
		BlueWall = 2,
		YellowWall = 3,
	}
	
	public enum EDirection
	{
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3,
	}
	
	public partial class Constants : KSObject
	{
		public int? MaxCycles { get; set; }
		public float? WallCreationScoreCoefficient { get; set; }
		public int? AreaWallCrashScore { get; set; }
		public int? MyWallCrashScore { get; set; }
		public int? EnemyWallCrashScore { get; set; }
		

		public Constants()
		{
		}
		
		public new const string NameStatic = "Constants";
		
		public override string Name() => "Constants";
		
		public override byte[] Serialize()
		{
			List<byte> s = new List<byte>();
			
			// serialize MaxCycles
			s.Add((byte)((MaxCycles == null) ? 0 : 1));
			if (MaxCycles != null)
			{
				s.AddRange(BitConverter.GetBytes((int)MaxCycles));
			}
			
			// serialize WallCreationScoreCoefficient
			s.Add((byte)((WallCreationScoreCoefficient == null) ? 0 : 1));
			if (WallCreationScoreCoefficient != null)
			{
				s.AddRange(BitConverter.GetBytes((float)WallCreationScoreCoefficient));
			}
			
			// serialize AreaWallCrashScore
			s.Add((byte)((AreaWallCrashScore == null) ? 0 : 1));
			if (AreaWallCrashScore != null)
			{
				s.AddRange(BitConverter.GetBytes((int)AreaWallCrashScore));
			}
			
			// serialize MyWallCrashScore
			s.Add((byte)((MyWallCrashScore == null) ? 0 : 1));
			if (MyWallCrashScore != null)
			{
				s.AddRange(BitConverter.GetBytes((int)MyWallCrashScore));
			}
			
			// serialize EnemyWallCrashScore
			s.Add((byte)((EnemyWallCrashScore == null) ? 0 : 1));
			if (EnemyWallCrashScore != null)
			{
				s.AddRange(BitConverter.GetBytes((int)EnemyWallCrashScore));
			}
			
			return s.ToArray();
		}
		
		public override uint Deserialize(byte[] s, uint offset = 0)
		{
			// deserialize MaxCycles
			byte tmp0;
			tmp0 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp0 == 1)
			{
				MaxCycles = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				MaxCycles = null;
			
			// deserialize WallCreationScoreCoefficient
			byte tmp1;
			tmp1 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp1 == 1)
			{
				WallCreationScoreCoefficient = BitConverter.ToSingle(s, (int)offset);
				offset += sizeof(float);
			}
			else
				WallCreationScoreCoefficient = null;
			
			// deserialize AreaWallCrashScore
			byte tmp2;
			tmp2 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp2 == 1)
			{
				AreaWallCrashScore = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				AreaWallCrashScore = null;
			
			// deserialize MyWallCrashScore
			byte tmp3;
			tmp3 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp3 == 1)
			{
				MyWallCrashScore = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				MyWallCrashScore = null;
			
			// deserialize EnemyWallCrashScore
			byte tmp4;
			tmp4 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp4 == 1)
			{
				EnemyWallCrashScore = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				EnemyWallCrashScore = null;
			
			return offset;
		}
	}
	
	public partial class Position : KSObject
	{
		public int? X { get; set; }
		public int? Y { get; set; }
		

		public Position()
		{
		}
		
		public new const string NameStatic = "Position";
		
		public override string Name() => "Position";
		
		public override byte[] Serialize()
		{
			List<byte> s = new List<byte>();
			
			// serialize X
			s.Add((byte)((X == null) ? 0 : 1));
			if (X != null)
			{
				s.AddRange(BitConverter.GetBytes((int)X));
			}
			
			// serialize Y
			s.Add((byte)((Y == null) ? 0 : 1));
			if (Y != null)
			{
				s.AddRange(BitConverter.GetBytes((int)Y));
			}
			
			return s.ToArray();
		}
		
		public override uint Deserialize(byte[] s, uint offset = 0)
		{
			// deserialize X
			byte tmp5;
			tmp5 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp5 == 1)
			{
				X = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				X = null;
			
			// deserialize Y
			byte tmp6;
			tmp6 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp6 == 1)
			{
				Y = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				Y = null;
			
			return offset;
		}
	}
	
	public partial class Agent : KSObject
	{
		public Position Position { get; set; }
		public EDirection? Direction { get; set; }
		

		public Agent()
		{
		}
		
		public new const string NameStatic = "Agent";
		
		public override string Name() => "Agent";
		
		public override byte[] Serialize()
		{
			List<byte> s = new List<byte>();
			
			// serialize Position
			s.Add((byte)((Position == null) ? 0 : 1));
			if (Position != null)
			{
				s.AddRange(Position.Serialize());
			}
			
			// serialize Direction
			s.Add((byte)((Direction == null) ? 0 : 1));
			if (Direction != null)
			{
				s.Add((byte)((sbyte)Direction));
			}
			
			return s.ToArray();
		}
		
		public override uint Deserialize(byte[] s, uint offset = 0)
		{
			// deserialize Position
			byte tmp7;
			tmp7 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp7 == 1)
			{
				Position = new Position();
				offset = Position.Deserialize(s, offset);
			}
			else
				Position = null;
			
			// deserialize Direction
			byte tmp8;
			tmp8 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp8 == 1)
			{
				sbyte tmp9;
				tmp9 = (sbyte)s[(int)offset];
				offset += sizeof(sbyte);
				Direction = (EDirection)tmp9;
			}
			else
				Direction = null;
			
			return offset;
		}
	}
	
	public partial class World : KSObject
	{
		public List<List<ECell?>> Board { get; set; }
		public Dictionary<string, Agent> Agents { get; set; }
		public Dictionary<string, float?> Scores { get; set; }
		public Constants Constants { get; set; }
		

		public World()
		{
		}
		
		public new const string NameStatic = "World";
		
		public override string Name() => "World";
		
		public override byte[] Serialize()
		{
			List<byte> s = new List<byte>();
			
			// serialize Board
			s.Add((byte)((Board == null) ? 0 : 1));
			if (Board != null)
			{
				List<byte> tmp10 = new List<byte>();
				tmp10.AddRange(BitConverter.GetBytes((uint)Board.Count()));
				while (tmp10.Count > 0 && tmp10.Last() == 0)
					tmp10.RemoveAt(tmp10.Count - 1);
				s.Add((byte)tmp10.Count);
				s.AddRange(tmp10);
				
				foreach (var tmp11 in Board)
				{
					s.Add((byte)((tmp11 == null) ? 0 : 1));
					if (tmp11 != null)
					{
						List<byte> tmp12 = new List<byte>();
						tmp12.AddRange(BitConverter.GetBytes((uint)tmp11.Count()));
						while (tmp12.Count > 0 && tmp12.Last() == 0)
							tmp12.RemoveAt(tmp12.Count - 1);
						s.Add((byte)tmp12.Count);
						s.AddRange(tmp12);
						
						foreach (var tmp13 in tmp11)
						{
							s.Add((byte)((tmp13 == null) ? 0 : 1));
							if (tmp13 != null)
							{
								s.Add((byte)((sbyte)tmp13));
							}
						}
					}
				}
			}
			
			// serialize Agents
			s.Add((byte)((Agents == null) ? 0 : 1));
			if (Agents != null)
			{
				List<byte> tmp14 = new List<byte>();
				tmp14.AddRange(BitConverter.GetBytes((uint)Agents.Count()));
				while (tmp14.Count > 0 && tmp14.Last() == 0)
					tmp14.RemoveAt(tmp14.Count - 1);
				s.Add((byte)tmp14.Count);
				s.AddRange(tmp14);
				
				foreach (var tmp15 in Agents)
				{
					s.Add((byte)((tmp15.Key == null) ? 0 : 1));
					if (tmp15.Key != null)
					{
						List<byte> tmp16 = new List<byte>();
						tmp16.AddRange(BitConverter.GetBytes((uint)tmp15.Key.Count()));
						while (tmp16.Count > 0 && tmp16.Last() == 0)
							tmp16.RemoveAt(tmp16.Count - 1);
						s.Add((byte)tmp16.Count);
						s.AddRange(tmp16);
						
						s.AddRange(System.Text.Encoding.GetEncoding("ISO-8859-1").GetBytes(tmp15.Key));
					}
					
					s.Add((byte)((tmp15.Value == null) ? 0 : 1));
					if (tmp15.Value != null)
					{
						s.AddRange(tmp15.Value.Serialize());
					}
				}
			}
			
			// serialize Scores
			s.Add((byte)((Scores == null) ? 0 : 1));
			if (Scores != null)
			{
				List<byte> tmp17 = new List<byte>();
				tmp17.AddRange(BitConverter.GetBytes((uint)Scores.Count()));
				while (tmp17.Count > 0 && tmp17.Last() == 0)
					tmp17.RemoveAt(tmp17.Count - 1);
				s.Add((byte)tmp17.Count);
				s.AddRange(tmp17);
				
				foreach (var tmp18 in Scores)
				{
					s.Add((byte)((tmp18.Key == null) ? 0 : 1));
					if (tmp18.Key != null)
					{
						List<byte> tmp19 = new List<byte>();
						tmp19.AddRange(BitConverter.GetBytes((uint)tmp18.Key.Count()));
						while (tmp19.Count > 0 && tmp19.Last() == 0)
							tmp19.RemoveAt(tmp19.Count - 1);
						s.Add((byte)tmp19.Count);
						s.AddRange(tmp19);
						
						s.AddRange(System.Text.Encoding.GetEncoding("ISO-8859-1").GetBytes(tmp18.Key));
					}
					
					s.Add((byte)((tmp18.Value == null) ? 0 : 1));
					if (tmp18.Value != null)
					{
						s.AddRange(BitConverter.GetBytes((float)tmp18.Value));
					}
				}
			}
			
			// serialize Constants
			s.Add((byte)((Constants == null) ? 0 : 1));
			if (Constants != null)
			{
				s.AddRange(Constants.Serialize());
			}
			
			return s.ToArray();
		}
		
		public override uint Deserialize(byte[] s, uint offset = 0)
		{
			// deserialize Board
			byte tmp20;
			tmp20 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp20 == 1)
			{
				byte tmp21;
				tmp21 = (byte)s[(int)offset];
				offset += sizeof(byte);
				byte[] tmp22 = new byte[sizeof(uint)];
				Array.Copy(s, offset, tmp22, 0, tmp21);
				offset += tmp21;
				uint tmp23;
				tmp23 = BitConverter.ToUInt32(tmp22, (int)0);
				
				Board = new List<List<ECell?>>();
				for (uint tmp24 = 0; tmp24 < tmp23; tmp24++)
				{
					List<ECell?> tmp25;
					byte tmp26;
					tmp26 = (byte)s[(int)offset];
					offset += sizeof(byte);
					if (tmp26 == 1)
					{
						byte tmp27;
						tmp27 = (byte)s[(int)offset];
						offset += sizeof(byte);
						byte[] tmp28 = new byte[sizeof(uint)];
						Array.Copy(s, offset, tmp28, 0, tmp27);
						offset += tmp27;
						uint tmp29;
						tmp29 = BitConverter.ToUInt32(tmp28, (int)0);
						
						tmp25 = new List<ECell?>();
						for (uint tmp30 = 0; tmp30 < tmp29; tmp30++)
						{
							ECell? tmp31;
							byte tmp32;
							tmp32 = (byte)s[(int)offset];
							offset += sizeof(byte);
							if (tmp32 == 1)
							{
								sbyte tmp33;
								tmp33 = (sbyte)s[(int)offset];
								offset += sizeof(sbyte);
								tmp31 = (ECell)tmp33;
							}
							else
								tmp31 = null;
							tmp25.Add(tmp31);
						}
					}
					else
						tmp25 = null;
					Board.Add(tmp25);
				}
			}
			else
				Board = null;
			
			// deserialize Agents
			byte tmp34;
			tmp34 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp34 == 1)
			{
				byte tmp35;
				tmp35 = (byte)s[(int)offset];
				offset += sizeof(byte);
				byte[] tmp36 = new byte[sizeof(uint)];
				Array.Copy(s, offset, tmp36, 0, tmp35);
				offset += tmp35;
				uint tmp37;
				tmp37 = BitConverter.ToUInt32(tmp36, (int)0);
				
				Agents = new Dictionary<string, Agent>();
				for (uint tmp38 = 0; tmp38 < tmp37; tmp38++)
				{
					string tmp39;
					byte tmp41;
					tmp41 = (byte)s[(int)offset];
					offset += sizeof(byte);
					if (tmp41 == 1)
					{
						byte tmp42;
						tmp42 = (byte)s[(int)offset];
						offset += sizeof(byte);
						byte[] tmp43 = new byte[sizeof(uint)];
						Array.Copy(s, offset, tmp43, 0, tmp42);
						offset += tmp42;
						uint tmp44;
						tmp44 = BitConverter.ToUInt32(tmp43, (int)0);
						
						tmp39 = System.Text.Encoding.GetEncoding("ISO-8859-1").GetString(s.Skip((int)offset).Take((int)tmp44).ToArray());
						offset += tmp44;
					}
					else
						tmp39 = null;
					
					Agent tmp40;
					byte tmp45;
					tmp45 = (byte)s[(int)offset];
					offset += sizeof(byte);
					if (tmp45 == 1)
					{
						tmp40 = new Agent();
						offset = tmp40.Deserialize(s, offset);
					}
					else
						tmp40 = null;
					
					Agents[tmp39] = tmp40;
				}
			}
			else
				Agents = null;
			
			// deserialize Scores
			byte tmp46;
			tmp46 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp46 == 1)
			{
				byte tmp47;
				tmp47 = (byte)s[(int)offset];
				offset += sizeof(byte);
				byte[] tmp48 = new byte[sizeof(uint)];
				Array.Copy(s, offset, tmp48, 0, tmp47);
				offset += tmp47;
				uint tmp49;
				tmp49 = BitConverter.ToUInt32(tmp48, (int)0);
				
				Scores = new Dictionary<string, float?>();
				for (uint tmp50 = 0; tmp50 < tmp49; tmp50++)
				{
					string tmp51;
					byte tmp53;
					tmp53 = (byte)s[(int)offset];
					offset += sizeof(byte);
					if (tmp53 == 1)
					{
						byte tmp54;
						tmp54 = (byte)s[(int)offset];
						offset += sizeof(byte);
						byte[] tmp55 = new byte[sizeof(uint)];
						Array.Copy(s, offset, tmp55, 0, tmp54);
						offset += tmp54;
						uint tmp56;
						tmp56 = BitConverter.ToUInt32(tmp55, (int)0);
						
						tmp51 = System.Text.Encoding.GetEncoding("ISO-8859-1").GetString(s.Skip((int)offset).Take((int)tmp56).ToArray());
						offset += tmp56;
					}
					else
						tmp51 = null;
					
					float? tmp52;
					byte tmp57;
					tmp57 = (byte)s[(int)offset];
					offset += sizeof(byte);
					if (tmp57 == 1)
					{
						tmp52 = BitConverter.ToSingle(s, (int)offset);
						offset += sizeof(float);
					}
					else
						tmp52 = null;
					
					Scores[tmp51] = tmp52;
				}
			}
			else
				Scores = null;
			
			// deserialize Constants
			byte tmp58;
			tmp58 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp58 == 1)
			{
				Constants = new Constants();
				offset = Constants.Deserialize(s, offset);
			}
			else
				Constants = null;
			
			return offset;
		}
	}
} // namespace KS.Models
