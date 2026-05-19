#include "../include/AnalyzerConsumer.h"
#include "../include/AnalyzerAction.h"
#include <iostream>

using namespace std;

unique_ptr<clang::ASTConsumer> AnalyzerAction::CreateASTConsumer(
    clang::CompilerInstance &CI,
    llvm::StringRef file
) {
    cout<<"CreateASTConsumer CALLED"<<endl;
    return make_unique<AnalyzerConsumer>();
}