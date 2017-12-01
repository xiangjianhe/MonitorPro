@echo off
set PRONAME=CVT_RL6336_PROJECT
set OUTFILE=.\Output\CVT_RL6336_PROJECT\%PRONAME%.plg
set TOOLS_PATH=..\tool\xml
set BIN_PATH_SOURCE=.\Output\CVT_RL6336_PROJECT
set BIN_PATH_DES=..\bin
set BIN_NAME=CVT_RL6336_PROJECT.bin
set RAR_NAME=_UI_TE20
set 

set File_name= =.\*R_0x*.bin


del /q %BIN_PATH_SOURCE%\*.7z
del /q %BIN_PATH_SOURCE%\*.xml
del /q %BIN_PATH_DES%\*.7z
del /q %BIN_PATH_DES%\*.xml
rd %BIN_PATH_DES%
%TOOLS_PATH%\GetVersion.exe %BIN_PATH_SOURCE%\%PRONAME%.bin bin
copy %BIN_PATH_SOURCE%\%PRONAME%.bin %BIN_PATH_SOURCE%\%BIN_NAME%
%TOOLS_PATH%\auto_name.exe %BIN_PATH_SOURCE%\%PRONAME%.plg %BIN_PATH_SOURCE%\ %BIN_NAME% bin
rd /s /q xml
mkdir xml
copy %TOOLS_PATH%\ocs.dat  .\xml

%TOOLS_PATH%\xml.exe %OUTFILE%

set str1=%File_name%
call :show %str1%
echo %str2%
:show
set str2=%~n1

set /a tm1=%time:~0,2%*1
if %tm1% LSS 10 set tm1=0%tm1%
set hhmmss=%tm1%%time:~3,2%%time:~6,2%

set str3=%str2%%hhmmss%%RAR_NAME%
copy ocs.xml %BIN_PATH_SOURCE%\%str3%.xml

%TOOLS_PATH%\7za a %BIN_PATH_SOURCE%\%str3% %BIN_PATH_SOURCE%\%BIN_NAME%


mkdir %BIN_PATH_DES%
copy %BIN_PATH_SOURCE%\%str3%.* %BIN_PATH_DES%
copy %BIN_PATH_SOURCE%\%BIN_NAME% %BIN_PATH_DES%

del /q .\*.xml
del /q .\getversion.txt
del /q .\*.bin
del /q .\%BIN_PATH_DES%\.7z
@echo off
