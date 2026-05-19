#include "../include/AnalyzerConsumer.h"
#include "../include/AnalyzerAction.h"

using namespace std;

unique_ptr<clang::ASTConsumer> AnalyzerAction::CreateASTConsumer(
    clang::CompilerInstance &CI,
    llvm::StringRef file
) {
    return make_unique<AnalyzerConsumer>();
}