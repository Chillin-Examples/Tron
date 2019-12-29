package ks.models;

import java.lang.*;
import java.util.*;
import java.nio.*;
import java.nio.charset.Charset;

import ks.KSObject;

public class Constants extends KSObject
{
	protected Integer maxCycles;
	protected Float wallCreationScoreCoefficient;
	protected Integer areaWallCrashScore;
	protected Integer myWallCrashScore;
	protected Integer enemyWallCrashScore;
	
	// getters
	
	public Integer getMaxCycles()
	{
		return this.maxCycles;
	}
	
	public Float getWallCreationScoreCoefficient()
	{
		return this.wallCreationScoreCoefficient;
	}
	
	public Integer getAreaWallCrashScore()
	{
		return this.areaWallCrashScore;
	}
	
	public Integer getMyWallCrashScore()
	{
		return this.myWallCrashScore;
	}
	
	public Integer getEnemyWallCrashScore()
	{
		return this.enemyWallCrashScore;
	}
	
	
	// setters
	
	public void setMaxCycles(Integer maxCycles)
	{
		this.maxCycles = maxCycles;
	}
	
	public void setWallCreationScoreCoefficient(Float wallCreationScoreCoefficient)
	{
		this.wallCreationScoreCoefficient = wallCreationScoreCoefficient;
	}
	
	public void setAreaWallCrashScore(Integer areaWallCrashScore)
	{
		this.areaWallCrashScore = areaWallCrashScore;
	}
	
	public void setMyWallCrashScore(Integer myWallCrashScore)
	{
		this.myWallCrashScore = myWallCrashScore;
	}
	
	public void setEnemyWallCrashScore(Integer enemyWallCrashScore)
	{
		this.enemyWallCrashScore = enemyWallCrashScore;
	}
	
	
	public Constants()
	{
	}
	
	public static final String nameStatic = "Constants";
	
	@Override
	public String name() { return "Constants"; }
	
	@Override
	public byte[] serialize()
	{
		List<Byte> s = new ArrayList<>();
		
		// serialize maxCycles
		s.add((byte) ((maxCycles == null) ? 0 : 1));
		if (maxCycles != null)
		{
			s.addAll(b2B(ByteBuffer.allocate(Integer.BYTES).order(ByteOrder.LITTLE_ENDIAN).putInt(maxCycles).array()));
		}
		
		// serialize wallCreationScoreCoefficient
		s.add((byte) ((wallCreationScoreCoefficient == null) ? 0 : 1));
		if (wallCreationScoreCoefficient != null)
		{
			s.addAll(b2B(ByteBuffer.allocate(Float.BYTES).order(ByteOrder.LITTLE_ENDIAN).putFloat(wallCreationScoreCoefficient).array()));
		}
		
		// serialize areaWallCrashScore
		s.add((byte) ((areaWallCrashScore == null) ? 0 : 1));
		if (areaWallCrashScore != null)
		{
			s.addAll(b2B(ByteBuffer.allocate(Integer.BYTES).order(ByteOrder.LITTLE_ENDIAN).putInt(areaWallCrashScore).array()));
		}
		
		// serialize myWallCrashScore
		s.add((byte) ((myWallCrashScore == null) ? 0 : 1));
		if (myWallCrashScore != null)
		{
			s.addAll(b2B(ByteBuffer.allocate(Integer.BYTES).order(ByteOrder.LITTLE_ENDIAN).putInt(myWallCrashScore).array()));
		}
		
		// serialize enemyWallCrashScore
		s.add((byte) ((enemyWallCrashScore == null) ? 0 : 1));
		if (enemyWallCrashScore != null)
		{
			s.addAll(b2B(ByteBuffer.allocate(Integer.BYTES).order(ByteOrder.LITTLE_ENDIAN).putInt(enemyWallCrashScore).array()));
		}
		
		return B2b(s);
	}
	
	@Override
	protected int deserialize(byte[] s, int offset)
	{
		// deserialize maxCycles
		byte tmp0;
		tmp0 = s[offset];
		offset += Byte.BYTES;
		if (tmp0 == 1)
		{
			maxCycles = ByteBuffer.wrap(Arrays.copyOfRange(s, offset, offset + Integer.BYTES)).order(ByteOrder.LITTLE_ENDIAN).getInt();
			offset += Integer.BYTES;
		}
		else
			maxCycles = null;
		
		// deserialize wallCreationScoreCoefficient
		byte tmp1;
		tmp1 = s[offset];
		offset += Byte.BYTES;
		if (tmp1 == 1)
		{
			wallCreationScoreCoefficient = ByteBuffer.wrap(Arrays.copyOfRange(s, offset, offset + Float.BYTES)).order(ByteOrder.LITTLE_ENDIAN).getFloat();
			offset += Float.BYTES;
		}
		else
			wallCreationScoreCoefficient = null;
		
		// deserialize areaWallCrashScore
		byte tmp2;
		tmp2 = s[offset];
		offset += Byte.BYTES;
		if (tmp2 == 1)
		{
			areaWallCrashScore = ByteBuffer.wrap(Arrays.copyOfRange(s, offset, offset + Integer.BYTES)).order(ByteOrder.LITTLE_ENDIAN).getInt();
			offset += Integer.BYTES;
		}
		else
			areaWallCrashScore = null;
		
		// deserialize myWallCrashScore
		byte tmp3;
		tmp3 = s[offset];
		offset += Byte.BYTES;
		if (tmp3 == 1)
		{
			myWallCrashScore = ByteBuffer.wrap(Arrays.copyOfRange(s, offset, offset + Integer.BYTES)).order(ByteOrder.LITTLE_ENDIAN).getInt();
			offset += Integer.BYTES;
		}
		else
			myWallCrashScore = null;
		
		// deserialize enemyWallCrashScore
		byte tmp4;
		tmp4 = s[offset];
		offset += Byte.BYTES;
		if (tmp4 == 1)
		{
			enemyWallCrashScore = ByteBuffer.wrap(Arrays.copyOfRange(s, offset, offset + Integer.BYTES)).order(ByteOrder.LITTLE_ENDIAN).getInt();
			offset += Integer.BYTES;
		}
		else
			enemyWallCrashScore = null;
		
		return offset;
	}
}
