@echo off
::set ViewDefine1=..\..\INC\ViewDefine1.h
::set ViewDefine=..\..\INC\ViewDefine1.h
set Buildtime=..\customer\Buildtime.h

::if not exist %ViewDefine1% (copy %ViewDefine% %ViewDefine1%) else (echo viewdefine1.h is define)
::for /f "tokens=3" %%a in (%ViewDefine1%) do @set ver=%%a
::set /a ver1=%ver%^^1
::echo #define VIEWDEFINE_ID %ver1% >%ViewDefine1%
::set yyyymmdd=%date:~0,4%%date:~5,2%%date:~8,2%%time:~0,2%%time:~3,2%%time:~6,2%

set /a tm1=%time:~0,2%*1
if %tm1% LSS 10 set tm1=0%tm1%
set yyyymmdd=%date:~0,4%%date:~5,2%%date:~8,2%%tm1%%time:~3,2%%time:~6,2%

echo #define CVT_DEF_BUILD_TIME "%yyyymmdd%" >%Buildtime%