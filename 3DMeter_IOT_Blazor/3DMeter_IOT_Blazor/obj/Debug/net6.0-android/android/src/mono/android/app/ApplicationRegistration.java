package mono.android.app;

public class ApplicationRegistration {

	public static void registerApplications ()
	{
				// Application and Instrumentation ACWs must be registered first.
		mono.android.Runtime.register ("_3DMeter_IOT_Blazor.MainApplication, 3DMeter_IOT_Blazor, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null", crc6434749a29d5c6da86.MainApplication.class, crc6434749a29d5c6da86.MainApplication.__md_methods);
		mono.android.Runtime.register ("Microsoft.Maui.MauiApplication, Microsoft.Maui, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null", crc6488302ad6e9e4df1a.MauiApplication.class, crc6488302ad6e9e4df1a.MauiApplication.__md_methods);
		
	}
}
