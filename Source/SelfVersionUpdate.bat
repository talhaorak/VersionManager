@ echo off
REM Author: Talha ORAK
set OLDDIR=%CD%

rem echo  First param is %1
rem echo Second param is %2
echo *******************************************************
echo *******************************************************
echo *******************************************************
echo ***************Self version update*********************
echo *******************************************************
echo *******************************************************
echo *******************************************************

IF EXIST %1\VersionManager.exe (
	IF EXIST %1\VersionManager.prev.exe (
		echo **********1  Deleting old version
		del %1\VersionManager.prev.exe 
	)
	echo **********2 Backing up
	copy /Y %1\VersionManager.exe %1\VersionManager.prev.exe
	echo **********3 Setting up the QT path
	call %QTDIR%\bin\qtenv2.bat
	echo **********4 Getting back to project dir
	cd /d %OLDDIR%
	echo **********5 Updating the version of the project
	%1\VersionManager.prev.exe -e %2
	IF ERRORLEVEL 1 (
		echo ********** VersionManager.prev.exe returned error
	) ELSE (
		echo *******************************************************
		echo *******************************************************
		echo *******************************************************
		echo **********************All Done!************************
		echo *******************************************************
		echo *******************************************************
		echo *******************************************************
	)
) ELSE ( 
	echo **********6 %1\VersionManager.exe doesn't exist 
)