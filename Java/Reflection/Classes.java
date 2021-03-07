package jul.reflection;

import java.io.File;
import java.io.IOException;
import java.lang.annotation.Annotation;
import java.net.URL;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Enumeration;
import java.util.stream.Collectors;

public class Classes
{
	private static final String CLASS_EXTENSION = "class";

	public static Collection<Class<?>> getAnnotatedClasses(Class<?> annotation)
	{
		return Classes.getAllClasses().stream().filter(c -> {
			for(Annotation declaredAnnotation : c.getDeclaredAnnotations())
			{
				if(declaredAnnotation.annotationType().equals(annotation))
				{
					return true;
				}
			}

			return false;
		}).collect(Collectors.toList());
	}

	public static Collection<Class<?>> getAllClasses()
	{
		return Classes.getClassesFromPackage("");
	}

	private static Collection<Class<?>> getClassesFromPackage(String packageName)
	{
		Collection<Class<?>> classes = new ArrayList<Class<?>>();
		Enumeration<URL> content = Classes.getPackageContent(packageName);

		while(content.hasMoreElements())
		{
			URL element = content.nextElement();
			File elementFile = new File(element.getFile());

			if(elementFile.isDirectory())
			{
				classes.addAll(Classes.getClassFromPackages(packageName, elementFile.listFiles()));
			}
			else if(Classes.isClassFile(packageName))
			{
				try
				{
					classes.add(Class.forName(Classes.asClassName(packageName)));
				}
				catch(ClassNotFoundException e)
				{
				}
			}
		}

		return classes;
	}

	private static Collection<Class<?>> getClassFromPackages(String packageName, File[] files)
	{
		Collection<Class<?>> classes = new ArrayList<Class<?>>();

		for(File subfile : files)
		{
			String nextPackage = Classes.appendPackage(packageName, subfile.getName());
			classes.addAll(Classes.getClassesFromPackage(nextPackage));
		}

		return classes;
	}

	private static Enumeration<URL> getPackageContent(String packageName)
	{
		try
		{
			ClassLoader classLoader = ClassLoader.getSystemClassLoader();

			if(classLoader == null)
			{
				return Collections.emptyEnumeration();
			}
			else
			{
				String pathOfPackage = Classes.getPathOfPackage(packageName);
				return classLoader.getResources(pathOfPackage);
			}
		}
		catch(IOException e)
		{
			return Collections.emptyEnumeration();
		}
	}

	private static String getPathOfPackage(String packageName)
	{
		return packageName.replaceAll("\\.(?!" + Classes.CLASS_EXTENSION + ")", File.separator); // Replace all . in package and not one of the class
	}

	private static String appendPackage(String packageName, String subfile)
	{
		return packageName.length() > 0 ? packageName + "." + subfile : subfile;
	}

	private static boolean isClassFile(String packageClass)
	{
		return packageClass.endsWith("." + Classes.CLASS_EXTENSION);
	}

	private static String asClassName(String packageClass)
	{
		return packageClass.replace("." + Classes.CLASS_EXTENSION, "");
	}
}
