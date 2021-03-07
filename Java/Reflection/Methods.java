package jul.reflection;

import java.lang.annotation.Annotation;
import java.lang.reflect.Method;
import java.util.Arrays;
import java.util.Collection;
import java.util.stream.Collectors;

public class Methods
{
	public static Collection<Method> getAnnotatedMethods(Class<?> from, Class<?> annotation)
	{
		return Methods.getAllMethods(from).stream().filter(method -> {
			for(Annotation declaredAnnotation : method.getDeclaredAnnotations())
			{
				if(declaredAnnotation.annotationType().equals(annotation))
				{
					return true;
				}
			}

			return false;
		}).collect(Collectors.toList());
	}

	public static Collection<Method> getAllMethods(Class<?> from)
	{
		return Arrays.asList(from.getDeclaredMethods());
	}
}
