# DLL_4W-injection

![alt text](https://cdn.discordapp.com/attachments/951192813477965856/1046065959045189642/Inkedsasas_LI.jpg)

# What is DLL hijacking?

When attackers get an infected file onto your machine, this file is then executed when the application vulnerable to DLL hijacking is run. DLL hijacking is a cyberattack method that injects an infected file within the search parameters of an application. A user then attempts to load a file from that directory and instead loads the infected DLL file. This infected file takes action when the application is loaded. DLL files are often preloaded into a computer. Many applications with DLL files automatically load during startup, which can then compromise the entire computer, giving hackers access to it whenever the file containing the malicious code loads.

Windows operating systems provide the functionality to allow custom DLL’s to be loaded into the address space of almost all application processes. This can give the opportunity for persistence since an arbitrary DLL can be loaded that will execute code when applications processes are created on the system. Administrator level privileges are required to implement this technique.

Therefore; Microsoft protect Windows users from malware has disabled by default the loading of DLLs’s via AppInit. However, setting the registry key “LoadAppInit_DLLs” to value “1” will enable this functionality. Dropping the arbitrary DLL into the “Program Files” directory and modifying the “AppInit_DLLs” registry key to contain the path of the DLL will load the pentestlab.dll into every Windows application. This is because DLL’s that are specified in the “AppInit_DLLs” registry key are loaded by the user32.dll which is used by almost all applications.

and here we go , this project is going to make your life easy by breaking those security implimented by MicroSOft to make this attack happening Ethically
