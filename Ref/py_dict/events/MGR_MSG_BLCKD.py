'''
Created on Wednesday, 25 March 2020
@author: wbs0013

THIS FILE IS AUTOMATICALLY GENERATED - DO NOT EDIT!!!

XML Source: /home/wbs0013/fprime/Ref/Manager/ManagerComponentAi.xml
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


COMPONENT = "Ref::Manager"

NAME = "MGR_MSG_BLCKD"
ID  = 0x7d2
SEVERITY = "ACTIVITY_LO"
FORMAT_STRING = "Mgr Msg Blckd: %b"
EVENT_DESCRIPTION = ""

# Set arguments list with default values here.
ARGUMENTS = [
    ("messageBlckd","The val1 argument",BoolType()),
    ]

