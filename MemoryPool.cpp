#include "MemoryPool.h"
#include "Packet.h"
template <typename T> 
CMemoryPool<T>* CMemoryPool<T>::m_pInstance = nullptr;

void MemoryPool_StreamPush(void* p)
{
    CStream* pStream = (CStream*)p;
    pStream->Clear();

    CMemoryPool<CStream>::Push(pStream);
}

void MemoryPool_PacketPush(int TYPE , void* p)
{
    ((CPacket*)p)->Clear();

    switch (TYPE)
    {
        /*Usage : 
        CASEMEMORYPUSHTOPOOL(PACKET_SERVER_2_CLIENT_TEST, p);
        */
       

    default:
        break;
    }

}

void PacketPoolInitialize()
{
    for (int i = 0; i < ENUM_NETPACKET_TYPE::PACKET_END; ++i)
    {
        switch (i)
        {
	/* Usage :
            POOLINITIALIZE(PACKET_SERVER_2_CLIENT_TEST)
            */

        default:
            break;
        }
    }
    



}
