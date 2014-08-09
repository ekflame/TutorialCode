PUSHD %~DP0
call "C:\GitHub\UnrealEngine\GenerateProjectFiles.bat" -project="%~dp0\TutorialCode.uproject" -game -engine

if not "%ERRORLEVEL%" == "0" call "D:\GitHub\UnrealEngine\GenerateProjectFiles.bat" -project="%~dp0\TutorialCode.uproject" -game -engine
