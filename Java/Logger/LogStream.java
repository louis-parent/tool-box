package fr.gear.cousteau.logging;

public interface LogStream
{
	public default void debug(Object data)
	{
		this.printFormatedLn(LogLevel.DEBUG, data);
	}
	
	public default void log(Object data)
	{
		this.printFormatedLn(LogLevel.LOG, data);
	}
	
	public default void warn(Object data)
	{
		this.printFormatedLn(LogLevel.WARN, data);
	}
	
	public default void error(Object data)
	{
		this.printFormatedLn(LogLevel.ERROR, data);
	}
	
	public default void printFormatedLn(LogLevel level, Object data)
	{
		this.printFormated(level, data, System.lineSeparator());
	}
	
	public void printFormated(LogLevel level, Object data, String endLine);

	public static enum LogLevel
	{
		DEBUG,
		LOG,
		WARN,
		ERROR
	}
}
