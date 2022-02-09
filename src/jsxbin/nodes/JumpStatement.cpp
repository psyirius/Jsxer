#include "JumpStatement.h"

void JumpStatement::parse() {
    labelInfo = decoders::d_line_info(reader);
    jmpLocation = decoders::d_sid(reader);
    breakStatement = decoders::d_bool(reader);
}

string JumpStatement::to_string() {
    string result = labelInfo.lbl_statement();

    if (breakStatement)
        result += "break ";
    else
        result += "continue ";

    result += jmpLocation + ';';

    return result;
}