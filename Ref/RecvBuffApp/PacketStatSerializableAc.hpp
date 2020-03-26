/*
 * PacketStat.hpp
 *
 *  Created on: Wednesday, 25 March 2020
 *  Author:     wbs0013
 *
 */
#ifndef PACKETSTAT_HPP_
#define PACKETSTAT_HPP_

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/StringType.hpp>
#include <stdio.h> // snprintf
#ifdef BUILD_UT
#include <iostream>
#include <Fw/Types/EightyCharString.hpp>
#endif
#endif

namespace Ref {

    typedef enum {
        PACKET_STATE_NO_PACKETS,
        PACKET_STATE_OK,
        PACKET_STATE_ERRORS = 3,  // Receiver has seen errors
        PacketRecvStatus_MAX
    } PacketRecvStatus;

class PacketStat : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(U32) +
        sizeof(U32) +
        sizeof(FwEnumStoreType)
    }; //!< serializable size of PacketStat

    PacketStat(void); //!< Default constructor
    PacketStat(const PacketStat* src); //!< pointer copy constructor
    PacketStat(const PacketStat& src); //!< reference copy constructor
    PacketStat(U32 BuffRecv, U32 BuffErr, PacketRecvStatus PacketStatus); //!< constructor with arguments
    const PacketStat& operator=(const PacketStat& src); //!< equal operator
    bool operator==(const PacketStat& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const PacketStat& obj);
#endif

    void set(U32 BuffRecv, U32 BuffErr, PacketRecvStatus PacketStatus); //!< set values

    U32 getBuffRecv(void); //!< get member BuffRecv
    U32 getBuffErr(void); //!< get member BuffErr
    PacketRecvStatus getPacketStatus(void); //!< get member PacketStatus

    void setBuffRecv(U32 val); //!< set member BuffRecv
    void setBuffErr(U32 val); //!< set member BuffErr
    void setPacketStatus(PacketRecvStatus val); //!< set member PacketStatus


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0xC92F919A //!< type id
    };

    U32 m_BuffRecv; //<! BuffRecv - Number of buffers received
    U32 m_BuffErr; //<! BuffErr - Number of buffers received with errors
    PacketRecvStatus m_PacketStatus; //<! PacketStatus - Packet Status
private:

};
} // end namespace Ref
#endif /* PACKETSTAT_HPP_ */

