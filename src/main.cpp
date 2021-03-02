#include <Windows.h>
#include <steam/steam_api.h>

#include <iostream>
#include <iomanip>
int main(){
    auto init = SteamAPI_Init();
    if(!init){
        std::cout << "Error: Init failed! Steam ought to be running if using the official steam bindings" << std::endl;
        return 1;
    }
    auto user = SteamUser();
    auto id = user->GetSteamID();
    std::cout << "SteamID64 Dec: " << id.ConvertToUint64() << std::endl;
    std::cout << "SteamID64 Hex: " << std::hex << id.ConvertToUint64() << std::endl;
    SteamAPI_Shutdown();
    return 0;
}