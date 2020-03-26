'''
Created on Wednesday, 25 March 2020
@author: wbs0013

THIS FILE IS AUTOMATICALLY GENERATED - DO NOT EDIT!!!

XML Source: /home/wbs0013/fprime/Ref/PingReceiver/PingReceiverComponentAi.xml
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

from fprime_gds.common.models.common import channel_telemetry
# Each file represents the information for a single event
# These module variables are used to instance the channel object within the Gse


COMPONENT = "Ref::PingReceiver"

NAME = "PR_NumPings"
ID  = 0x29
CHANNEL_DESCRIPTION = "Number of pings received"
TYPE = U32Type()
FORMAT_STRING = None

LOW_RED = None
LOW_ORANGE = None
LOW_YELLOW = None
HIGH_YELLOW = None
HIGH_ORANGE = None
HIGH_RED = None

