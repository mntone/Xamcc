@echo off
set MSBUILD=msbuild
set NUGET=nuget

set PROJECT_FILES=.\Mntone.Xamcc\Mntone.Xamcc.Windows\Mntone.Xamcc.Windows.vcxproj .\Mntone.Xamcc\Mntone.Xamcc.WindowsPhone\Mntone.Xamcc.WindowsPhone.vcxproj .\Mntone.Xamcc.Interactions\Mntone.Xamcc.Interactions.Windows\Mntone.Xamcc.Interactions.Windows.vcxproj .\Mntone.Xamcc.Interactions\Mntone.Xamcc.Interactions.WindowsPhone\Mntone.Xamcc.Interactions.WindowsPhone.vcxproj

set PLATFORM_WIN32=Win32
set PLATFORM_AMD64=x64
set PLATFORM_ARM=ARM

set CONFIGURATION_DEBUG=Debug
set CONFIGURATION_RELEASE=Release

for %%i in (%PROJECT_FILES%) do %MSBUILD% "%%i" /maxcpucount /t:Clean;Build /p:Configuration=%CONFIGURATION_RELEASE%;Platform=%PLATFORM_WIN32%;GenerateProjectSpecificOutputFolder=false
for %%i in (%PROJECT_FILES%) do %MSBUILD% "%%i" /maxcpucount /t:Clean;Build /p:Configuration=%CONFIGURATION_RELEASE%;Platform=%PLATFORM_AMD64%;GenerateProjectSpecificOutputFolder=false
for %%i in (%PROJECT_FILES%) do %MSBUILD% "%%i" /maxcpucount /t:Clean;Build /p:Configuration=%CONFIGURATION_RELEASE%;Platform=%PLATFORM_ARM%;GenerateProjectSpecificOutputFolder=false

cd ./nuget
%NUGET% pack Xamcc.nuspec
%NUGET% pack Xamcc.Interactions.nuspec

PAUSE