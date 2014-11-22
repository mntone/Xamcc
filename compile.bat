@echo off
set MSBUILD=msbuild

set PROJECT_FILES=.\Mntone.Xamcc\Mntone.Xamcc.Windows\Mntone.Xamcc.Windows.vcxproj .\Mntone.Xamcc\Mntone.Xamcc.WindowsPhone\Mntone.Xamcc.WindowsPhone.vcxproj .\Mntone.Xamcc.Interactions\Mntone.Xamcc.Interactions.Windows\Mntone.Xamcc.Interactions.Windows.vcxproj .\Mntone.Xamcc.Interactions\Mntone.Xamcc.Interactions.WindowsPhone\Mntone.Xamcc.Interactions.WindowsPhone.vcxproj

set PLATFORM_WIN32=Win32
set PLATFORM_AMD64=x64
set PLATFORM_ARM=ARM
set TARGET_PLATFORMS=%PLATFORM_WIN32% %PLATFORM_AMD64% %PLATFORM_ARM%

set CONFIGURATION_DEBUG=Debug
set CONFIGURATION_RELEASE=Release
set TARGET_CONFIGURATIONS=%CONFIGURATION_RELEASE%

for %%c in (%TARGET_CONFIGURATIONS%) do for %%p in (%TARGET_PLATFORMS%) do for %%f in (%PROJECT_FILES%) do (
	echo # -----------------------
	echo # Compile "%%f" in %%p-%%c
	echo # -----------------------
	%MSBUILD% "%%f" /maxcpucount /t:Clean;Build /p:Configuration=%%c;Platform=%%p;GenerateProjectSpecificOutputFolder=false
)

cd ./nuget
nuget-pack.bat

PAUSE