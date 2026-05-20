#include "../include/main.h"

using namespace clang;
using namespace clang::tooling;

static llvm::cl::OptionCategory MyToolCategory("code analyzer");

int main(int argc, const char **argv)
{
    llvm::outs() << "Code Analyzer Started\n"; 

    auto ExpectedParser = CommonOptionsParser::create(argc, argv, MyToolCategory);

    if(!ExpectedParser) {
        llvm::errs() << ExpectedParser.takeError();
        return 1;
    }

    CommonOptionsParser& OptionsParser =
        ExpectedParser.get();

    ClangTool Tool(
        OptionsParser.getCompilations(),
        OptionsParser.getSourcePathList()
    );

    return Tool.run(newFrontendActionFactory<AnalyzerAction>().get());
}