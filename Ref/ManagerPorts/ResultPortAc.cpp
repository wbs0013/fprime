#include <Fw/Cfg/Config.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>

#include <Ref/ManagerPorts/ResultPortAc.hpp>
namespace Ref {


    namespace {

        class ResultPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity(void) const {
                    return sizeof(m_buff);
                }

                U8* getBuffAddr(void) {
                    return m_buff;
                }

                const U8* getBuffAddr(void) const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputResultPort::SERIALIZED_SIZE];

        };

    }
    InputResultPort::InputResultPort(void) :
        Fw::InputPortBase(),
        m_func(0) {
    }

    void InputResultPort::init(void) {
        Fw::InputPortBase::init();
    }

    void InputResultPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputResultPort::invoke(F32 result) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, result);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputResultPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        F32 result;
        _status = buffer.deserialize(result);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, result);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputResultPort::OutputResultPort(void) :
            Fw::OutputPortBase(),
    m_port(0) {
}

void OutputResultPort::init(void) {
    Fw::OutputPortBase::init();
}

void OutputResultPort::addCallPort(InputResultPort* callPort) {
    FW_ASSERT(callPort);
    
    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = 0;
#endif
}

void OutputResultPort::invoke(F32 result) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION            
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(result);
#if FW_PORT_SERIALIZATION            
    } else if (this->m_serPort) {
        Fw::SerializeStatus status;
        ResultPortBuffer _buffer;
        status = _buffer.serialize(result);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }    
#endif

} // end OutputResultPort::invoke(...)

} // end namespace Ref
