#include <Fw/Obj/SimpleObjRegistry.hpp>
#include <string.h>

#include <Svc/Health/HealthComponentAc.hpp>
#include <Svc/ActiveLogger/ActiveLoggerComponentAc.hpp>
#include <Ref/SendBuffApp/SendBuffComponentAc.hpp>
#include <Svc/CmdSequencer/CmdSequencerComponentAc.hpp>
#include <Svc/BufferManager/BufferManagerComponentAc.hpp>
#include <Svc/ActiveRateGroup/ActiveRateGroupComponentAc.hpp>
#include <Svc/GndIf/GndIfComponentAc.hpp>
#include <Svc/FileDownlink/FileDownlinkComponentAc.hpp>
#include <Ref/Driver/DriverComponentAc.hpp>
#include <Ref/Manager/ManagerComponentAc.hpp>
#include <Svc/CmdDispatcher/CommandDispatcherComponentAc.hpp>
#include <Svc/TlmChan/TlmChanComponentAc.hpp>
#include <Ref/PingReceiver/PingReceiverComponentAc.hpp>
#include <Svc/FileUplink/FileUplinkComponentAc.hpp>
#include <Ref/SignalGen/SignalGenComponentAc.hpp>
#include <Svc/PassiveTextLogger/PassiveTextLoggerComponentAc.hpp>
#include <Svc/AssertFatalAdapter/AssertFatalAdapterComponentAc.hpp>
#include <Svc/Time/TimeComponentAc.hpp>
#include <Svc/PrmDb/PrmDbComponentAc.hpp>
#include <Drv/BlockDriver/BlockDriverComponentAc.hpp>
#include <Ref/Scheduler/SchedulerComponentAc.hpp>
#include <Svc/FatalHandler/FatalHandlerComponentAc.hpp>
#include <Svc/RateGroupDriver/RateGroupDriverComponentAc.hpp>
#include <Ref/RecvBuffApp/RecvBuffComponentAc.hpp>

#include <unistd.h>

using namespace std;

extern Fw::SimpleObjRegistry simpleReg;

// Component declarations
extern Svc::FatalHandlerImpl fatalHandler("fatalHandler");
extern Svc::ActiveRateGroupImpl rateGroup1Comp("rateGroup1Comp");
extern Ref::PingReceiverImpl pingRcvr("pingRcvr");
extern Svc::TlmChanImpl chanTlm("chanTlm");
extern Ref::SendBuffImpl sendBuffComp("sendBuffComp");
extern Ref::RecvBuffImpl recvBuffComp("recvBuffComp");
extern Svc::CommandDispatcherImpl cmdDisp("cmdDisp");
extern Svc::PrmDbImpl prmDb("prmDb");
extern Svc::ActiveRateGroupImpl rateGroup2Comp("rateGroup2Comp");
extern Svc::CmdSequencerImpl cmdSeq("cmdSeq");
extern Ref::SignalGenImpl SG1("SG1");
extern Ref::SignalGenImpl SG3("SG3");
extern Ref::SignalGenImpl SG2("SG2");
extern Svc::ActiveRateGroupImpl rateGroup3Comp("rateGroup3Comp");
extern Svc::FileUplinkImpl fileUplink("fileUplink");
extern Ref::SignalGenImpl SG5("SG5");
extern Svc::BufferManagerImpl fileUplinkBufferManager("fileUplinkBufferManager");
extern Ref::SignalGenImpl SG4("SG4");
extern Svc::AssertFatalAdapterImpl fatalAdapter("fatalAdapter");
extern Svc::HealthImpl health("health");
extern Svc::GndIfImpl sockGndIf("sockGndIf");
extern Svc::BufferManagerImpl fileDownlinkBufferManager("fileDownlinkBufferManager");
extern Svc::ActiveLoggerImpl eventLogger("eventLogger");
extern Svc::TimeImpl linuxTime("linuxTime");
extern Svc::RateGroupDriverImpl rateGroupDriverComp("rateGroupDriverComp");
extern Drv::BlockDriverImpl blockDrv("blockDrv");
extern Svc::FileDownlinkImpl fileDownlink("fileDownlink");
extern Svc::PassiveTextLoggerImpl textLogger("textLogger");
extern Ref::ManagerImpl manager("manager");
extern Ref::SchedulerImpl scheduler("scheduler");
extern Ref::DriverImpl driver("driver");



extern "C" {
    void dumparch(void);
    void dumpobj(const char* objName);
}


void dumparch(void);

void dumpobj(const char* objName);

void setRef_Ids(void);

void RefInit(void);

void RefStart(void);

void RefRegister(void);

void constructRefArchitecture(void);

void exitTasks(void) ;
