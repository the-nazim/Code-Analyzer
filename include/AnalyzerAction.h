#ifndef ANALYZERACTION_H
#define ANALYZERACTION_H

#include <clang/Frontend/FrontendAction.h>

class AnalyzerAction
    : public clang::ASTFrontendAction {

public:

    std::unique_ptr<clang::ASTConsumer>
    CreateASTConsumer(
        clang::CompilerInstance &CI,
        llvm::StringRef file
    ) override;
};

#endif