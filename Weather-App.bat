@echo off
REM Set the path to your desired location
set "path=D:\Rishi\Project 2024\C++\WeatherAppUsingRestAPI\cpprestsdk-411a109\Release\src"


set "PROJECT_PATH=D:\Rishi\Project 2024\C++\WeatherAppUsingRestAPI\Weather-App"

REM Navigate to the project path
cd /d %PROJECT_PATH%

REM Open the solution file
start "" "%PROJECT_PATH%\Weather-App.sln"
