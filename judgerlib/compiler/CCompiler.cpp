
#include "CCompiler.h"
#include "../process/Process.h"
#include "../util/Utility.h"

namespace IMUST
{
namespace CompileArg
{
    const OJInt32_t limitTime = 20000;
    const OJInt32_t limitMemory = 128*1024*1024;

    const OJString cmd = OJStr("gcc %s -o %s -O2 -Wall -lm --static -std=c99 -DONLINE_JUDGE");
}

CCompiler::CCompiler(void)
{
}


CCompiler::~CCompiler(void)
{
}

bool CCompiler::run(
    const OJString & codeFile,
    const OJString & exeFile,
    const OJString & compileFile)
{
    OJString cmdLine;
    FormatString(cmdLine, CompileArg::cmd.c_str(), codeFile.c_str(), exeFile.c_str());
    
    IMUST::WindowsProcess wp(OJStr(""), compileFile);
    wp.create(cmdLine, CompileArg::limitTime, CompileArg::limitMemory);
    result_ = wp.getExitCodeEx();

    return isAccept();
}

}//namespace IMUST