#ifndef PACKETMAKEPARENT_H
#define PACKETMAKEPARENT_H

class PacketMakeParent
{


public:
     PacketMakeParent(){}
     virtual void PacketOpen() = 0;
     virtual void PacketSniff() = 0;
     virtual void PacketSend() = 0;
};

#endif // PACKETMAKEPARENT_H
