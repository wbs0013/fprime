'''
Created on Monday, 06 April 2020
@author: wbs0013

THIS FILE IS AUTOMATICALLY GENERATED - DO NOT EDIT!!!

XML Source: /home/wbs0013/fprime/Svc/Health/HealthComponentAi.xml
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

from fprime_gds.common.models.common import command
# Each file represents the information for a single command
# These module variables are used to instance the command object within the Gse


COMPONENT = "Svc::Health"

MNEMONIC = "HLTH_CHNG_PING"

OP_CODE  = 0x16b

CMD_DESCRIPTION = "Change ping value"

# Set arguments list with default values here.
ARGUMENTS = [
    ("entry","The entry to modify",StringType(max_string_len=40)),
    ("warningValue","Ping warning threshold",U32Type()),
    ("fatalValue","Ping fatal threshold",U32Type()),
    ]

if __name__ == '__main__':
    testcmd = command.Command(COMPONENT, MNEMONIC, OP_CODE, CMD_DESCRIPTION, ARGUMENTS)
    data = testcmd.serialize()
    type_base.showBytes(data)
