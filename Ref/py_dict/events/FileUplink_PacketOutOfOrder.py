'''
Created on Monday, 06 April 2020
@author: wbs0013

THIS FILE IS AUTOMATICALLY GENERATED - DO NOT EDIT!!!

XML Source: /home/wbs0013/fprime/Svc/FileUplink/FileUplinkComponentAi.xml
'''

# Import the types this way so they do not need prefixing for execution.
from fprime.common.models.serialize.type_exceptions import *
from fprime.common.models.serialize.type_base import *

from fprime.common.models.serialize.bool_type import *
from fprime.common.models.serialize.enum_type import *
from fprime.common.models.serialize.f32_type import *
from fprime.common.models.serialize.f64_type import *

from fprime.common.models.serialize.u8_type import *
from fprime.common.models.serialize.u16_type import *
from fprime.common.models.serialize.u32_type import *
from fprime.common.models.serialize.u64_type import *

from fprime.common.models.serialize.i8_type import *
from fprime.common.models.serialize.i16_type import *
from fprime.common.models.serialize.i32_type import *
from fprime.common.models.serialize.i64_type import *

from fprime.common.models.serialize.string_type import *
from fprime.common.models.serialize.serializable_type import *

from fprime_gds.common.models.common import event
# Each file represents the information for a single event
# These module variables are used to instance the event object within the Gse


COMPONENT = "Svc::FileUplink"

NAME = "FileUplink_PacketOutOfOrder"
ID  = 0x10b
SEVERITY = "WARNING_HI"
FORMAT_STRING = "Received packet %u after packet %u"
EVENT_DESCRIPTION = "The File Uplink component encountered an out-of-order packet during file receipt"

# Set arguments list with default values here.
ARGUMENTS = [
    ("packetIndex","The sequence index of the out-of-order packet",U32Type()),
    ("lastPacketIndex","The sequence index of the last packet received before the out-of-order packet",U32Type()),
    ]

