'''
Created on Monday, 06 April 2020
@author: wbs0013

THIS FILE IS AUTOMATICALLY GENERATED - DO NOT EDIT!!!

XML Source: /home/wbs0013/fprime/Ref/RecvBuffApp/RecvBuffComponentAi.xml
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


COMPONENT = "Ref::RecvBuff"

MNEMONIC = "PARAMETER2_PRM_SET"

OP_CODE  = 0x67

CMD_DESCRIPTION = "A test parameter"

# Set arguments list with default values here.
ARGUMENTS = [
    ("parameter2","A test parameter",I16Type()),
    ]

if __name__ == '__main__':
    testcmd = command.Command(COMPONENT, MNEMONIC, OP_CODE, CMD_DESCRIPTION, ARGUMENTS)
    data = testcmd.serialize()
    type_base.showBytes(data)
