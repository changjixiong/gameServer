# Microsoft Developer Studio Project File - Name="GameServer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=GameServer - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GameServer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GameServer.mak" CFG="GameServer - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GameServer - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "GameServer - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GameServer - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "GameServer - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "GameServer - Win32 Release"
# Name "GameServer - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\GameServer.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "BasicLib"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BasicLib\BasicLib.h
# End Source File
# Begin Source File

SOURCE=.\BasicLib\BasicLibFunctions.h
# End Source File
# Begin Source File

SOURCE=.\BasicLib\BasicLibLogger.h
# End Source File
# Begin Source File

SOURCE=.\BasicLib\BasicLibRandom.cpp
# End Source File
# Begin Source File

SOURCE=.\BasicLib\BasicLibRandom.h
# End Source File
# Begin Source File

SOURCE=.\BasicLib\BasicLibString.cpp
# End Source File
# Begin Source File

SOURCE=.\BasicLib\BasicLibString.h
# End Source File
# Begin Source File

SOURCE=.\BasicLib\BasicLibTime.cpp
# End Source File
# Begin Source File

SOURCE=.\BasicLib\BasicLibTime.h
# End Source File
# Begin Source File

SOURCE=.\BasicLib\BasicLibTypes.h
# End Source File
# End Group
# Begin Group "SocketLib"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\SocketLib\Connection.h
# End Source File
# Begin Source File

SOURCE=.\SocketLib\ConnectionHandler.h
# End Source File
# Begin Source File

SOURCE=.\SocketLib\ConnectionManager.h
# End Source File
# Begin Source File

SOURCE=.\SocketLib\ListeningManager.h
# End Source File
# Begin Source File

SOURCE=.\SocketLib\SocketLib.h
# End Source File
# Begin Source File

SOURCE=.\SocketLib\SocketLibErrors.cpp
# End Source File
# Begin Source File

SOURCE=.\SocketLib\SocketLibErrors.h
# End Source File
# Begin Source File

SOURCE=.\SocketLib\SocketLibSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\SocketLib\SocketLibSocket.h
# End Source File
# Begin Source File

SOURCE=.\SocketLib\SocketLibSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\SocketLib\SocketLibSystem.h
# End Source File
# Begin Source File

SOURCE=.\SocketLib\SocketLibTypes.h
# End Source File
# Begin Source File

SOURCE=.\SocketLib\SocketSet.cpp
# End Source File
# Begin Source File

SOURCE=.\SocketLib\SocketSet.h
# End Source File
# Begin Source File

SOURCE=.\SocketLib\Telnet.cpp
# End Source File
# Begin Source File

SOURCE=.\SocketLib\Telnet.h
# End Source File
# End Group
# Begin Group "ThreadLib"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ThreadLib\ThreadException.h
# End Source File
# Begin Source File

SOURCE=.\ThreadLib\ThreadLib.h
# End Source File
# Begin Source File

SOURCE=.\ThreadLib\ThreadLibFunctions.cpp
# End Source File
# Begin Source File

SOURCE=.\ThreadLib\ThreadLibFunctions.h
# End Source File
# Begin Source File

SOURCE=.\ThreadLib\ThreadLibMutex.h
# End Source File
# End Group
# Begin Group "Login"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Login\SCLogon.cpp
# End Source File
# Begin Source File

SOURCE=.\Login\SCLogon.h
# End Source File
# End Group
# Begin Group "UserDB"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UserDB\SCUserDB.cpp
# End Source File
# Begin Source File

SOURCE=.\UserDB\SCUserDB.h
# End Source File
# End Group
# Begin Group "Logic"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Logic\SCChat.cpp
# End Source File
# Begin Source File

SOURCE=.\Logic\SCChat.h
# End Source File
# End Group
# End Target
# End Project
