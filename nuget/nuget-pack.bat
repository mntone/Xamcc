@echo off

set NUGET=nuget

%NUGET% pack Xamcc.nuspec
%NUGET% pack Xamcc.Interactions.nuspec

PAUSE