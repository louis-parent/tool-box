package fr.gear.cousteau.logging;

import java.io.IOException;
import java.io.OutputStream;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class Logger implements LogStream
{
	public static final Logger SYSTEM_LOGGER = new Logger();
	private static final DateFormat DATE_FORMATER = new SimpleDateFormat();
	
	private Map<LogLevel, OutputStream> streams;

	public Logger()
	{
		this(System.out, System.err);
	}

	public Logger(OutputStream messageStream, OutputStream importantStream)
	{
		this(messageStream, messageStream, importantStream, importantStream);
	}

	public Logger(OutputStream debugStream, OutputStream logStream, OutputStream warnStream, OutputStream errorStream)
	{
		this.streams = new HashMap<LogLevel, OutputStream>();
		this.streams.put(LogLevel.DEBUG, debugStream);
		this.streams.put(LogLevel.LOG, logStream);
		this.streams.put(LogLevel.WARN, warnStream);
		this.streams.put(LogLevel.ERROR, errorStream);
	}

	@Override
	public void printFormated(LogLevel level, Object data, String endLine)
	{
		try
		{
			String line = "";
			line += "[" + this.getNow() + "]";
			line += "@" + level + ": ";
			line += data.toString();
			line += endLine;
			
			this.streams.get(level).write(line.getBytes());
		}
		catch(IOException e)
		{
			System.err.println("Unable to write in " + level + " logger");
		}
	}

	protected String getNow()
	{
		return this.getDateFormater().format(new Date());
	}
	
	protected DateFormat getDateFormater()
	{
		return Logger.DATE_FORMATER;
	}
}
