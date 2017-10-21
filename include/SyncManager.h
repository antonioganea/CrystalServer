#ifndef SYNCMANAGER_H
#define SYNCMANAGER_H

#include <SFML/Network.hpp>

#define MAX_PLAYERS 16

class SyncManager
{
    public:
        static void init();
        static void acceptConnections();
        static void receivePackets();

        /**Redirect Packet from a client to peers ( including packet type )*/
        static void redirectPacket( int receivedFrom, char * buffer, int size, bool skipSender );
        //static bool queueResource( const std::string& filePath, const ResourceType& type );
        //static bool loadResource();
        //static ResourcePtr getResource( const std::string& filePath, const ResourceType& type );

        static int players;
        static sf::TcpSocket * sockets;
        static sf::TcpListener listener;
        static char * packageBuffer;
        static int crystalTypes[MAX_PLAYERS];
        static int crystalHP[MAX_PLAYERS];
        static bool playersOn[MAX_PLAYERS];
        static sf::Vector2f playerPositions[MAX_PLAYERS];

        static int nextSocket;

        static char * options;

        static void damageCrystal( int player );
        static void pushCrystal( int affectedPlayer, int player, float force );
        static void sendDisconnected( int player );

        static void detectCollisions();

        static sf::SocketSelector selector;
    protected:

    private:
        SyncManager();
        static void parseBuffer( int player, std::size_t received );


        //static std::map<std::string, ResourcePtr> m_resources;
        //static std::stack<ResourceCommand> m_commands;
};

#endif // SYNCMANAGER_H
