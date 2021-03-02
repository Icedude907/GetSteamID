#include <Windows.h>
#include <steam/steam_api.h>

#include <iostream>
#include <iomanip>
int main(){
    auto init = SteamAPI_Init();
    std::cout << std::flush;
    if(!init){
        std::cout << "Error: Init failed!" << std::endl;
        return 1;
    }
    auto user = SteamUser();
    auto id = user->GetSteamID();
    std::cout << "SteamID: " << id.ConvertToUint64() << std::endl;
    std::cout << "SteamID: " << std::hex << id.ConvertToUint64() << std::endl;
    return 0;
}