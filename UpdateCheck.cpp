///
/// Created by Anonymous275 on 3/29/2020
///

#include <iostream>
#include <string>


void Download(const std::string& URL,const std::string& path);
std::string HTTP_REQUEST(const std::string&url,int port);
void SystemExec(const std::string& cmd);
void WinExec(const std::string& cmd);

void CheckForUpdates(){
    system ("cls");
    std::string CV = "0.11";
    std::string HTTP = HTTP_REQUEST("backend.beamng-mp.com/builds/launcher/latest?version=true",80);
    HTTP = HTTP.substr(HTTP.find_last_of("ver=")+1,HTTP.find_last_of('.')).substr(0,4);
    std::cout << "Current Version : " << CV << "\nRemote version : " << HTTP << std::endl;
    if(HTTP > CV){
        struct stat buffer{};
        if(stat ("BeamMP-Launcher.back", &buffer) == 0)remove("BeamMP-Launcher.back");
        std::cout << "Update found!" << std::endl;
        std::cout << "Updating..." << std::endl;
        SystemExec("rename BeamMP-Launcher.exe BeamMP-Launcher.back>nul");
        Download("http://backend.beamng-mp.com/builds/launcher/latest?download=true", "BeamMP-Launcher.exe");
        WinExec("BeamMP-Launcher.exe");
        exit(1);
    }else{
        std::cout << "Version is up to date" << std::endl;
    }
}