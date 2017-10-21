#include <iostream>
#include "SyncManager.h"

int main(){
    SyncManager::init();
    while ( true ){
        if ( SyncManager::selector.wait() ){
            SyncManager::acceptConnections();
            SyncManager::receivePackets();
        }
    }
    return 0;
}
